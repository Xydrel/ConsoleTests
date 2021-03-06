#include "Core.h"
#include "Math.h"
#include "BinaryTreeNode.h"
#include "BinarySearchTree.h"
#include "HackerRank.h"
#include "ScratchPad.h"

#include "Config\cfg-Facilities.h"

int main(void)
{

#if TEST_FACILITY_ENABLED
	// nothing needed here currently
#endif

#if MATH_TESTS_ENABLED
	RunMathTestFunctions();
#endif

#if TEST_DATA_STRUCTS_FACITLITY_ENABLED

	RunBinarySearchTreeTests();
#endif

#if GENERAL_TESTS_ENABLED
	//RunHackerRankTestFunctions();

	//std::string test1("A");
	//reverseString(test1);

	//std::string test2("ABCDE");
	//reverseString(test2);

	/*std::string message1("one another get");
	reverseWords(message1);*/

	/*const std::vector<int> myVector{ 2, 4, 6, 8 };
	const std::vector<int> alicesVector{ 1, 7 };
*/
	/*const std::vector<int> myVector{ 2, 4, 6 };
	const std::vector<int> alicesVector{ 1, 3, 7 };
	mergeVectors(myVector, alicesVector);
*/

	//const std::vector<int> movieLengths{ 4, 3, 2 };
	//const std::vector<int> movieLengths{ 6 };
	//const std::vector<int> movieLengths{ 3, 8 };
	//bool result = canTwoMoviesFillFlight(movieLengths, 6);
	//std::string resultString = (result == 1) ? "true" : "false";
	//std::cout << "result: " << resultString << std::endl;

	//EXPECT(canTwoMoviesFillFlight(movieLengths, 6) == false);

	
#endif


	system("pause");
	return 0;
}