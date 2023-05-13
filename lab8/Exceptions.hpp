#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <typeinfo>
#include <iostream>

class IStreamError : public std::exception {
public:
	const char* what() const noexcept override {
		return "Input stream error occured!";
	}

	bool isDouble(const double& value) {
		return typeid(value)==typeid(double);
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

class OStreamError : public std::exception {
public:
	const char* what() const noexcept override {
		return "Output stream error occured!";
	}

	bool isDouble(const double& value) {
		return typeid(value) == typeid(double);
	}

	bool isString(const string& value) {
		return typeid(value) == typeid(string);
	}
	
	bool isEmptyTable(CTable& t) {
		if (!t.getRows() && !t.getColumns()) {
			throw OStreamError();
			return true;
		}
		else return false;
	}
};

class ColNameOutOfRange : public std::exception {
public:
	const char* what() const noexcept override {
		return "Cannot access the column name out of the table range!";
	}
};

class ColTypeOutOfRange : public std::exception {
public:
	const char* what() const noexcept override {
		return "Cannot access the column type out of the table range!";
	}
};

class ValueOutOfRange : public std::exception {
public:
	const char* what() const noexcept override {
		return "Cannot access the element out of the table range!";
	}
};

class DiffColumnsNumAddition : public std::exception {
public:
	const char* what() const noexcept override {
		return "Cannot UNION ALL tables with different number of columns!";
	}
};

class ZeroColMultiplication : public std::exception {
public:
	const char* what() const noexcept override {
		return "Cannot CROSS JOIN table with zero columns!";
	}
};

#endif