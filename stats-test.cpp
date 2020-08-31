#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"
#include <cmath>

TEST_CASE("reports average, minimum and maximum") {
    Statistics::ComputedStats<float> computedFvalues;
    auto computedStats = Statistics::ComputeStatistics(computedFvalues, {1.5, 8.9, 3.2, 4.5});
    float epsilon = 0.001;
    REQUIRE(std::abs(computedStats.average - 4.525) < epsilon);
    REQUIRE(std::abs(computedStats.Max - 8.9) < epsilon);
    REQUIRE(std::abs(computedStats.Min - 1.5) < epsilon);
}

TEST_CASE("average is NaN for empty array") {
    Statistics::ComputedStats<float> computedFvalues;
    auto computedStats = Statistics::ComputeStatistics(computedFvalues,{});
    REQUIRE(isnan(computedStats.average) == true);
    REQUIRE(isnan(computedStats.Max) == true);
    REQUIRE(isnan(computedStats.Min) == true);
}
