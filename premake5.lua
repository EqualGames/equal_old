require "tools/premake/helpers"
require "config"
require "external/glm"
require "external/pugixml"
require "external/fmt"

workspace "Equal"
  architecture "x64"
  configurations { "Debug", "Release" }

  project "Equal"
    kind "StaticLib"
    language "C++"
    cppdialect "gnu++17"
    staticruntime "on"
    targetdir (TARGET_DIR)
    debugdir (DEBUG_DIR)
    objdir (OBJ_DIR)
    flags "NoPCH"

    files (GetHeaders("include", Platforms))
    files (GetHeaders("src", Platforms))
    files (GetSources("src", Platforms))
    includedirs "include"
    includedirs "src"
    
    -- Third-Party
    files (GetHeaders(GLM_INCLUDES))
    files (GetSources(GLM_SOURCES))
    files (GetHeaders(FMT_INCLUDES))
    files (GetSources(FMT_SOURCES))
    files (GetHeaders(PUGIXML_INCLUDES))
    files (GetSources(PUGIXML_SOURCES))
    includedirs (GLM_INCLUDES)
    includedirs (PUGIXML_INCLUDES)
    includedirs (FMT_INCLUDES)

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
      files (GetSources("src/platform/sdl"))

    postbuildcommands {
      "cd tests && premake5 gmake2 && make -B && ./build/Test && cd ..",
      "premake5 docs",
      "premake5 install",
    }

    ---------- Linux ----------

    filter "system:linux"
      toolset "gcc"
      defines (EQUAL_LINUX_DEFINES)
      buildoptions (EQUAL_LINUX_BUILD_OPTIONS)
      linkoptions (EQUAL_LINUX_LINK_OPTIONS)
      includedirs (EQUAL_LINUX_INCLUDES)
      libdirs (EQUAL_LINUX_LIBRARIES)
      links (EQUAL_LINUX_LINKS)

      newaction {
        trigger     = "docs",
        description = "Generate documentation",
        execute     = function ()
          os.execute("sh tools/scripts/generate_docs.sh")
        end
      }

      newaction {
        trigger     = "install",
        description = "Install library locally",
        execute     = function ()
          os.execute("sudo cp build/libEqual.a /usr/local/lib/libEqual.a")
        end
      }
