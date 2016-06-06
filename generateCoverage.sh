rm -rf gcov
rm -rf target/site/clover
mkdir gcov
cd gcov/
gcov --object-directory ../bin/obj/x86/Coverage/prediction-test/* ../test
lcov --capture --base-directory ../test --directory .. --directory ../test/ --directory ../prediction/include/ --output-file coverage.info --no-external
genhtml coverage.info --output-directory ../target/site/clover
python  ../assets/Zefiros-Software/SerLib/Zefiros-Software/gcov2clover/gcov2clover.py *.gcov