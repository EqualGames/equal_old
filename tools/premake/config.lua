VCPKG_ROOT_DIR = "C:/bin/vcpkg"

EQUAL_PLATFORMS = {
  "sdl"
}

newoption {
  trigger     = "render",
  value       = "API",
  default     = "SDL",
  description = "Choose a particular API for rendering",
  allowed     = {
      { "SDL",  "Simple DirectMedia Layer (SDL)" }
  }
}

EQUAL_RUN_PATHS = {
  "~/.local/lib",
  "/usr/local/lib",
  "."
}

EQUAL_LINUX_DEBUG_BUILD_OPTIONS = {
  "-Og",
  "-Wall",
  "-Wextra",
  "-Wundef",
  "-Wpedantic",
  "-Wno-unused-parameter",
  -- "-Wconversion",
  "-Wcast-align",
  "-Wunused",
  -- "-Wshadow",
  "-Wold-style-cast",
  "-Wclass-memaccess",
  "-Wpointer-arith -Wcast-qual -Wno-missing-braces",
}


EQUAL_LINUX_DEBUG_LINK_OPTIONS = {}

EQUAL_LINUX_RELEASE_BUILD_OPTIONS = {
  -- "-O2",
  -- "-ffunction-sections",
  -- "-fdata-sections",
}

EQUAL_LINUX_RELEASE_LINK_OPTIONS = {
  -- "-Wl,-strip-all,--gc-sections"
}

EQUAL_LINUX_DEFINES = {
  "__linux__",
  "EQ_LINUX",
  "_REENTRANT" -- SDL2 flags
}

EQUAL_LINUX_INCLUDES = {
  "$$HOME/.local/include",
  "/usr/include",
  "/usr/local/include"
}

EQUAL_LINUX_LIBRARIES = {
  "$$HOME/.local/lib",
  "/usr/lib",
  "/usr/local/lib",
  "/usr/lib/x86_64-linux-gnu",
}

EQUAL_LINUX_LINKS = {
  "stdc++fs",
  "uuid",
  "boost_serialization",
  "OpenGL",
  "SDL2",
  "SDL2_ttf"
}
