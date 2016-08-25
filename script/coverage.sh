set -e

cd plot
make config=coverage_x86
cd ../

./plot-testcd

codecov
