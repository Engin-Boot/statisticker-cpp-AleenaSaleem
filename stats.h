#include<iostream>
#include <vector>
#include<math.h>
#include<numeric>
#include<bits/stdc++.h>

using namespace std;

namespace Statistics{
	template <class numeric_type>
	struct ComputedStats{
		numeric_type average;
		numeric_type Max;
		numeric_type Min;
	};	
	template <typename numeric_type>
	void ComputeAverage(struct ComputedStats<numeric_type> &computedValues, const vector<numeric_type>& data){
		numeric_type sum = 0;
		sum = accumulate( data.begin(), data.end(), sum);
		computedValues.average = sum / data.size();
	}
	
	template <typename numeric_type>
	void ComputeMax(struct ComputedStats<numeric_type> &computedValues, const vector<numeric_type>& data){
		computedValues.Max = *max_element(data.begin(), data.end());
	}
	
	template <typename numeric_type>
	void ComputeMin(struct ComputedStats<numeric_type> &computedValues, const vector<numeric_type>& data){
		computedValues.Min = *min_element(data.begin(), data.end());
	}
	
	template <typename numeric_type>
	struct ComputedStats<numeric_type> ComputeStatistics(struct ComputedStats<numeric_type> &computedValues, const vector<numeric_type>& data){
		if(data.size() == 0)
	    	{
			computedValues.average = numeric_limits<numeric_type>::quiet_NaN();
			computedValues.Max = numeric_limits<numeric_type>::quiet_NaN();
			computedValues.Min = numeric_limits<numeric_type>::quiet_NaN();
			return computedValues;
		}
		ComputeAverage(computedValues,data);
		ComputeMax(computedValues,data);
		ComputeMin(computedValues,data);
		return computedValues;
	}
}
