# [libcheck][] C usage example with a minimalist build ([make][])

This is a usage example for [check][libcheck] using only [gnu make][make].

It losely follows the libcheck tutorial here:
<https://libcheck.github.io/check/doc/check_html/check_3.html>

## Building

You will need:

- [GNU Make][make] (probably any other Make will do, but untested)
- A compiler like [gcc][] or [clang][]
- The [check][libcheck] library
- The [pkg-config][] tool

Installation procedures will vary per platform.
On Ubuntu, this looks like:

    sudo apt-get update
    sudo apt-get -y install make build-essential check pkg-config

Alternately, you can invoke `nix-shell` from the [nix][] package manager;
it will read [shell.nix](shell.nix) and set up these dependencies for you.

Once dependencies are set up, build code and run tests with:

    make check

To reset the build environment:

    make clean

## Project Structure

Build definition is in [Makefile](Makefile).

Pretend-library code and headers are in [libmoney](libmoney).

[program.c](program.c) is the program using `libmoney`.

[test.c](test.c) implements test routines against `libmoney`.


[nix]: <https://nixos.org/nix/>
[clang]: <https://clang.llvm.org/>
[gcc]: <https://gcc.gnu.org/>
[make]: <https://www.gnu.org/software/make/>
[libcheck]: <https://github.com/libcheck/check>
[pkg-config]: <https://www.freedesktop.org/wiki/Software/pkg-config/>
