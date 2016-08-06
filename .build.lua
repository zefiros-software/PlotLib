
project "PlotLib"

    if zpm.option( "HeaderOnly" ) then
        defines "PLOTLIB_NO_HEADER_ONLY"     
        files "plot/src/**.cpp"   
        kind "StaticLib"
    else
        kind "Utility"
    end

    if zpm.option( "UseZPMAnaconda" ) then
        defines "PLOTLIB_USE_ZPM_ANACONDA"
    end

    zpm.export [[
        includedirs "plot/include/"
        defines "PLOTLIB_USE_ZPM_ANACONDA"
        flags "C++11"
    ]]