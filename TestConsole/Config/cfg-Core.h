#pragma once

static const bool bEnabled = true;
static const bool bDisabled = false;

#define ENABLED 1
#define DISABLED 0

// Allow for control of different facility functionality in one location
#if _DEBUG
#define TEST_FACILITIES_ENABLED ENABLED
#define MATH_TESTS_ENABLED DISABLED
#define DATA_STRUCT_TESTS_ENABLED ENABLED
#define GENERAL_TESTS_ENABLED ENABLED
#else
#define MATH_TESTS_ENABLED DISABLED
#define DATA_STRUCT_TESTS_ENABLED DISABLED
#define TEST_FACILITIES_ENABLED DISABLED
#define GENERAL_TESTS_ENABLED DISABLED
#endif

#undef FORCEINLINE
#define FORCEINLINE __forceinline

