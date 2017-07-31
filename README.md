# AsciiImg

A simple Image to Ascii conversion library, written in OpenCV.

## Example output

```
0000000000000000000000000@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@00000
00000000000000000000000000@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@00000
00000000000000000000000000@@@@@@O*O*oO0@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@000000
0000000000000000000000000000oo.*ooo....oo*.*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@000000
00000000000000000000000000ooo.ooooooooooo**o*@@@@@@@@@@@@@@@@@@@@@@@@@@@00000000
000000000000000OO0000000Oo. o**************ooo*@@0***o**OOOOO000OOOOOO**oooooooo
000000000000000O*OOOO00O*ooo*****************.o00000000000000000000000000OOOOOOO
00000000000000O**OOOO0O0Oooo*****************o.0000000000000000000000OOOOOOOOOOO
00000000000000OOOOOOO0O0O0..***o...ooooo.ooo*.00000000000000000000O0OOOOOOOOOOOO
000000000000OO*OO0000@000Oo *o.oo...    .oooo.@@@00000000000000OOOOOOOOOOOOOOOOO
0000000000000OO*O00000000OO*o**oooo ** oooo*o*00000000*0o*O0OOOOOOOOOOOOOOOOOOOO
0000000000000OO.OOOOOOOOOOO0o*oo...o**oo.ooo*00OOO0OOO*OOOOOOOOOOOOOOOOOOOOOOOOO
0OO00000000OOOOOOOOOOOOOOOOOooo.oooo..ooo..ooO0OOOOO0OOOOOOOOOOOOOOOOOOOOOOOOOOO
000O0OO000OOO**OOOOOOOOOOOOOOo..ooooooooo..o00000*OOOoOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOO0OOOOO**OOOOOO000000OOO...oo........000000OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOO0OOOOO*.OOOOO000000OOo.o...ooooo... .**000OOOOOOOOOOOOOO*OOOOOOOOOOOOOOOO
OOOOOOOOOOOOOO*OOOOOOOOOO0*oo..oo.     ..o..o. o.**OOOOOOOOOOOOOOOOOOOOOOOOOOOOO
OOOOOOOOOOOO***OOOOO*ooooooo...oooooooo.o.oooo.ooooo******OOOOOOOOOOOOOOOOOOOOO*
OOOOOOOOOOOO*o*O***o**ooooo.  ...oooo*oooo*....oooooooooooo*OOOOOO*OOOOOOOOOOO**
OOOOOOOOOOOO*.*ooooooooooooo...  . .oo...  ...oooo*oooooooooo*OOOOOOOOOOOOOOO***
OOOOOOOOOOOO**o.*ooooooooo.o...o......  .......o*ooooooooo.oooo*OOOOO*OOOOOO****
```

## Build Requirements

* CMake >= 2.8
* OpenCV >= 2.x

### OS X

```
xcode-select --install
brew tap homebrew/science
brew install cmake
brew install homebrew/science/opencv3
```

### Ubuntu

```
sudo apt-get update
sudo apt-get install build-essential cmake opencv3
```

## Build

```
./build.sh
```

## Install

```
cd build
sudo make install
```
