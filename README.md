## Serious Sam Classic ST8 MOD VI
[![Build status](https://github.com/tx00100xt/SE1-TSE-ST8VI/actions/workflows/cibuild.yml/badge.svg)](https://github.com/tx00100xt/SE1-TSE-ST8VI/actions/)
[![License: GPL v2](https://img.shields.io/badge/License-GPL_v2-blue.svg)](https://www.gnu.org/licenses/old-licenses/gpl-2.0.en.html)
[![GitHub release (latest by date)](https://img.shields.io/github/v/release/tx00100xt/SE1-TSE-ST8VI)](https://github.com/tx00100xt/SE1-TSE-ST8VI/releases/tag/v1.7.1)
[![Github downloads](https://img.shields.io/github/downloads/tx00100xt/SE1-TSE-ST8VI/total.svg?logo=github&logoColor=white&style=flat-square&color=E75776)](https://github.com/tx00100xt/SE1-TSE-ST8VI/releases/)

What is ST8 MOD VI?
This is a modification for Serious Sam Classic The Second Encounter. 
This mod required https://github.com/tx00100xt/SeriousSamClassic or https://github.com/tx00100xt/SeriousSamClassic-VK to run.
ST8 MOD VI was created by fans of the game Serious Sam Classic and is distributed for free.
Remark:  UED (from China) is author this mod for windows.

![ST81](https://raw.githubusercontent.com/tx00100xt/SE1-TSE-ST8VI/main/Images/st8vi-1.png)

![ST82](https://raw.githubusercontent.com/tx00100xt/SE1-TSE-ST8VI/main/Images/st8vi-2.png)


Download [SamTSE-ST8VI.tar.xz] archive and unpack to  SeriousSamClassic/SamTSE/ directory.
You can also download the archive using curl or wget:
```
wget https://archive.org/download/sam-tse-st8vi/SamTSE-ST8VI.tar.xz
```
To start the modification, use the game menu - item Modification.

Building Serious Sam Classic ST8 MOD VI (only for SS:TSE)
---------------------------------------------------------

### Linux

Type this in your terminal:

```
git clone https://github.com/tx00100xt/SE1-TSE-ST8VI.git
cd SE1-TSE-ST8VI/Sources
./build-linux64.sh      	    # use build-linux32.sh for 32-bits
```
After that , libraries will be collected in the Mods directory.   
Copy them to SeriousSamClassic/SamTSE/Mods/ST8VI/Bin folder.

### Ubuntu

Instead of building you can install packages from ppa by adding ppa:tx00100xt/serioussam to your system's Software Sources.
```bash
sudo add-apt-repository ppa:tx00100xt/serioussam
sudo add-apt-repository ppa:tx00100xt/serioussam-mods
sudo apt update
```
This PPA can be added to your system manually by copying the lines below and adding them to your system's software sources.
```
deb https://ppa.launchpadcontent.net/tx00100xt/serioussam/ubuntu YOUR_UBUNTU_VERSION_HERE main 
deb-src https://ppa.launchpadcontent.net/tx00100xt/serioussam/ubuntu YOUR_UBUNTU_VERSION_HERE main 
```
After adding ppa, run the commands:
```bash
sudo apt install serioussamclassic serioussam-st8vi
```
or
```bash
sudo apt install serioussamclassic-vk serioussam-st8vi
```

### Gentoo

To build a game for gentoo, use a https://github.com/tx00100xt/serioussam-overlay containing ready-made ebuilds for building the game and add-ons.

### Arch Linux

To build a game under Arch Linux you can use the package from AUR: https://aur.archlinux.org/packages/serioussam

### Raspberry Pi

The build for raspberry pi is similar to the build for Linux, you just need to add an additional build key.

```
git clone https://github.com/tx00100xt/SE1-TSE-ST8VI.git
cd SE1-TSE-ST8VI/Sources
./build-linux64.sh -DRPI4=TRUE	# use build-linux32.sh for 32-bits
```
### FreeBSD

Install bash. 
Type this in your terminal:

```
git clone https://github.com/tx00100xt/SE1-TSE-ST8VI.git
cd SE1-TSE-ST8VI/Sources
bash build-linux64.sh    	    # use build-linux32.sh for 32-bits
```
After that , libraries will be collected in the Mods directory.   
Copy them to SeriousSamClassic/SamTSE/Mods/ST8VI/Bin folder.

### macOS

Install dependes
```
brew install bison flex sdl2 libogg libvorbis zlib-ng cmake git
```
Type this in your terminal:
```
git clone https://github.com/tx00100xt/SE1-TSE-ST8VI.git
cd SE1-TSE-ST8VI/Sources
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j4
make install
```
After that , libraries will be collected in the Mods directory.   
Copy them to SeriousSamClassic/SamTSE/Mods/ST8VI/Bin folder.

Windows
-------
* This project can be compiled starting from Windows 7 and higher.

1. Download and Install [Visual Studio 2015 Community Edition] or higher.
2. Download and Install [Windows 10 SDK 10.0.14393.795] or other.
3. Open the solution in the Sources folder, select Release x64 or Release Win32 and compile it.

Supported Architectures
----------------------
* `x86`
* `aarch64`
* `e2k` (elbrus)

Supported OS
-----------
* `Linux`
* `FreeBSD`
* `Windows`
* `Raspberry PI OS`
* `macOS`

### Build status
|CI|Platform|Compiler|Configurations|Platforms|Status|
|---|---|---|---|---|---|
|GitHub Actions|Windows, Ubuntu, FreeBSD, Alpine, Raspberry PI OS Lite, macOS|MSVC, GCC, Clang|Release|x86, x64, armv7l, aarch64, riscv64, ppc64le, s390x|![GitHub Actions Build Status](https://github.com/tx00100xt/SE1-TSE-ST8VI/actions/workflows/cibuild.yml/badge.svg)

You can download a the automatically build based on the latest commit.  
To do this, go to the [Actions tab], select the top workflows, and then Artifacts.

License
-------

* Serious Engine v1.10 is licensed under the GNU GPL v2 (see LICENSE file).


[SamTSE-ST8VI.tar.xz]: https://drive.google.com/file/d/19wQDweUq8C2J6DeSjMAXqPNAsIjmBK73/view?usp=sharing "Serious Sam Classic ST8 MOD VI"
[Visual Studio 2015 Community Edition]: https://go.microsoft.com/fwlink/?LinkId=615448&clcid=0x409 "Visual Studio 2015 Community Edition"
[Windows 10 SDK 10.0.14393.795]: https://go.microsoft.com/fwlink/p/?LinkId=838916 "Windows 10 SDK 10.0.14393.795"
[Actions tab]: https://github.com/tx00100xt/SE1-TSE-ST8VI/actions "Download Artifacts"
