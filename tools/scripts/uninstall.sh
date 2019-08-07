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

sudo rm -rf /usr/local/lib/libEqual.a
sudo rm -rf /usr/local/include/equal
sudo rm -rf /usr/local/include/fmt
sudo rm -rf /usr/local/include/glm
sudo rm -rf /usr/local/include/pugixml
sudo rm -rf /usr/local/include/stb
sudo rm -rf /usr/local/include/gtest
