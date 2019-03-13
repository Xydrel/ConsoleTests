#include "Core.h"
#include "Math.h"
#include "BinaryNode.h"
#include "HackerRank.h"

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
	RunHackerRankTestFunctions();
#endif


	system("pause");
	return 0;
}