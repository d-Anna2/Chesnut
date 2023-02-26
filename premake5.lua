workspace "Chestnut"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- inlcude dirs relatie to root folder (solution dir)
IncludeDir = {}
IncludeDir["GLFW"] = "Chestnut/vendor/GLFW/include"

include "Chestnut/vendor/GLFW"

project "Chestnut"
    location "Chestnut"
    kind "SharedLib"
    language "C++"


    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "cnpch.h"
    pchsource "Chestnut/src/cnpch.cpp"

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        runtime "Debug"
        buildoptions "/MDd"
        systemversion "latest"

        defines {
            "CN_PLATFORM_WINDOWS",
            "CN_BUILD_DLL"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
        }
    
    filter "configurations:Debug"
        defines "CN_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "CN_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "CN_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "Chestnut/vendor/spdlog/include",
        "Chestnut/src"
    }

    links {
        "Chestnut"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        runtime "Debug"
        buildoptions "/MDd"
        systemversion "latest"

        defines {
            "CN_PLATFORM_WINDOWS"        }

        postbuildcommands {
            --("{COPY} %{cfg.buildtarget.relpath} .. /bin/" .. outputdir .. "/Sandbox")
            --("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
        } 
    
    filter "configurations:Debug"
        defines "CN_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "CN_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "CN_DIST"
        optimize "On"
   

