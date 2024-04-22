#include "ProcessVector.h"
#include <vector>
#include <iostream>
#include <algorithm>


void ProcessVector(std::vector<double>& vector)
{
	if (!vector.empty())
	{
		const  auto [min, max] = std::minmax_element(vector.begin(), vector.end());
		//использовать minmax_element
		const double minElem = *min;
		const double maxElem = *max;
		for (double& item : vector)
		{
			item = item * maxElem / minElem;
		}
		/*
		std::transform(vector.begin(), vector.end(), vector.begin(), 
			[](auto val) {return val = val * max / minElem; });

		/**/
		//использовать std::transform или std::ranges::transform
	}
}
