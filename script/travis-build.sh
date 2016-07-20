premake5 install-package --allow-modules
premake5 gmake
make config=debug_x86
make config=debug_x86_64
make config=release_x86
make config=release_x86_64
make config=coverage_x86
make config=coverage_x86_64

cd docs/images/
../../bin/x86/plot-test
../../bin/x86/plot-testd
../../bin/x86/plot-testcd

../../bin/x86_64/plot-test
../../bin/x86_64/plot-testd
../../bin/x86_64/plot-testcd