#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <stdexcept>
#include <typeinfo>
#include <iostream>

using namespace std;

class IStreamError : public exception {
public:
	const char* what() const noexcept override {
		return "Input stream error occured!";
	}

	bool isString(const string& value) {
		return typeid(value) == typeid(string);
	}

	void isDigit(const string& value) {
		if (!isdigit(value[0]) && value[0] != '-') {
			throw IStreamError();
		}

		for (int i = 1; i < value.length(); ++i) {
			if (!isdigit(value[i])) {
				throw IStreamError();
			}
		}
	}
};

class OStreamError : public exception {
public:
	const char* what() const noexcept override {
		return "Output stream error occured!";
	}

	bool isString(const string& value) {
		return typeid(value) == typeid(string);
	}
};

class ColNameOutOfRange : public exception {
public:
	const char* what() const noexcept override {
		return "Cannot access the column name out of the table range!";
	}
};

class ColTypeOutOfRange : public exception {
public:
	const char* what() const noexcept override {
		return "Cannot access the column type out of the table range!";
	}
};

class ValueOutOfRange : public exception {
public:
	const char* what() const noexcept override {
		return "Cannot access the element out of the table range!";
	}
};

class RowIndexOutOfRange : public exception {
public:
	const char* what() const noexcept override {
		return "This row index is out of the table range!";
	}
};

class ColIndexOutOfRange : public exception {
public:
	const char* what() const noexcept override {
		return "This column index is out of the table range!";
	}
};

class DiffColumnsNumAddition : public exception {
public:
	const char* what() const noexcept override {
		return "Cannot UNION ALL tables with different number of columns!";
	}
};

class ZeroColMultiplication : public exception {
public:
	const char* what() const noexcept override {
		return "Cannot CROSS JOIN table with zero columns!";
	}
};

class InvalidDataType : public exception {
public:
	const char* what() const noexcept override {
		return "Invalid data type!";
	}
};

#endif