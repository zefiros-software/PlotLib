premake5 install-package --allow-install --allow-module  || exit /b
premake5 vs2015 || exit /b
msbuild plot/PlotLib.sln /property:Configuration=Release /property:Platform=Win32 || exit /b
msbuild plot/PlotLib.sln /property:Configuration=Debug /property:Platform=Win32 || exit /b
msbuild plot/PlotLib.sln /property:Configuration=Release /property:Platform=x64 || exit /b
msbuild plot/PlotLib.sln /property:Configuration=Debug /property:Platform=x64 || exit /b

cd test/
premake5 vs2015 || exit /b
msbuild zpm/PlotLib-ZPM.sln || exit /b

cd ../docs/images/ || exit /b
%~dp0/../../bin/x86/plot-test.exe || exit /b
%~dp0/../../bin/x86/plot-testd.exe || exit /b

%~dp0/../../bin/x86_64/plot-test.exe || exit /b
%~dp0/../../bin/x86_64/plot-testd.exe || exit /b

%~dp0/../../test/bin/x86/plot-zpm-test.exe || exit /b