#include "pch.h"
#include "../oop_lab2_prog/lab2.h"

TEST(GetTimeOfOperationInHours, TestCornerCases) {
	//dRatio=0
	double uiResult = GetTimeOfOperationInHours(100,200, 0);
	EXPECT_EQ(uiResult, -1);

	//dRatio=1
	uiResult = GetTimeOfOperationInHours(100,200,1);
	EXPECT_EQ(uiResult, -1);


	//dW=0
	uiResult = GetTimeOfOperationInHours(0, 200, 0.5);
	EXPECT_EQ(uiResult, -1);

	//dC=0
	uiResult = GetTimeOfOperationInHours(100, 0, 0.5);
	EXPECT_EQ(uiResult, -1);
}

TEST(GetTimeOfOperationInHours, TestNegativeInput) {
	//dW<0
	double uiResult = GetTimeOfOperationInHours(-100, 200, 1);
	EXPECT_EQ(uiResult, -1);

	//dC<0
	uiResult = GetTimeOfOperationInHours(100, -200, 1);
	EXPECT_EQ(uiResult, -1);

	//dRatio<0
	uiResult = GetTimeOfOperationInHours(100, 200, -1);
	EXPECT_EQ(uiResult, -1);

	//dRatio>1
	uiResult = GetTimeOfOperationInHours(100, 200, 2);
	EXPECT_EQ(uiResult, -1);
}

TEST(GetTimeOfOperationInHours, TestValidInput) {
	//Random valid input
	double uiResult = GetTimeOfOperationInHours(7, 5637, 0.75);
	EXPECT_NEAR(uiResult, 603.964, 0.001);

	uiResult = GetTimeOfOperationInHours(100, 200, 0.7);
	EXPECT_EQ(uiResult, 1.4);

	//Big numbers
	uiResult = GetTimeOfOperationInHours(1e9, 1e12, 0.1);
	EXPECT_NEAR(uiResult, 1e2, 1e-4);

	//Small numbers
	uiResult = GetTimeOfOperationInHours(1e-10, 1e-12, 0.9);
	EXPECT_NEAR(uiResult, 0.9e-2, 1e-4);
}