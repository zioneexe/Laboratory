#ifndef CLASS_HPP
#define CLASS_HPP

#include <iostream>
#include <cassert>
#include <cmath>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

using namespace std;

class CBitField
{
private:
	unsigned bits :32;
	static int count;
public:

	bool operator [] (int pos);
	CBitField& operator | (const CBitField & other);
	CBitField& operator & (const CBitField& other);
	CBitField& operator ^ (const CBitField & other);

	CBitField() : bits(0) { ++count; };
	CBitField(int value);
	CBitField(const bool array[], int len);
	CBitField(bool first_bits[16], bool last_bits[16]);
	void PrintField();
	void InverseField();
	void Getter(bool* array);
	void Setter();
	bool GetBit(int pos) const;
	void SetBit(int pos, bool bit);
	int NumOfTrueBits();
	CBitField BitwiseAND(CBitField & Operand);
	CBitField BitwiseOR(CBitField & Operand);
	CBitField BitwiseXOR(CBitField & Operand);
	static int GetCount() { return CBitField::count; }
	//--------------------------------------------------------
	void Setter(stringstream& ss);
	void Setter(string FILENAME);
	void Setter(bool bit);

	friend ostream& operator << (ostream& os, const CBitField& bf);
	friend istream& operator >> (istream& is, CBitField& bf);
	friend bool operator == (const CBitField& bf1, const CBitField& bf2);

};

#endif