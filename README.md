# eXamine 1.0 beta

Data conversion/examination command line tool.

## Installation

eXamine is written in pure C, so you cam compile it wherever you want. Just do:

    git clone https://github.com/merces/examine.git
    make
    make install
    examine

A symbolic link "x" is also created for your convenience. :neckbeard:

Available input prefixes (for numbers only): 0b (binary), 0x (hexadecimal) and 0 (octal).

## Usage examples

Analyse the hexadecimal number 0xB0B0CA:

    echo 0xb0b0ca | x
    Hex string: 3078623062306361
    Byte array: \x30\x78\x62\x30\x62\x30\x63\x61
    URL encoding: %30%78%62%30%62%30%63%61
    ROT13: 0ko0o0pn
    Signed int: 11579594
    Unsigned int: 11579594
    Float: 1.62265e-38
    Hexadecimal: 0xb0b0ca
    Octal: 054130312
    Binary: 0b101100001011000011001010
    RGB: (176, 176, 202)
    IPv4: 0.176.176.202
    Timestamp: Fri, 15 May 1970 00:33:14 UTC/GMT-0

eXamine does not really know whether the input is intended to be either a string or a number. It just processes it as both and output some handy conversions. The next example shows eXamine in interactive mode:

    x
    eXamine> eXamine rocks! \o/
    Hex string: 6558616d696e6520726f636b7321205c6f2f
    Byte array: \x65\x58\x61\x6d\x69\x6e\x65\x20\x72\x6f\x63\x6b\x73\x21\x20\x5c\x6f\x2f
    URL encoding: %65%58%61%6D%69%6E%65%20%72%6F%63%6B%73%21%20%5C%6F%2F
    ROT13: rKnzvar ebpxf! \b/
    Signed int: 0
    Unsigned int: 0
    Float: 0
    Hexadecimal: 00
    Octal: 0
    Binary: 0b
    ASCII char: NUL
    RGB: (0, 0, 0)
    IPv4: 0.0.0.0
    Timestamp: Thu, 01 Jan 1970 00:00:00 UTC/GMT-0

    eXamine> 0x3fc00000
    Hex string: 30783366633030303030
    Byte array: \x30\x78\x33\x66\x63\x30\x30\x30\x30\x30
    URL encoding: %30%78%33%66%63%30%30%30%30%30
    ROT13: 0k3sp00000
    Signed int: 1069547520
    Unsigned int: 1069547520
    Float: 1.5
    Hexadecimal: 0x3fc00000
    Octal: 07760000000
    Binary: 0b111111110000000000000000000000
    IPv4: 63.192.0.0
    Timestamp: Sun, 23 Nov 2003 00:32:00 UTC/GMT-0

Hit Ctrl+C to quit.