#!/bin/sh -e

cd tools/doxygen

cmake -G"Unix Makefiles"

make clean

make doxygen

