#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"
#include <cmath>
TEST_CASE("reports average, minimum and maximum") {
	struct Statistics::ComputedStats<float> computedFvalues;
	vector<float> float_data;
	float_data.push_back(1.5);
	float_data.push_back(8.9);
	float_data.push_back(3.2);
	float_data.push_back(4.5);
    auto computed_stats = Statistics::ComputeStatistics(computedFvalues, float_data);
    float epsilon = 0.001;
    REQUIRE(std::abs(computed_stats.average - 4.525) < epsilon);
    REQUIRE(std::abs(computed_stats.Max - 8.9) < epsilon);
    REQUIRE(std::abs(computed_stats.Min - 1.5) < epsilon);
}

TEST_CASE("average is NaN for empty array") {
	struct Statistics::ComputedStats<float> computedFvalues;
	vector<float> float_data;
    auto computed_stats = Statistics::ComputeStatistics(computedFvalues, float_data);
    REQUIRE(isnan(computed_stats.average) == true);
    REQUIRE(isnan(computed_stats.Max) == true);
    REQUIRE(isnan(computed_stats.Min) == true);
}
