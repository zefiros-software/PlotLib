

workspace "PlotLib"
    
    configurations { "Debug", "Release", "Coverage" }
    platforms { "x86_64", "x86" }


    startproject "plot-test"
	location "plot/"
	objdir "bin/obj/"

	vectorextensions "SSE2"
	floatingpoint "Fast"
	warnings "Extra"
	
	flags {
		"Unicode",
		"C++11"
	}
    
    filter "platforms:x86"
        targetdir "bin/x86/"
        debugdir "bin/x86/"
        architecture "x86"
    
    filter "platforms:x86_64"
        targetdir "bin/x86_64/"
        debugdir "bin/x86_64/"
        architecture "x86_64"
        
    filter "*Debug"
        targetsuffix "d"
        defines "DEBUG"
        optimize "Off"

    filter "*Release"
        flags "LinkTimeOptimization"
        optimize "Speed"
        
    filter { "Coverage", "action:gmake" }
        targetsuffix "cd"
        links "gcov"
        buildoptions "-coverage"
        
    zpm.buildLibraries()
				
	filter {}
			
	project "plot-test"
				
		kind "ConsoleApp"
		flags "WinMain"
		
		location "test/"
        
        zpm.uses {
			"Zefiros-Software/ArmadilloExt",
			"Zefiros-Software/GoogleTest"
		}
		
		includedirs {			
			"plot/include/",
			"test/"
			}	
		
		files { 
			"test/**.h",
			"test/**.cpp"
			}
			
		filter "action:gmake"
			links "pthread"
            
        filter { "*Debug", "platforms:x86" }
            defines "PREFIX=X86D_"
        
        filter { "*Debug", "platforms:x86_64" }
            defines "PREFIX=X86_64D_"
        
        filter { "*Release", "platforms:x86" }
            defines "PREFIX=X86R_"
        
        filter { "*Release", "platforms:x86_64" }
            defines "PREFIX=X86_64R_"
			
	project "plot"
		targetname "plot"	 
		kind "StaticLib"
                
		includedirs {
			"plot/include/"
			}				
		
		files { 
			"plot/include/**.h"
			}