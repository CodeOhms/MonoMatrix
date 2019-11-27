# MonoMatrix
Programmable driver for monochrome dot matrix displays.</br>
The idea is to program such displays once, instead of each time
you wish to modify its message.

## Features
- [ ] Storage devices (uses littlefs):
  - [ ] eeprom
  - [ ] SD card
- [ ] Data stream
  - [ ] USB serial
  - [ ] wifi

## Data layouts



### Symbols

To have a mixture of symbol sizes, they will be grouped into files.
These files will be in a dedicated directory in the storage device.
For example, `SYMBOLS_WxH.hex` where W is width and H is height.
The width and height of the symbols will be deduced from
the name of the file.

Each will have a header, of one byte,
that specifies the amount of symbols in the file.
Following will be the data for the symbols.
There will be no indicators for when each row, or even each symbol,
will end.
The parsing code will have the dimensions of each symbol,
so it can keep track using simple math.

### Effects



### Matrix data
