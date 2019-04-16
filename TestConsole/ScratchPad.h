#pragma once

#include "Core.h"

#include "Config\cfg-Facilities.h"

#include <vector>
#include <string>
#include <iterator>
#include <unordered_set>

#include <algorithm>

void reverseString(std::string& str)
{
	using namespace std;
	cout << "before reverse: " << str << endl;

	// reverse the input string in place
 	auto& start = str.begin();
	auto& end = str.end() - 1;
	while (*start != *end)
	{
		auto buffer = *start;
		*start = *end;
		*end = buffer;
		start++;
		end--;
	}

	cout << "after reverse: " << str << endl;
}

void reverseWords(std::string& message)
{
	using namespace std;

	// decode the message by reversing the words
	vector<std::string> brokenMessage;
	string delimiter = " ";
	size_t pos = 0;
	std::string token;
	
	do
	{
		pos = message.find(delimiter);
		token = message.substr(0, pos);
		brokenMessage.push_back(token);
		message.erase(0, pos + delimiter.length());
	} while ((pos) != message.npos);

	message.clear();
	std::reverse(brokenMessage.begin(), brokenMessage.end());

	for (auto s : brokenMessage)
	{
		cout << "s = " << s << endl;
		message += (s + " ");
	}

	
}

std::vector<int> mergeVectors(const std::vector<int>& myVector, const std::vector<int>& alicesVector)
{
	using namespace std;

	vector<int> mergedVectors;
	if (myVector.empty() && alicesVector.empty())
	{
		return mergedVectors;
	}

	if (myVector.empty() && !alicesVector.empty())
	{
		mergedVectors = alicesVector;
		return mergedVectors;
	}

	if (!myVector.empty() && alicesVector.empty())
	{
		mergedVectors = myVector;
		return mergedVectors;
	}


	// combine the sorted vectors into one large sorted vector
	mergedVectors.insert(mergedVectors.end(), myVector.begin(), myVector.end());

	vector<int>::const_iterator alicesIter = alicesVector.begin();
	size_t mergedVecSize = mergedVectors.size();
	bool bIsAlicesVectorExausted = false;
	size_t i = 0;
	while (bIsAlicesVectorExausted == false)
	{
		if (alicesIter != alicesVector.end()
			&& *alicesIter < mergedVectors[i])
		{
			mergedVectors.insert(mergedVectors.begin() + i, *alicesIter);
			alicesIter++;
		}
		else if (i == mergedVecSize
			&& alicesIter != alicesVector.end()
			&& *alicesIter > mergedVectors[i])
		{
			mergedVectors.insert(mergedVectors.end(), *alicesIter);
			alicesIter++;
		}

		if (alicesIter == alicesVector.end())
		{
			bIsAlicesVectorExausted = true;
		}

		++i;
	}

	return mergedVectors;
}

bool canTwoMoviesFillFlight(const std::vector<int>& movieLengths, int flightLength)
{
	using namespace std;
	// determine if two movies add up to the flight length
	if (movieLengths.empty())
	{
		return false;
	}

	if (movieLengths.size() > 1)
	{
		unordered_set<int> unorderedMovieLengths;
		unorderedMovieLengths.insert(movieLengths.begin(), movieLengths.end());
		unordered_set<int>::const_iterator movieLenIter = unorderedMovieLengths.begin();
		while (movieLenIter != unorderedMovieLengths.end())
		{
			int composite = flightLength - *movieLenIter;
			if (unorderedMovieLengths.find(composite) != unorderedMovieLengths.end()
				&& unorderedMovieLengths.find(composite) != unorderedMovieLengths.begin())
			{
				return true;
			}

			++movieLenIter;
		}
	}


	return false;
}
