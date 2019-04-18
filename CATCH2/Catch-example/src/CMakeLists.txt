cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)

add_executable(CatchSampleExampleExe 
                sampleCatchProgram.cpp
                sample_function.cpp
                sample_function.h)

add_library(CatchSampleExampleLib
                sample_function.cpp
                sample_function.h)
                
# add_executable(CatchSampleExampleTest
#                 src/sample_function_test.cpp)

# target_link_libraries(CatchSampleExampleTest
#                         PUBLIC SampleTestLib)

# target_include_directories(CatchSampleExampleTest
#                             PUBLIC ../externals/ ../src/ )

# install(TARGETS CatchSampleExampleTest DESTINATION .)
install(TARGETS CatchSampleExampleExe DESTINATION .)
install(TARGETS CatchSampleExampleLib DESTINATION .)