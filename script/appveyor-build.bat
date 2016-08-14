premake5 install-package --allow-install --allow-module  || exit /b 1
premake5 vs2015 || exit /b 1
msbuild plot/PlotLib.sln /property:Configuration=Release /property:Platform=Win32 || exit /b 1
msbuild plot/PlotLib.sln /property:Configuration=Debug /property:Platform=Win32 || exit /b 1
msbuild plot/PlotLib.sln /property:Configuration=Release /property:Platform=x64 || exit /b 1
msbuild plot/PlotLib.sln /property:Configuration=Debug /property:Platform=x64 || exit /b 1

cd test/
premake5 vs2015 || exit /b 1
msbuild zpm/PlotLib-ZPM.sln || exit /b 1

cd ../docs/images/ || exit /b 1
..\..\bin\x86\plot-test.exe || exit /b 1
..\..\bin\x86\plot-testd.exe || exit /b 1

..\..\bin\x86_64\plot-test.exe || exit /b 1
..\..\bin\x86_64\plot-testd.exe || exit /b 1

..\..\test\bin\x86\plot-zpm-test.exe || exit /b 1