#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

#define MAX_CMD_LINE 1000
#define TIMESTR_SIZ 36

// From https://stackoverflow.com/questions/16164620/how-to-convert-an-ieee-754-single-precision-binary-floating-point-to-decimal/29969785#29969785
float int2float(int uintS) {
	unsigned int sign     = (uintS & 0x80000000); //01111111 10000000 00000000 00000000
	unsigned int exponent = (uintS & 0x7F800000); //01111111 10000000 00000000 00000000
	unsigned int mantessa = (uintS & 0x007FFFFF); //00000000 01111111 11111111 11111111
	float normalizedExponent = (float) ((signed char) ((exponent>>23) - 127));
	float normalizedMantessa = (float) 1 + (float) mantessa / pow((float)2,(float)23);
	float theVar = normalizedMantessa * pow((float)2,(float)normalizedExponent);

	if (sign != 0) theVar = theVar * (float) (-1);
	if (fabs(theVar) < pow((float) 10, (float) -38)) theVar = 0;
	return theVar;
}

// From https://stackoverflow.com/questions/1024389/print-an-int-in-binary-representation-using-c
char *int2bin(int i) {
    size_t bits = sizeof(int) * CHAR_BIT;

    char * str = malloc(bits + 1);
    if(!str) return NULL;
    str[bits] = '\0';

    // type punning because signed shift is implementation-defined
    unsigned u = *(unsigned *)&i;
    for(; bits--; u >>= 1)
    	str[bits] = u & 1 ? '1' : '0';

    // remove trailing zeroes
    while (*str == '0')
    	str++;

    return str;
}

// From https://stackoverflow.com/questions/13520067/about-rot13-implementation/14636260#14636260
void rot13(char *s) {
    if (!s)
        return;

    int i;
    for (i = 0; s[i]; i++) {
        if (s[i] >= 'a' && s[i] <= 'm') { s[i] += 13; continue; }
        if (s[i] >= 'A' && s[i] <= 'M') { s[i] += 13; continue; }
        if (s[i] >= 'n' && s[i] <= 'z') { s[i] -= 13; continue; }
        if (s[i] >= 'N' && s[i] <= 'Z') { s[i] -= 13; continue; }
    }
}

void examine(const char *s) {
	long number;
	int i;

	const char *nongraph[] = {
   	"NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL",
   	"BS", "\\t (tab)", "\\n (newline or line feed)", "VT (vertical tab)", "FF", "\\r (carriage return)", "SO", "SI",
   	"DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB",
	"CAN", "EM", "SUB", "ESC", "FS", "GS", "RS", "US"
	};

	// Handle input as string
	printf("Hex string: ");
	for (i=0; i < strlen(s); i++)
		printf("%2x", s[i]);
	putchar('\n');

	printf("Byte array: ");
	for (i=0; i < strlen(s); i++)
		printf("\\x%2x", s[i]);
	putchar('\n');

	printf("URL encoding: ");
	for (i=0; i < strlen(s); i++)
		printf("%%%2X", s[i]);
	putchar('\n');

	char *t = strndup(s, strlen(s));
	rot13(t);
	printf("ROT13: %s\n", t);
	free(t);

	// Handle input as number

	// Binary prefix 0b is not automatically handled by strtoul() so we handle that
	if (*s == '0' && *(s+1) == 'b')
		number = (long) strtol(s+2, NULL, 2);
	else
		number = (long) strtol(s, NULL, 0);

	printf("Signed int: %jd\n", number);
	printf("Unsigned int: %ju\n", number);
	printf("Float: %g\n", int2float(number));
	printf("Hexadecimal: %#02x\n", (unsigned) number);
	printf("Octal: %#o\n", (unsigned) number);
	char *binary = int2bin((int) number);
	printf("Binary: 0b%s\n", binary);

	// Customized ASCII representation for non graphical characters
	if (number >= 0 && number < 128)
	{
		if (number == 127)
			printf("ASCII char: DEL");
		else if (number < 32)
			printf("ASCII char: %s\n", nongraph[number]);
		else
			printf("ASCII char: %c\n", (char) number);
	}

	if (number >= 0 && number <= 0xffffff)
		printf("RGB: (%d, %d, %d)\n", (int)(number >> 16) & 0xff, (int)(number >> 8) & 0xff, (int) number & 0xff);

	printf("IPv4: %d.%d.%d.%d\n",
		(int)(number>>24) & 0xff,
		(int)(number>>16) & 0xff,
		(int)(number>>8) & 0xff,
		(int)number & 0xff);

	char timestr[TIMESTR_SIZ], u[TIMESTR_SIZ];
	strftime(timestr, TIMESTR_SIZ, "%a, %d %b %Y %H:%M:%S UTC/GMT-0", gmtime((time_t *) &number));
	snprintf(u, TIMESTR_SIZ, "%s", timestr);
	printf("Timestamp: %s\n", u);
}

int main(int argc, char *argv[]) {
	unsigned i=0;
	char s[MAX_CMD_LINE], c;

	// Loop until Ctrl+C is pressed
	while (1) {
		if (i==0 && isatty(fileno(stdin)))
			printf("eXamine> ");

		c = getchar();

		if (c == '\n') {
			s[i] = '\0';
			if (i > 0) {
				examine(s);
				putchar('\n');
			}
			i=0;
			continue;
		} else if (c == EOF) {
			break;
		} else {
			s[i] = c;
		}

		if (i >= MAX_CMD_LINE) {
			fprintf(stderr, "Error: input is bigger than %d bytes. Increase MAX_CMD_LINE and try again.\n", MAX_CMD_LINE);
			return 1;
		}

		i++;
	}

	return 0;
}
