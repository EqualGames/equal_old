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

sudo ln -sfr ./include/equal ~/.local/include
sudo ln -sfr ./external/fmt/include/fmt ~/.local/include
sudo ln -sfr ./external/glm/glm ~/.local/include
sudo ln -sfr ./external/pugixml/src ~/.local/include/pugixml
sudo ln -sfr ./external/stb ~/.local/include
sudo ln -sfr ./external/googletest/googletest/include/gtest ~/.local/include
