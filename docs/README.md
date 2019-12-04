# Index

1. [Architecture](#architecture)
1. [TGA format](#tga-format)
1. [The math behind RGB color](#the-math-behind-rgb-color)
1. [Generating the rotation pattern](#generating-the-rotation-pattern)

# Architecture

TBD

[To the top](#index)

# TGA format

The format was choosen becausee it's pretty easy to realize it with the code:

- [Paul Bourke](http://www.paulbourke.net/dataformats/tga/),
- [Wiki](https://en.wikipedia.org/wiki/Truevision_TGA).

tldr; it has an 18 bytes _header_ followed by pixel data (image _payload)._

We use uncompressed 24bit TrueColor RGb image. That's image type `2` and implies 3 bytes per pixel for image payload in format `BGR` (because of TGA uses little-endian notation where lower bytes go first).

## Header

```
#           value (hex)            Comment
------------------------------------------------------------------
00          00                     ID
01          00                     Color map type (none in our case)
02          02                     24bit uncompressed RGB
03-07       00 00 00 00 00         Color map related data (we don't use color map)
08-09       00 00                  X origin
0A-0B       00 00                  Y origin
0C-0D       00 04                  Width; 1024px (0d1024 = 0x0400; little-endian notation)
0E-0F       00 04                  Height; 1024px (0d1024 = 0x0400; little-endian notation)
10          18                     Means 24bit RGB (think 3 bytes or 1 byte per channel)
11          00                     Image descriptor
```

## Payload

The payload is the sequence of 3 byte chunks. Each of them represents single pixel (Red, Green and Blue values of the color). Little-endian notation should be respected so

```
class Pixel {
  public:
    char r;
    char g;
    char b;
}

void put_pixel(ofstream file, Pixel pix) {
  //  Mind reverse order!
  file.put(pix.b);
  file.put(pix.g);
  file.put(pix.r);
}
```

In our example we expect `1024 * 1024 = 1048576` pixels to be put.

[To the top](#index)

# The math behind RGB color

TBD

[To the top](#index)

# Generating the rotation pattern

TBD

[To the top](#index)
