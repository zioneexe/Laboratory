#include "pch.h"
#include "..\oop_lab4_prog\class.hpp"

TEST(TestOperators, BitwiseAND_Operator) {
	////Valid case

	bool first[32] = { 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0 };
	bool second[32] = { 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1 };
	bool expectedresult[32] = { 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0 };

	CBitField First(first, 32);
	CBitField Second(second, 32);
	CBitField ExpectedResult(expectedresult, 32);

	CBitField Result = First & Second;

	for (int i = 0; i < 32; ++i) {
		ASSERT_EQ(ExpectedResult.GetBit(i), Result.GetBit(i));
	}
}

TEST(TestOperators, BitwiseOR_Operator) {
	//Valid case

	bool first[32] = { 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0 };
	bool second[32] = { 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1 };
	bool expectedresult[32] = { 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1 };

	CBitField First(first, 32);
	CBitField Second(second, 32);
	CBitField ExpectedResult(expectedresult, 32);

	CBitField Result = First | Second;

	for (int i = 0; i < 32; ++i) {
		ASSERT_EQ(ExpectedResult.GetBit(i), Result.GetBit(i));
	}
}

TEST(TestOperators, BitwiseXOR_Operator) {
	//Valid case

	bool first[32] = { 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0 };
	bool second[32] = { 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1 };
	bool expectedresult[32] = { 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1 };

	CBitField First(first, 32);
	CBitField Second(second, 32);
	CBitField ExpectedResult(expectedresult, 32);

	CBitField Result = First ^ Second;

	for (int i = 0; i < 32; ++i) {
		ASSERT_EQ(ExpectedResult.GetBit(i), Result.GetBit(i));
	}
}

TEST(TestOperators, OStream_Operator) {
	//Valid case
	
	stringstream ss;
	bool arr[32] = { 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1,
					1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0 };
	CBitField bf(arr, 32);
	ss << bf;
	string expected_output = "Bits:\n1 0 1 0 0 1 0 1 1 0 1 0 1 0 0 1 1 0 0 1 1 0 0 1 0 1 1 0 0 1 1 0 ";
	ASSERT_EQ(ss.str(), expected_output);
}

TEST(TestOperators, IStream_Operator) {
	//Valid case
	
	stringstream ss;
	CBitField bf;
	ss << "0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1\n";
	ss >> bf;

	for (int i = 0; i < 32; ++i) {
		if (i % 2 == 0) {
			ASSERT_EQ(bf.GetBit(i), 0);
		}
		else {
			ASSERT_EQ(bf.GetBit(i), 1);
		}
	}
}

TEST(TestOperators, Index_Operator) {
	//Valid case

	bool array[20] = { 1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,1,0,1,1,1 };

	CBitField bits(array, 20);

	EXPECT_EQ(bits.GetBit(0), bits[0]);
	EXPECT_EQ(bits.GetBit(31), bits[31]);
	EXPECT_NE(bits.GetBit(0), bits[7]);
	EXPECT_DEATH(bits[-5], "");
	EXPECT_DEATH(bits[33], "");
}

TEST(TestOperators, Equals_Operator) {
	//Valid case

	bool first[32] = { 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0 };
	bool second[32] = { 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1 };
	bool expectedresult[32] = { 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1 };

	CBitField First(first, 32);
	CBitField Second(second, 32);
	CBitField ExpectedResult(expectedresult, 32);

	CBitField Result = First.BitwiseXOR(Second);

	EXPECT_TRUE(Result == ExpectedResult);
	EXPECT_FALSE(First == Second);
}

TEST(TestOperators, TestStaticCounter) {
	//Valid case

	CBitField bits;

	bool arr[32] = { 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0 };
	CBitField arrarr(arr, 32);

	CBitField intarr(9);

	EXPECT_EQ(CBitField::GetCount(), 3);
}

TEST(TestOtherFunctions, StringSetterTest) {
	//Valid case

	CBitField bf;

	stringstream ss;
	ss << "10101110";
	bf.Setter(ss);

	EXPECT_TRUE(bf.GetBit(0) && bf.GetBit(2) && bf.GetBit(4) && bf.GetBit(5) && bf.GetBit(6));
	EXPECT_FALSE(bf.GetBit(1) || bf.GetBit(3) || bf.GetBit(7));
}

TEST(TestOtherFunctions, FileSetterTest) {
	//Valid case
	
	CBitField bf;

	bf.Setter("test.txt");

	for (int i = 0; i < 32; ++i) {
		if (i % 5 == 0) {
			EXPECT_FALSE(bf.GetBit(i));
		}
		else {
			EXPECT_TRUE(bf.GetBit(i));
		}
	}
}

TEST(TestOtherFunctions, RandomSetterTest) {
	//Valid case
	
	bool bit = false;
	CBitField bf;

	bf.Setter(bit);

	for (int i = 0; i < 32; i++) {
		ASSERT_TRUE(bf.GetBit(i) || !bf.GetBit(i));
	}
}