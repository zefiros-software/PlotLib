
project "PlotLib"
        
    kind "StaticLib"

    if not zpm.option( "HeaderOnly" ) then
        zpm.export [[
            defines "PLOTLIB_NO_HEADER_ONLY"
        ]]  
        files "plot/src/**.cpp"   
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
