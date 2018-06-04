mkdir bin
cd bin
cmake -DCMAKE_BUILD_TYPE=Release ..
REM This only works for Vstudio compilations on Windows
cmake --build . --config Release --target ALL_BUILD