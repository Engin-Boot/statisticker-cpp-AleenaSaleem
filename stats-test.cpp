//#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"
#include <cmath>
TEST_CASE("reports average, minimum and maximum") {
	Statistics::ComputedStats<float> computedFvalues;
    Statistics::ComputedStats<float> computed_stats = Statistics::ComputeStatistics(computedFvalues,{1.5, 8.9, 3.2, 4.5});
    float epsilon = 0.001;
    REQUIRE(std::abs(computed_stats.average - 4.525) < epsilon);
    REQUIRE(std::abs(computed_stats.Max - 8.9) < epsilon);
    REQUIRE(std::abs(computed_stats.Min - 1.5) < epsilon);
}

TEST_CASE("average is NaN for empty array") {
	 Statistics::ComputedStats<float> computedFvalues;
    Statistics::ComputedStats<float> computed_stats = Statistics::ComputeStatistics(computedFvalues, {});
    REQUIRE(isnan(computed_stats.average) == true);
    REQUIRE(isnan(computed_stats.Max) == true);
    REQUIRE(isnan(computed_stats.Min) == true);
}
