premake5 install-package --allow-install --allow-module
premake5 vs2015
msbuild plot/PlotLib.sln /property:Configuration=Release /property:Platform=Win32
msbuild plot/PlotLib.sln /property:Configuration=Debug /property:Platform=Win32
msbuild plot/PlotLib.sln /property:Configuration=Release /property:Platform=x64
msbuild plot/PlotLib.sln /property:Configuration=Debug /property:Platform=x64

cd ../docs/images/
../../bin/x86/plot-test.exe
../../bin/x86/plot-testd.exe

../../bin/x86_64/plot-test.exe
../../bin/x86_64/plot-testd.exe