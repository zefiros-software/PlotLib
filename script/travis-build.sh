#!/bin/bash
set -e

if [ "$TYPE" == "zpm" ]; then
    cd test
    
    zpm gmake --skip-lock

    cd zpm/
    make
    cd ../../

    test/bin/x86/plot-zpm-test

else
    zpm gmake --skip-lock
    cd plot
    make config=${TYPE}_${ARCH}
    cd ../


    if [ "$TYPE" == "debug" ]; then
        bin/${ARCH}/plot-testd

    elif [ "$TYPE" == "coverage" ]; then
        ./plot-testcd
    else
        bin/${ARCH}/plot-test
    fi
fi