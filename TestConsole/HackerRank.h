#pragma once
#include "Core.h"

#include "Config\cfg-Facilities.h"

#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
#include <unordered_set>

// this is bad, but to make things simple.. here it is for now.
using namespace std;


#if TEST_FACILITY_ENABLED && GENERAL_TESTS_ENABLED
class WordCloudData
{
public:
	WordCloudData(const string& inputString) :
		wordStartIndex_(0),
		wordEndIndex_(0)
	{
		characterToUse_ = {
			'a','b','c','d',
			'e','f','g','h',
			'i','j','k','l',
			'm','n','o','p',
			'q','r','s','t',
			'u','v','w','x',
			'y','z','-','\''
		};
		cout << "set was filled and has count = " << characterToUse_.size() << endl;

		populateWordsToCounts(inputString);
	}

	const unordered_map<string, size_t> getWordsToCounts() const
	{
		return wordsToCounts_;
	}

private:
	void populateWordsToCounts(const string& inputString)
	{


		// count the frequency of each word
		fillMapWithWordCounts(inputString);

	}

	void fillMapWithWordCounts(const string& inputString)
	{
		for (size_t i = 0; i <= inputString.size(); ++i)
		{
			// check for special char in O(1) set lookup
			// characterToUse_.find(inputString[i])

			string wordToCount = "";
			auto charFindResult = characterToUse_.find(inputString[i]);
			if (charFindResult != characterToUse_.end()
				|| characterToUse_.find(inputString[i] + 32) != characterToUse_.end())
			{
				// build the string word to add and count
				cout << "building string: curr char = " << inputString[i] << endl;
				wordToCount.push_back(inputString[i]);
			}
			else
			{
				unordered_map<string, size_t>::iterator wordCountsIter = wordsToCounts_.find(wordToCount);
				if (wordCountsIter != wordsToCounts_.end())
				{
					cout << "inserting new pair" << endl;
					// if nothing found, go ahead and add and start count at 0
					wordsToCounts_.insert(std::make_pair(wordToCount, 1));
				}
				else
				{
					// we found an entry for that word, get the current count and increment
					//cout << "updating count of existing pair" << endl;
					//wordCountsIter->second++;
				}
				wordToCount.clear();
			}

		}
	}

	/* Private Properties */
	unordered_map<string, size_t> wordsToCounts_;
	unordered_set<char> characterToUse_;
	size_t wordStartIndex_;
	size_t wordEndIndex_;
};



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

		for (size_t i = 0; i < arr.size(); i++)
		{
			// complete sorting operation
			if (arr[i] != (i + 1))
			{
				for (size_t j = 0; j < arr.size(); j++)
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