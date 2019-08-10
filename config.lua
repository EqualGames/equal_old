WKS_DIR = "%{wks.location}"
VCPKG_ROOT_DIR = "C:/bin/vcpkg"
TARGET_DIR = "%{wks.location}/build"
DEBUG_DIR = "%{wks.location}/build"
OBJ_DIR = "%{wks.location}/build/.obj/%{cfg.buildcfg}-%{cfg.architecture}/%{prj.name}"

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
  "/usr/local/lib",
  "."
}

EQUAL_LINUX_DEFINES = {
  "__linux__",
  "EQ_LINUX",
  "_REENTRANT" -- SDL2 flags
}

EQUAL_LINUX_BUILD_OPTIONS = {
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

EQUAL_LINUX_BUILD_OPTIONS_OPTIMIZE = {
  -- "-O2",
  -- "-ffunction-sections",
  -- "-fdata-sections",
}

EQUAL_LINUX_LINK_OPTIONS = {}

EQUAL_LINUX_LINK_OPTIONS_OPTIMIZE = {
  -- "-Wl,-strip-all,--gc-sections"
}

EQUAL_LINUX_INCLUDES = {
  "/usr/include",
  "/usr/local/include"
}

EQUAL_LINUX_LIBRARIES = {
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
