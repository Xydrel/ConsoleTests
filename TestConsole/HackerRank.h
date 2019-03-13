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

		for (int i = 0; i < arr.size(); i++)
		{
			// complete sorting operation
			if (arr[i] != (i + 1))
			{
				for (int j = 0; j < arr.size(); j++)
				{
					if (arr[j] == (i + 1))
					{
						int numBuff = arr[i];
						arr[i] = arr[j];
						arr[j] = numBuff;
						minimumSwapsMade++;
						break;
					}
				}
			}

			// debugging code
			std::cout << std::endl;
			for (auto i : arr)
			{
				std::cout << i << " ";
			}
		}
	
	std::cout << std::endl;
	std::cout << "minimimSwapsMade = " << minimumSwapsMade << std::endl;
	return minimumSwapsMade;
}









// Remains last function to avoid necessity of forward declaring functions
void RunHackerRankTestFunctions()
{
	std::cout << "Running HackerRank Test functions" << std::endl;


	std::vector<int> arr = { 1,3,5,2,4,6,7 }; // should resut in 3
	//std::vector<int> arr = { 4,3,1,2 }; // should result in 3
	minimumSwaps(arr);
}
#endif