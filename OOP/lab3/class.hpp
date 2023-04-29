#ifndef CLASS_HPP
#define CLASS_HPP

#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

class CBitField
{
private:
	unsigned bits :32;
public:
	CBitField() : bits(0) {};
	CBitField(int value);
	CBitField(const bool * array, int len);
	CBitField(bool first_bits[16], bool last_bits[16]);
	void PrintField();
	void InverseField();
	void Getter(bool* array);
	void Setter();
	bool GetBit(int pos);
	void SetBit(int pos, bool bit);
	int NumOfTrueBits();
	CBitField BitwiseAND(CBitField & Operand);
	CBitField BitwiseOR(CBitField & Operand);
	CBitField BitwiseXOR(CBitField & Operand);
};

#endif