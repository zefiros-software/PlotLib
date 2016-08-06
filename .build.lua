
project "PlotLib"

    if zpm.option( "HeaderOnly" ) then
        zpm.export [[
        defines "PLOTLIB_NO_HEADER_ONLY"   
        ]]  
        files "plot/src/**.cpp"   
        kind "StaticLib"
    else
        kind "Utility"
    end

    if zpm.option( "UseZPMAnaconda" ) then
        zpm.export [[
            defines "PLOTLIB_USE_ZPM_ANACONDA"
        ]]
    end

    zpm.export [[
        includedirs "plot/include/"
        flags "C++11"
    ]]