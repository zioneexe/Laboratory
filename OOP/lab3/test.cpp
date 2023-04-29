#include "pch.h"
#include "../oop_lab3_prog/class.hpp"


TEST(TestFunctions, Constructor) {
	//Valid case

	CBitField bits;

	bits.GetBit(0);

	for (int i = 0; i < 32; ++i) {
		ASSERT_FALSE(bits.GetBit(i));
	}
}
TEST(TestFunctions, IntConstructor) {
	//Valid case

	CBitField bits(9);
	bits.PrintField();
	EXPECT_TRUE(bits.GetBit(0) && bits.GetBit(3));
	for (int i = 4; i < 32; ++i) {
		EXPECT_FALSE(bits.GetBit(1) || bits.GetBit(2) || bits.GetBit(i));
	}
}

TEST(TestFunctions, ArrayConstructor) {
	//Valid case

	bool array[20] = { 1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,1,0,1,1,1 };

	CBitField bits(array, 20);


	EXPECT_TRUE(bits.GetBit(0) && bits.GetBit(1) && bits.GetBit(2) && bits.GetBit(3) && bits.GetBit(4) && bits.GetBit(12) && bits.GetBit(13) && bits.GetBit(15) && bits.GetBit(17) && bits.GetBit(18) && bits.GetBit(19));

	EXPECT_FALSE(bits.GetBit(5) || bits.GetBit(6) || bits.GetBit(7) || bits.GetBit(8) || bits.GetBit(9) || bits.GetBit(10) || bits.GetBit(11) || bits.GetBit(14) || bits.GetBit(16));

	for (int i = 20; i < 32; ++i) {
		EXPECT_FALSE(bits.GetBit(i));
	}

	EXPECT_DEATH(CBitField errbits(array, 788), "");
}

TEST(TestFunctions, FirstLastBitsConstructor) {
	//Valid case

	bool first[16] = { 1,1,0, 0 };
	bool last[16] = { 1 };

	CBitField bits(first, last);

	for (int i = 0; i < 16; i++) {
		if (i == 0 || i == 1) {
			EXPECT_TRUE(bits.GetBit(i));
		}
		else EXPECT_FALSE(bits.GetBit(i));
	}

	for (int i = 16; i < 32; i++) {
		EXPECT_TRUE(bits.GetBit(i));
	}
}

TEST(TestFunctions, Getter) {
	//Valid case

	bool newarray[32] = { 0 };
	bool array[20] = { 1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,1,0,1,1,1 };

	CBitField bits(array, 20);

	bits.Getter(newarray);

	EXPECT_TRUE(newarray[0] && newarray[1] && newarray[2] && newarray[3] && newarray[4] && newarray[12] && newarray[13] && newarray[15] && newarray[17] && newarray[18] && newarray[19]);

	EXPECT_FALSE(newarray[5] || newarray[6] || newarray[7] || newarray[8] || newarray[9] || newarray[10] || newarray[11] || newarray[14] || newarray[16]);

	for (int i = 20; i < 32; i++) {
		EXPECT_FALSE(newarray[i]);
	}
}

TEST(TestFunctions, GetBit) {
	//Valid case
	bool array[20] = { 1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,1,0,1,1,1 };

	CBitField bits(array, 20);

	EXPECT_TRUE(bits.GetBit(0));
	EXPECT_FALSE(bits.GetBit(31));

	EXPECT_DEATH(bits.GetBit(-1),"");
	EXPECT_DEATH(bits.GetBit(55),"");
}

TEST(TestFunctions, SetBit) {
	//Valid case

	bool array[20] = { 1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,1,0,1,1,1 };

	CBitField bits(array, 20);

	bits.SetBit(0, false);
	EXPECT_FALSE(bits.GetBit(0));

	bits.SetBit(5, true);
	EXPECT_TRUE(bits.GetBit(5));
}

TEST(TestFunctions, NumOfTrueBits) {
	//Valid case

	bool array[20] = { 1,1,1,1,1,0,0,0,0,0,0,0,1,1,0,1,0,1,1,1 };

	CBitField bits(array, 20);

	int cnt = 0;
	for (int i = 0; i < 32; ++i) {
		if (bits.GetBit(i)) ++cnt;
	}

	EXPECT_EQ(cnt, 11);
}

TEST(TestFunctions, BitwiseAND) {
	//Valid case

	bool first[32] = { 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0 };
	bool second[32] = { 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1 };
	bool expectedresult[32] = { 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0 };

	CBitField First(first, 32);
	CBitField Second(second, 32);
	CBitField ExpectedResult(expectedresult, 32);

	CBitField Result = First.BitwiseAND(Second);

	for (int i = 0; i < 32; ++i) {
		ASSERT_EQ(ExpectedResult.GetBit(i), Result.GetBit(i));
	}
}

TEST(TestFunctions, BitwiseOR) {
	//Valid case

	bool first[32] = { 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0 };
	bool second[32] = { 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1 };
	bool expectedresult[32] = { 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1 };

	CBitField First(first, 32);
	CBitField Second(second, 32);
	CBitField ExpectedResult(expectedresult, 32);

	CBitField Result = First.BitwiseOR(Second);

	for (int i = 0; i < 32; ++i) {
		ASSERT_EQ(ExpectedResult.GetBit(i), Result.GetBit(i));
	}
}

TEST(TestFunctions, BitwiseXOR) {
	//Valid case

	bool first[32] = { 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0 };
	bool second[32] = { 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1 };
	bool expectedresult[32] = { 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1 };

	CBitField First(first, 32);
	CBitField Second(second, 32);
	CBitField ExpectedResult(expectedresult, 32);

	CBitField Result = First.BitwiseXOR(Second);

	for (int i = 0; i < 32; ++i) {
		ASSERT_EQ(ExpectedResult.GetBit(i), Result.GetBit(i));
	}
}