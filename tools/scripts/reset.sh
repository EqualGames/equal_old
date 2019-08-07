#!/bin/sh -e

rm -rf build Makefile *.make
rm -rf **/build **/Makefile **/*.make
rm -rf **/**/build **/**/Makefile **/**/*.make
