#include<iostream>
#include <vector>
#include<math.h>

using namespace std;


namespace Statistics {
	template <typename numeric_type>
	struct ComputedStats{
		numeric_type average;
		numeric_type Max;
		numeric_type Min;
	};	
	template <typename numeric_type>
		void ComputeAverage(struct ComputedStats<numeric_type>&,const vector<numeric_type>& );
	template <typename numeric_type>
		void ComputeMax(struct ComputedStats<numeric_type>&,const vector<numeric_type>& );
	template <typename numeric_type>
		void ComputeMin(struct ComputedStats<numeric_type>&,const vector<numeric_type>& );
	template <typename numeric_type>
	struct ComputedStats<numeric_type> ComputeStatistics(struct ComputedStats<numeric_type>&,const vector<numeric_type>& );
}
