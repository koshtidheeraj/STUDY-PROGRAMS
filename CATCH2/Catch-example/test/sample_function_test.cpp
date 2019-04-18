#define CATCH_CONFIG_MAIN
#include "../externals/catch.hpp"
#include "../src/sample_function.h"

TEST_CASE("sample_test_run", "[classic]" ) {
    REQUIRE( sample_class::simple_integer_return() == 21);
}