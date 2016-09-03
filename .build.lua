
project "PlotLib"

    if zpm.option( "HeaderOnly" ) then
        kind "Utility"
    else
        zpm.export [[
            defines "PLOTLIB_NO_HEADER_ONLY"
        ]]  
        files "plot/src/**.cpp"   
        kind "StaticLib"
    end

    if zpm.option( "UseZPMAnaconda" ) then
        zpm.export [[
            defines "PLOTLIB_USE_ZPM_ANACONDA"
        ]]
    end

    if zpm.option( "UseArma" ) then
        zpm.export [[
            defines "PLOTLIB_ARMA"
        ]]
    end

    zpm.export [[
        includedirs "plot/include/"
        flags "C++11"
    ]]