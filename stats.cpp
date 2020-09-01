#include"stats.h"
#include<numeric>
#include<bits/stdc++.h>

namespace Statistics{
	template <typename numeric_type>
	void ComputeAverage(struct ComputedStats<numeric_type> &computedValues, vector<numeric_type>& data){
		numeric_type sum = 0;
		sum = accumulate( data.begin(), data.end(), sum);
		computedValues.average = sum / data.size();
	}
	
	template <typename numeric_type>
	void ComputeMax(struct ComputedStats<numeric_type> &computedValues, vector<numeric_type>& data){
		computedValues.Max = *max_element(data.begin(), data.end());
	}
	
	template <typename numeric_type>
	void ComputeMin(struct ComputedStats<numeric_type> &computedValues, vector<numeric_type>& data){
		computedValues.Min = *min_element(data.begin(), data.end());
	}
	
	template <typename numeric_type>
	struct ComputedStats<numeric_type> ComputeStatistics(struct ComputedStats<numeric_type> &computedValues, vector<numeric_type>& data){
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

/*int main(){
	vector<int> int_data;
	int_data.push_back(1);
	int_data.push_back(2);
	int_data.push_back(3);
	int_data.push_back(4);
	vector<float> float_data;
	float_data.push_back(1.0);
	float_data.push_back(2.0);
	float_data.push_back(3.0);
	float_data.push_back(4.0);
	Statistics::ComputedStats<int> computedvalues;
	Statistics::ComputeStatistics(computedvalues,int_data);
	cout<<"Average_int: "<<computedvalues.average<<endl;
	cout<<"Max_int: "<<computedvalues.Max<<endl;
	cout<<"Min_int: "<<computedvalues.Min<<endl;
	Statistics::ComputedStats<float> computedFvalues;
	Statistics::ComputeStatistics(computedFvalues,float_data);
	cout<<"Average_float: "<<computedFvalues.average<<endl;
	cout<<"Max_float: "<<computedFvalues.Max<<endl;
	cout<<"Min_float: "<<computedFvalues.Min<<endl;
	return 0;
}*/
