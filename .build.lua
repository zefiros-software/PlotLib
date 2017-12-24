project "PlotLib"

    kind "StaticLib"

    if not zpm.setting("headerOnly") then
        zpm.export [[
            defines "PLOTLIB_NO_HEADER_ONLY"
        ]]
    
        
        files "plot/src/**.cpp"
    end

    if zpm.has("Zefiros-Software/Miniconda") then
        zpm.export [[
            defines "PLOTLIB_USE_ZPM_ANACONDA"
        ]]

    end

    if zpm.has("Zefiros-Software/Armadillo") then
        zpm.export [[
            defines "PLOTLIB_ARMA"
        ]]

    end

    zpm.export [[
        includedirs "plot/include/"
        cppdialect "C++11"
    ]]
