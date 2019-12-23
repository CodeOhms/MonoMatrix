# MonoMatrix
Programmable driver for monochrome dot matrix displays.</br>
The idea is to program such displays once, instead of each time
you wish to modify its message.

## Features
- [ ] Storage devices (uses littlefs):
  - [ ] eeprom
  - [ ] SD card
- [ ] Data streams:
  - [ ] USB serial
  - [ ] wifi

## Data structures
## Settings File
1. Number of effects that can apply to display data.
1. Raw display data buffer.
1. Frame rate.
1. Default speed of effects - measured in the amount of frames played per second.
1. Frame queue length - must be > 2.

#### Might not implement. Too many layout variants to deal with, so it likely will greatly impact performance
### ~~Symbols Files~~
~~To have a mixture of symbol sizes, they will be grouped into files.
These files will be in a dedicated directory in the storage device.
For example, `SYMBOLS_WxH.hex` where W is width and H is height.
The width and height of the symbols will be deduced from
the name of the file.~~

~~Each will have a header, of one byte,
that specifies the amount of symbols in the file.
Following will be the data for the symbols.
There will be no indicators for when each row, or even each symbol, will end.
The parsing code will have the dimensions of each symbol,
so it can keep track using simple math.~~

### Effects
There are predefined effects. They control how data is displayed, and are mandatory.<br>
Available effects are subject to change with each new version. However,
some effects are guaranteed to always be supported:<br>
- (0x0) Plain Data
  - Simply displays what is stored. This effect expects a series of frames,
    with a specified delay.
- (0x1) Scroll left
  - Scrolls through text to the left, as seen with most LED displays.

### Matrix Data Files
Display data will be grouped into seperate files. The data includes effects and display rates.<br>
Each set of data will begin with the effects, and optionally followed by
the speed of the effects - measured in the amount of frames played per second.
Next will be either symbol identifiers or plain data.<br>
Marking the end of the data set will be the end of the file.<br>

Effects and display rates data will be stored in RAM for the life of the program.
Meanwhile, display data will be buffered from storage as needed.