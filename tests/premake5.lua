require "../tools/premake/helpers"
require "../config"

workspace "Tests"
  architecture "x64"
  configurations { "Debug", "Release" }

  include "../external/googletest"

  project "Test"
    kind "ConsoleApp"
    language "C++"
    cppdialect "gnu++17"
    staticruntime "on"
    targetdir (TARGET_DIR)
    debugdir (DEBUG_DIR)
    objdir (OBJ_DIR)
    flags "NoPCH"

    files (GetHeaders("."))
    files (GetSources("."))
    includedirs "."
    links "Equal"

    dependson "gtest"
    links "gtest"
    links "pthread"

    runpathdirs (EQUAL_RUN_PATHS)

    filter "configurations:Debug"
      symbols "on"
      runtime "Debug"
      defines "_DEBUG"

    filter "configurations:Release"
      optimize "on"
      runtime "Release"
      defines "NDEBUG"

    filter "options:render=SDL"
      defines "EQ_SDL"

    ---------- Linux ----------

    filter "system:linux"
      toolset "gcc"
      defines (EQUAL_LINUX_DEFINES)
      buildoptions (EQUAL_LINUX_BUILD_OPTIONS)
      linkoptions (EQUAL_LINUX_LINK_OPTIONS)
      includedirs (EQUAL_LINUX_INCLUDES)
      libdirs (EQUAL_LINUX_LIBRARIES)
      links (EQUAL_LINUX_LINKS)
