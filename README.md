examine 1.0
===========

Data conversion/examination command line tool

###1. Build
    $ make

###3. Install
    # make install

###3. Usage
    $ examine
    $ x

Available input prefixes for numbers are: 0b (binary), 0x (hexadecimal) and 0 (octal).

A symbolic link called "x" is also created for convenience.

###4. Examples

Analyse the hexadecimal number 0xB0B0CA:

    $ $ echo 0xb0b0ca | x
	[*] Handling as string:
	Hex string: 3078623062306361
	Byte array: \x30\x78\x62\x30\x62\x30\x63\x61
	URL encoding: %30%78%62%30%62%30%63%61
	ROT13: 0ko0o0pn
	[*] Handling as number:
	Signed int: 11579594
	Unsigned int: 11579594
	Float: 1.15796e+07
	Hexadecimal: 0xb0b0ca
	Octal: 054130312
	Binary: 0b101100001011000011001010
	RGB: (176, 176, 202)
	IPv4: 0.176.176.202
	Date/time stamp: Fri, 15 May 1970 00:33:14 UTC/GMT-0

examine does not really know if input is intended to be string or number. It just process it as it was both and output some handy conversions. The next example shows how to use examine on interactive mode:

    $ x
    examine rocks!
	[*] Handling as string:
	Hex string: 6578616d696e6520726f636b7321
	Byte array: \x65\x78\x61\x6d\x69\x6e\x65\x20\x72\x6f\x63\x6b\x73\x21
	URL encoding: %65%78%61%6D%69%6E%65%20%72%6F%63%6B%73%21
	ROT13: rknzvar ebpxf!
	[*] Handling as number:
	Signed int: 0
	Unsigned int: 0
	Float: 0
	Hexadecimal: 00
	Octal: 0
	Binary: 0b
	ASCII char: NUL
	RGB: (0, 0, 0)
	IPv4: 0.0.0.0
	Date/time stamp: Thu, 01 Jan 1970 00:00:00 UTC/GMT-0

	as long as you know what you are doing!
	[*] Handling as string:
	Hex string: 6173206c6f6e6720617320796f75206b6e6f77207768617420796f752061726520646f696e6721
	Byte array: \x61\x73\x20\x6c\x6f\x6e\x67\x20\x61\x73\x20\x79\x6f\x75\x20\x6b\x6e\x6f\x77\x20\x77\x68\x61\x74\x20\x79\x6f\x75\x20\x61\x72\x65\x20\x64\x6f\x69\x6e\x67\x21
	URL encoding: %61%73%20%6C%6F%6E%67%20%61%73%20%79%6F%75%20%6B%6E%6F%77%20%77%68%61%74%20%79%6F%75%20%61%72%65%20%64%6F%69%6E%67%21
	ROT13: nf ybat nf lbh xabj jung lbh ner qbvat!
	[*] Handling as number:
	Signed int: 0
	Unsigned int: 0
	Float: 0
	Hexadecimal: 00
	Octal: 0
	Binary: 0b
	ASCII char: NUL
	RGB: (0, 0, 0)
	IPv4: 0.0.0.0
	Date/time stamp: Thu, 01 Jan 1970 00:00:00 UTC/GMT-0

Hit Ctrl+C to quit.

###5. Uninstall
    # make uninstall