# Capcom Logo on SNES

## Description
This is a demo showing the Capcom logo on the Super Nintendo and Super Famicom.

It is built and tested with PVSnesLib, develop branch and MSYS2:
https://github.com/alekmaul/pvsneslib

## Preview
![preview](preview.png)

## Operating System
Windows 10

## How to build
### Visual Studio Code
- Install Visual Studio Code
- Open the root directory with Visual Studio Code
- Build: Shit+Ctrl+B
- Open logo.sfc with a SNES Emulator

### Programmer's Notepad
- Install Programmer's Notepad: https://github.com/alekmaul/pvsneslib/wiki/PVSneslib-and-Programmer-Notepad
- Open sneslogo.pnproj with Programmer's Notepad
- Click on Tools>make in the top menu
- Open logo.sfc with a SNES Emulator

## PVSnesLib
### Installation
https://gist.github.com/kobenairb/00c2cf30822d8d2d5994850f68a5cfbdss

Then execute in MSYS2 terminal:
pacman -Sy mingw-w64-ucrt-x86_64-pcre2

### Documentation
https://alekmaul.github.io/pvsneslib/

## WLA Documentation
https://wla-dx.readthedocs.io/en/latest/

## SNES Assembly Documentation
https://ersanio.gitbook.io/assembly-for-the-snes/
https://problemkaputt.de/fullsnes.htm

## SNES SDK Documentation
https://www.retroreversing.com/super-famicom-snes-sdk/

## 65816 Reference
https://wiki.superfamicom.org/65816-reference

## ASM Hacking for Dummies
https://wiki.superfamicom.org/asm-hacking-for-dummies

## Debug with ASM

In snes_rules, add @cp $.asp $.svasm here:

%.asm: %.ps
    @echo Assembling ... $(notdir $<)
    $(PY) $< >$*.asp 
    @echo Moving constants ... $(notdir $<)
    $(CTF) $*.c $*.asp $@
    @cp $.asp $.svasm
    @rm $*.asp

## Palettes

u16 pal[sizepal];
pal[0] = RGB8(100,10,10);
pal[1] = RGB8(10,10,100);
...
pal[15] = RGB8(10,255,10);

dmaCopyCGram((u8 *) pal,numpal * 16, sizepal*2); 

## ImageMagick

magick spritesheet.png +repage -crop 16x16 tiles\tile%04d.png

## Draw pixels

https://github.com/alekmaul/pvsneslib/commit/0cb2cca4a6f336d870c455f138389bfa1c3f82f5

https://www.mesen.ca/docs/apireference/drawing.html

https://github.com/zeta0134/mesen-piano-roll/blob/master/piano_roll.lua

## Tiled

### Tool URL

https://portabledev.com/pvsneslib/tilesetextractor/

### Get the tileset from an image

1) open your graphic file with the converter and save tiles + tmx file (converter is here: https://portabledev.com/pvsneslib/tilesetextractor/)
2) put tmx + png tile files in a directory and open tmx with tiled
3) change tile properties (attribute/palette/priority) if you want
4) save tmx file as a json file with file/export in Tiled
5) take a look at sample to open your map file and display it on screen

## gfx2snes

### Options

Options are:

--- Graphics options ---\
-gb               add blank tile management (for multiple bgs)\
-gp               Output in packed pixel format\
-glz              Output in lzss compressed pixel format\
-gs(8|16|32|64)   Size of image blocks in pixels [8]\
\
--- Map options ---\
-m!               Exclude map from output\
-m                Convert the whole picture\
-mp               Convert the whole picture with high priority\
-m7               Convert the whole picture for mode 7 format\
-m5               Convert the whole picture for mode 5 & 6 512 width hires\
-mc               Generate collision map only\
-ms#              Generate collision map only with sprites table\
                   where # is the 1st tile corresponding to a sprite (0 to 255)\
-mn#              Generate the whole picture with an offset for tile number\
                   where # is the offset in decimal (0 to 2047)\
-mR!              No tile reduction (not advised)\
-m32p             Generate tile map organized in pages of 32x32 (good for scrolling)\
-me               Convert the map for PVSneslib map engine\
-mt(filename)     Tileset picture filename (PNG,BMP,PCX) for PVSneslib map engine matching\
\
--- Palette options ---\
-p!               Exclude palette from output.\
-pc(4|16|128|256) The number of colors to use [256]\
-po#              The number of colors to output (0 to 256) to the filename.pal\
-pe#              The palette entry to add to map tiles (0 to 16)\
-pr               Rearrange palette, and preserve palette numbers in the tilemap\
-pR               Palette rounding\
\
--- File options ---\
-f[bmp|pcx|tga|png]   convert a bmp or pcx or tga or png file [bmp]\
\
--- Misc options ---\
-n                no border\
-q                quiet mode\
-v                Display gfx2snes version information\

