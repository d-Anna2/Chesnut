workspace "Chestnut"
    architecture "x64"
    startproject "Sandbox"
    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- inlcude dirs relatie to root folder (solution dir)
IncludeDir = {}
IncludeDir["GLFW"] = "Chestnut/vendor/GLFW/include"
IncludeDir["glad"] = "Chestnut/vendor/glad/include"
IncludeDir["ImGui"] = "Chestnut/vendor/imgui"

include "Chestnut/vendor/GLFW"
include "Chestnut/vendor/glad"
include "Chestnut/vendor/imgui"


project "Chestnut"
    location "Chestnut"
    kind "SharedLib"
    language "C++"
    staticruntime "off"


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
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.glad}",
        "%{IncludeDir.ImGui}"
    }

    links {
        "GLFW",
        "glad",
        "opengl32.lib",
        "ImGui"
    }

    filter "system:windows"
        cppdialect "C++17"
        runtime "Debug"
        systemversion "latest"

        defines {
            "CN_PLATFORM_WINDOWS",
            "CN_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
        }
    
    filter "configurations:Debug"
        defines "CN_DEBUG"
        symbols "On"
        runtime "Debug"
        --buildoptions "/MDd"

    filter "configurations:Release"
        defines "CN_RELEASE"
        optimize "On"
        runtime "Release"
        --buildoptions "/MD"

    filter "configurations:Dist"
        defines "CN_DIST"
        optimize "On"
        runtime "Release"
        --buildoptions "/MD"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    staticruntime "off"

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
        runtime "Debug"
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
        runtime "Debug"
        --buildoptions "/MDd"

    filter "configurations:Release"
        defines "CN_RELEASE"
        optimize "On"
        runtime "Release"
        --buildoptions "/MD"

    filter "configurations:Dist"
        defines "CN_DIST"
        optimize "On"
        runtime "Release"
        --buildoptions "/MD"
   

