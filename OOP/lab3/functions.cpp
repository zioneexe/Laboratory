#include "class.hpp"
	
CBitField::CBitField(int value) {
	bits = 0;
	bool isNegative = value < 0;

	int pos = 0;
	if (value == 1) { 
		SetBit(0, 1);
		return;
	}
	if (isNegative) {
		value = abs(value) - 1;
		SetBit(pos, 1);
	}
	
	while (value > 0) {
		if (value % 2) {
			SetBit(pos, 1);
		}
		++pos;
		value /= 2;
	}

	if (isNegative) {
		InverseField();
	}
}
	
CBitField::CBitField(const bool * array, int len) {
	bits = 0;
	assert(len > 0 && len <= 32);
	for (int i = 0; i < len ; ++i) {
		if (array[i]) {
			SetBit(i, 1);
		}
		else { SetBit(i, 0); }
	}
}

CBitField::CBitField(bool first_bits[16], bool last_bits[16]) {
	bits = 0;
	for (int i = 0; i < 16; ++i) {
		if (first_bits[i]) {
			SetBit(i, 1);
		}
	}
	for (int i = 16; i<32; ++i) {
		for (int j = 0; j < 16; ++j) {
			if (last_bits[j]) {
				SetBit(i,1);
			}
		}
	}
}
	
void CBitField::Setter() {
	bits = 0;
	bool bit;
	for (int i = 0; i < 32; ++i) {
		cin >> bit;
		if (bit) {
			SetBit(i, 1);
		}
		else { SetBit(i, 0); }
	}
}
	
void CBitField::Getter(bool * array) {
	for (int i = 0; i < 32; ++i) {
		array[i] = GetBit(i);
	}
}
	
bool CBitField::GetBit(int pos) {
	assert(pos >= 0 && pos <= 32);
	return (bits >> pos) & 1;
}

void CBitField::SetBit(int pos, bool bit) {
	assert(pos >= 0 && pos <= 32);
	if (bit) {
		bits |= (1 << pos);
	}
	else {
		bits &= ~(1 << pos);
	}
}

int CBitField::NumOfTrueBits() {
	int cnt = 0, mask = 1;
		
	for (int i = 0; i < 32; ++i) {
		if (bits & mask) {
			++cnt;
		}
		mask <<= 1;
	}
		
	return cnt;
}

CBitField CBitField::BitwiseAND(CBitField &Operand) {
		
	CBitField Result;
		
	for (int i = 0; i < 32; ++i) {
		if (this->GetBit(i) == 1 && Operand.GetBit(i) == 1) {
			Result.SetBit(i, 1);
		}
		else Result.SetBit(i, 0);
	}

	return Result;
}

CBitField CBitField::BitwiseOR(CBitField & Operand) {
	CBitField Result;

	for (int i = 0; i < 32; ++i) {
		if (this->GetBit(i) == 1 || Operand.GetBit(i) == 1) {
			Result.SetBit(i, 1);
		}
		else Result.SetBit(i, 0);
	}

	return Result;
}

CBitField CBitField::BitwiseXOR(CBitField & Operand) {
	CBitField Result;

	for (int i = 0; i < 32; ++i) {
		if (this->GetBit(i) == Operand.GetBit(i)) {
			Result.SetBit(i, 0);
		}
		else Result.SetBit(i, 1);
	}

	return Result;
}

void CBitField::PrintField() {
	for (int i = 0; i < 32; ++i) {
		cout << GetBit(i) << " ";
	}
	cout << endl;
}

void CBitField::InverseField() {
	for (int i = 0; i < 32; ++i) {
		bool bit = GetBit(i);
		SetBit(i, bit ? 0 : 1);
	}
}