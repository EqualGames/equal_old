#!/bin/sh -e

sudo apt remove \
    clang-format \
    libsfml-dev \
    libsdl2-dev \
    libsdl2-image-dev \
    libsdl2-gfx-dev \
    libsdl2-ttf-dev \
    libsdl2-mixer-dev \
    libsdl2-net-dev \
    libboost-serialization-dev \
    libboost-signals-dev \
    uuid-dev \
    doxygen

sudo rm -rf ~/.local/lib/libEqual.a
sudo rm -rf ~/.local/include/equal
sudo rm -rf ~/.local/include/fmt
sudo rm -rf ~/.local/include/glm
sudo rm -rf ~/.local/include/pugixml
sudo rm -rf ~/.local/include/stb
sudo rm -rf ~/.local/include/gtest
