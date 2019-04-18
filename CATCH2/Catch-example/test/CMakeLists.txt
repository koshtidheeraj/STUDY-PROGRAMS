cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)

add_executable(CatchSampleExampleTest
                sample_function_test.cpp)

target_link_libraries(CatchSampleExampleTest
                        PUBLIC CatchSampleExampleLib)

target_include_directories(CatchSampleExampleTest
                            PUBLIC ../externals/ ../src/ )

install(TARGETS CatchSampleExampleTest DESTINATION .)