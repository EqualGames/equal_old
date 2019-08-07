#!/bin/sh -e

sudo apt install \
    clang-format \
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

sudo ln -sfr ./include/equal /usr/local/include
sudo ln -sfr ./external/fmt/include/fmt /usr/local/include
sudo ln -sfr ./external/glm/glm /usr/local/include
sudo ln -sfr ./external/pugixml/src /usr/local/include/pugixml
sudo ln -sfr ./external/stb /usr/local/include
sudo ln -sfr ./external/googletest/googletest/include/gtest /usr/local/include
