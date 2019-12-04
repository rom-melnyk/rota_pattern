# Index

1. [Architecture](#architecture)
1. [TGA format](#tga-format)
1. [The math behind RGB color](#the-math-behind-rgb-color)
1. [Generating the rotation pattern](#generating-the-rotation-pattern)

# Architecture

## CLI

The program is a CLI utility which should be run with following arguments:

- `-dout=NUMBER` means outer diameter of the pattern;
- `-din=NUMBER` means inner diameter of the rotary wheel; it should be less than outer diameter;
- `-pen=NUMBER` means the position of the pen on inner wheel (`0` means the center, `100` means the periphery).

## Targa file

The program produces the `.tga` (Targa) file with distinguishable name (containing CLI arguments). The TGA file can be opened by most image viewers.

## C++ classes

There are classes for:

- Parsing CLI arguments and holding appropriate data in convenient form.
- Writing the binary file (TGA destination).
- Holding single pixel information (color).
- Holding whole image information (`vector<Pixel>`).
- Drawing (placing a `Pixel` at given position). It implies the math that generates the pattern.

## C++ modules

The program should be split into multiple small files (one file for one piece of logic; one file per class).

## Compilation

The source code resides in `src/`. The entry point is `src/rota_pattern.cpp`. That file should be fed to compiler. Compiler should yield results into `build/`. Mind that output files are `.gitignore`-d.

[To the top](#index)

# TGA format

The format was choosen becausee it's pretty easy to realize it with the code:

- [Paul Bourke](http://www.paulbourke.net/dataformats/tga/),
- [Wiki](https://en.wikipedia.org/wiki/Truevision_TGA).

tldr; the TGA file has an 18 bytes _header_ followed by pixel data (image _payload)._

We use uncompressed 24bit TrueColor RGb image. That's image type `2` and implies 3 bytes per pixel for image payload in format `BGR` (because of TGA uses little-endian notation where lower bytes go first). Consider image resolution to be 1024x1024 pixils.

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

The payload is the sequence of 3 byte chunks. Each chunk represents single pixel (Red, Green and Blue values of the color). Little-endian notation should be respected we first put Blue then Green then Red bytes.

```
class Pixel {
  public:
    char r;
    char g;
    char b;
}

void put_pixel(ofstream file, Pixel pix) {
  // Mind reverse order!
  file.put(pix.b);
  file.put(pix.g);
  file.put(pix.r);
}
```

In our example we expect `1024 * 1024 = 1048576` pixels to be put (see the `width` and `height` fields of the header). The whole size of the image is ~3Mb (`3 * 1024 * 1024 + 18`).

[To the top](#index)

# The math behind RGB color

TBD

[To the top](#index)

# Generating the rotation pattern

TBD

[To the top](#index)