### Errors

gfx2snes: error 'Detected more colors in one 8x8 tile than is allowed'

## Tiles

vhopppcccccccccc
v/h        = Vertical/Horizontal flip this tile.
o          = Tile priority.
ppp        = Tile palette. The number of entries in the palette depends on the Mode and the BG.
cccccccccc = Tile number.

## Sprites

### The record format for the low table is 4 bytes

Sprite Table 1 (4-bytes per sprite)         
byte OBJ*4+0:    xxxxxxxx   x: X coordinate
byte OBJ*4+1:    yyyyyyyy   y: Y coordinate
byte OBJ*4+2:    cccccccc   c: Starting tile #
byte OBJ*4+3:    vhoopppc   v: vertical flip h: horizontal flip  o: priority bits
                            p: palette # c:sprite size (e.g. 8x8 or 16x16 pixel)

### The record format for the high table is 2 bits

Sprite Table 2 (2 bits per sprite)
bits 0,2,4,6 - Enable or disable the X coordinate's 9th bit.
bits 1,3,5,7 - Toggle Sprite size: 0 - small size   1 - large size

### Description

Xxxxxxxxx = X position of the sprite. Basically, consider this signed but see below.
yyyyyyyy  = Y position of the sprite.^
cccccccc  = First tile of the sprite.^^
N         = Name table of the sprite. See below for the calculation of the VRAM address.
ppp       = Palette of the sprite. The first palette index is 128+ppp*16.
oo        = Sprite priority. See below for details.
h/v       = Horizontal/Vertical flip flags.^^^
s         = Sprite size flag. See below for details.

^Values 0-239 are on-screen. -63 through -1 are "off the top", so the bottom part of the sprite comes in at the top of the screen. Note that this implies a really big sprite can go off the bottom and come back in the top.

^^See below for the calculation of the VRAM address. Note that this could also be considered as 'rrrrcccc' specifying the row and column of the tile in the 16x16 character table.

^^^Note this flips the whole sprite, not just the individual tiles. However, the rectangular sprites are flipped vertically as if they were two square sprites (i.e. rows "01234567" flip to "32107654", not "76543210").

The sprite size is controlled by bits 5-7 of $2101, and the Size bit of OAM. $2101 determines the two possible sizes for all sprites. If the OAM Size flag is 0, the sprite uses the smaller size, otherwise it uses the larger size.

## HDMA

https://wiki.superfamicom.org/grog's-guide-to-dma-and-hdma-on-the-snes

The HDMA Table has any number of "cells". Each cell tells the HDMA logic what value to send to the Destination register during the next N HBlanks, where N is any value from 1 to 128. If bit 8 of the N value is set, then the value is written EVERY HBlank; if bit 8 is zero, then the value is only written ONCE, the first time, and N-1 lines are skipped. The value $80 is a special case; it writes EVERY HBlank for 128 lines.

## Memory

https://en.wikibooks.org/wiki/Super_NES_Programming/SNES_memory_map

## Print options

https://user-web.icecube.wisc.edu/~dglo/c_class/printf.html

## Musics

### Get SFX from SNES Roms

SNES Sound Ripper

### SPC to IT Conversion

1) Convert SPC file to IT file

./spc2it music.spc -r 128

Download link: https://github.com/uyjulian/spc2it/releases/tag/v0.4.0

2) Open music.it with OpenMPT

https://openmpt.org/

3) Select general section:

Click on IT (Impulse Tracker) button
Select 8 channels
Click on Ok
Remove channels 9 to 16 (stereo)
Click on Ok

Note: Only 8 channels are available on SNES.

4) Select Patterns section:

Remove the duplicated patterns for stereo

Example: If you have 100 patterns, keep the 50 first patterns and remove the other ones.

5) Select Instruments section:

Ctrl+D or Select Duplicate Instrument

Note: This will create all the needed instruments

6) Select Edit> Cleanup...

Select Rearrange in Samples section in the window

Click on Ok

=> That should remove the duplicated patterns in Sequences
=> That should remove the unused Samples

7) Select Automatic Sample Trimmer (optional)

Note: this will reduce the size of your IT file

## Inputs

if (!(last_pad0 & KEY_X) && (pad0 & KEY_X)) to tell if X has just been pressed

## ASM

- Example of a function returning a number:
```
.SECTION ".text_0x0" SUPERFREE
myfunction:
lda.w #53
sta.b tcc__r0
rtl
.ENDS
```

## Python issues

Execute in Powershell:
Remove-Item $env:USERPROFILE\AppData\Local\Microsoft\WindowsApps\python*.exe

Disable Python in App execution aliases
