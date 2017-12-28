
if "%TYPE%" == "zpm" (    
    cd test
    
    zpmd vs2015 --ci || exit /b 1

    msbuild zpm/PlotLib-ZPM.sln || exit /b 1

    bin\x86\plot-zpm-test.exe || exit /b 1
) else (
    zpmd %VSTUD% --ci || exit /b 1

    msbuild plot/PlotLib.sln /property:Configuration=Release /property:Platform=%PLAT% || exit /b 1

    if %TYPE% == "debug" (
        bin\%ARCH%\plot-testd
    ) else (
        bin\%ARCH%\plot-test
    )
)