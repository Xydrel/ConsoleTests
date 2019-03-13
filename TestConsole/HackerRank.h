#pragma once
#include "Core.h"

#include "Config\cfg-Facilities.h"

#include <vector>
#include <string>


#if TEST_FACILITY_ENABLED && GENERAL_TESTS_ENABLED

int GetLandAreas(const std::vector<std::vector<std::string>> arr)
{
	int FoundLandItems = 0;
	for (auto& item : arr)
	{
		for (auto& subItem : item)
		{
			if (subItem == "L")
			{
				FoundLandItems++;
			}
		}
	}

	return FoundLandItems;
}

int minimumSwaps(std::vector<int>& arr) 
{
	int minimumSwapsMade = 0;
	std::cout << "traversing the arr" << std::endl;
	for (int i = arr.back() - 1; i >= 0; i--)
	{
		// complete sorting operation
		std::cout << i << " ";
		if (arr[i] != (i + 1))
		{
			std::cout << "i+1 = " << i+1 << " arr[i] = " << arr[i] << std::endl;
			//for (int j = 0; j < arr.back() - 1; j++)
			//{

			//}
		}
	}
	std::cout << std::endl;
	return minimumSwapsMade;
}









// Remains last function to avoid necessity of forward declaring functions
void RunHackerRankTestFunctions()
{
	std::cout << "Running HackerRank Test functions" << std::endl;


	std::vector<int> arr = { 1,3,5,2,4,6,7 };
	minimumSwaps(arr);
}
#endif