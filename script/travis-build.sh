set -e

if [[ ${TRAVIS_OS_NAME} = osx ]]; then
    # Since default gcc on osx is just a front-end for LLVM
    # and osx is currently broken with clang frontend
    if [[ ${CC} = gcc ]]; then
        export CXX=g++-4.8
        export CC=gcc-4.8
    fi
fi

premake5 install-package --allow-install --allow-module
premake5 gmake
cd plot
make config=debug_x86
make config=debug_x86_64
make config=release_x86
make config=release_x86_64
#make config=coverage_x86
#make config=coverage_x86_64

cd ../test/

premake5 gmake

cd zpm/
make
cd ../

cd ../docs/images/
../../bin/x86/plot-test
../../bin/x86/plot-testd
#../../bin/x86/plot-testcd

../../bin/x86_64/plot-test
../../bin/x86_64/plot-testd
#../../bin/x86_64/plot-testcd

../../test/bin/x86/plot-zpm-test