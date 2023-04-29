#include "CTable.hpp"

CTable::CTable() : rows(0), columns(0), data(nullptr), columnnames(nullptr) {}

CTable::CTable(int rows, int columns) {
	assert(columns >= 0 && rows >= 0);

	this->columns = columns;
	this->rows = rows;

	data = new double* [rows];

	for (int i = 0; i < rows; ++i) {
		data[i] = new double[columns];
	}

	columnnames = new string[columns];

	for (int i = 0; i < columns; ++i) {
		columnnames[i] = "Column" + to_string(i + 1);
	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			data[i][j] = 0;
		}
	}
}

CTable::CTable(int rows, int columns, string *names, int num) : CTable(rows, columns) {

	for (int i = 0; i < columns; ++i) {
		if (i < num) {
			columnnames[i] = names[i];
		}
		else {
			columnnames[i] = "";
		}
	}
}

CTable::CTable(int rows, int columns, const string& defaultColumnName) : CTable(rows, columns) {

	for (int i = 0; i < columns; i++) {
		columnnames[i] = defaultColumnName + to_string(i + 1);
	}
}

//конструктор копіювання
CTable::CTable(const CTable& other) {
	columns = other.columns;
	rows = other.rows;

	data = new double* [rows];
	for (int i = 0; i < rows; i++) {
		data[i] = new double[columns];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (i < other.rows && j < other.columns) {
				data[i][j] = other.data[i][j];
			}
			else {
				data[i][j] = 0;
			}
		}
	}

	columnnames = new string[columns];

	for (int i = 0; i < columns; i++) {
		if (i < other.columns) {
			columnnames[i] = other.columnnames[i];
		}
		else {
			columnnames[i] = "";
		}
	}
}

//конструктор переміщення
CTable::CTable(CTable&& other) noexcept : CTable(other.rows, other.columns ) {
	data = move(other.data);
	columnnames = move(other.columnnames);

	other.data = nullptr;
	other.columnnames = nullptr;
	other.rows = 0;
	other.columns = 0;
}


CTable::~CTable()
{
	if (data != nullptr) {
		for (int i = 0; i < rows; ++i) {
			delete[] data[i];
		}
		delete[] data;
	}

	if (columnnames != nullptr) {
		delete[] columnnames;
	}
}

int CTable::getColumns() const {
	return columns;
}

string CTable::getColumnName(int columnIndex) const {
	assert(columnIndex >= 0 && columnIndex < columns);

	return columnnames[columnIndex];
}

string CTable::getColumnType(int columnIndex) const {
	assert(columnIndex >= 0 && columnIndex < columns);

	return typeid(data[0][columnIndex]).name();
}

int CTable::getRows() const {
	return rows;
}

double CTable::getValue(int rowIndex, int columnIndex) const {
	assert(rowIndex >= 0 && rowIndex < rows && columnIndex >= 0 && columnIndex < columns);

	return data[rowIndex][columnIndex];
}

void CTable::setValue(int rowIndex, int columnIndex, const double& value) {
	assert(rowIndex >= 0 && rowIndex < rows && columnIndex >= 0 && columnIndex < columns);

	data[rowIndex][columnIndex] = value;
}

void CTable::setColumnCount(int numColumns) {
	assert(numColumns >= 0);

	double** newData = new double* [rows];
	for (int i = 0; i < rows; ++i) {
		newData[i] = new double[numColumns];
	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < numColumns; ++j) {
			newData[i][j] = data[i][j];
		}
	}


	for (int i = 0; i < rows; i++) {
		delete[] data[i];
	}
	delete[] data;

	data = newData;

	string* newColumnNames = new string[numColumns];

	for (int i = 0; i < min(columns, numColumns); ++i) {
		newColumnNames[i] = columnnames[i];
	}

	delete[] columnnames;

	columnnames = newColumnNames;

	columns = numColumns;
}

void CTable::setColumnName(int columnIndex, const string& columnName) {
	assert(columnIndex >= 0 && columnIndex < columns);

	columnnames[columnIndex] = columnName;
}

void CTable::setRowCount(int numRows) {
	assert(numRows >= 0);

	double** newData = new double* [numRows];
	for (int i = 0; i < numRows; ++i) {
		newData[i] = new double[columns];
	}

	for (int i = 0; i < min(rows, numRows); ++i) {
		for (int j = 0; j < columns; ++j) {
			newData[i][j] = data[i][j];
		}
	}

	for (int i = 0; i < rows; i++) {
		delete[] data[i];
	}
	delete[] data;

	data = newData;

	rows = numRows;
}

void CTable::clearTable() {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			columnnames[j] = "";
			data[i][j] = 0;
		}
	}
}

void CTable::printTable() {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			cout << getValue(i, j) << "\t";
		}
		cout << endl;
	}
}

CTable CTable::operator+(const CTable& other) const {
	if (columns == other.columns) {
		CTable result(rows + other.rows, columns, columnnames, columns);

		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				result.data[i][j] = data[i][j];
			}
		}

		for (int i = 0; i < other.rows; ++i) {
			for (int j = 0; j < other.columns; ++j) {
				result.data[rows + i][j] = other.data[i][j];
			}
		}

		return result;
	}

	else {
		int numColumns = (columns > other.columns) ? columns : other.columns;
		string* colNames = (columns > other.columns) ? columnnames : other.columnnames;

		CTable result(rows + other.rows, numColumns, colNames, numColumns);

		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				result.data[i][j] = data[i][j];
			}
		}

		for (int i = 0; i < other.rows; ++i) {
			for (int j = 0; j < other.columns; ++j) {
				result.data[rows + i][j] = other.data[i][j];
			}
		}

		return result;
	}
}

CTable CTable::operator*(const CTable& other) const {
	int newColumns = columns + other.columns;
	int newRows = rows * other.rows;
	CTable Result(newRows, newColumns);

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			for (int k = 0; k < other.rows; ++k) {
				Result.setValue(i * other.rows + k, j, data[i][j]);
			}
		}
	}

	for (int i = 0; i < other.rows; ++i) {
		for (int j = 0; j < other.columns; ++j) {
			for (int k = 0; k < rows; ++k) {
				Result.setValue(k * other.rows + i, columns + j, other.data[i][j]);
			}
		}
	}

	return Result;
}

istream& operator>>(istream& is, CTable& table) {
	is.ignore(6);
	is >> table.rows;
	
	is.ignore(11);
	is >> table.columns;

	is.ignore(9);
	table.columnnames = new string[table.columns];
	for (int i = 0; i < table.columns; i++) {
		is >> table.columnnames[i];
	}

	table.data = new double* [table.rows];
	for (int i = 0; i < table.rows; i++) {
		table.data[i] = new double[table.columns];
	}

	for (int i = 0; i < table.rows; i++) {
		for (int j = 0; j < table.columns; j++) {
			is >> table.data[i][j];
		}
	}

	return is;
}

ostream& operator<<(ostream& os, const CTable& table) {

	os << "Rows: " << table.rows << ", Columns: " << table.columns << endl;

	os << "Table:" << endl << endl;

	for (int i = 0; i < table.columns; ++i) {
		os << table.columnnames[i] << " ";
	}
	os << endl;

	for (int i = 0; i < table.rows; ++i) {
		for (int j = 0; j < table.columns; ++j) {
			os << table.data[i][j] << " ";
		}
		os << endl;
	}

	return os;
}

//оператор переміщення
CTable& CTable::operator=(CTable&& other) noexcept {
	if (this != &other) {
		if (data != nullptr) {
			for (int i = 0; i < rows; i++) {
				delete[] data[i];
			}
			delete[] data;
		}
		if (columnnames != nullptr) {
			delete[] columnnames;
		}

		columns = other.columns;
		rows = other.rows;

		data = other.data;
		columnnames = other.columnnames;

		other.data = nullptr;
		other.columnnames = nullptr;
		other.columns = 0;
		other.rows = 0;
	}
	return *this;
}

//оператор присвоєння
CTable& CTable::operator=(const CTable & other) {
	if (this != &other) {
		if (data != nullptr) {
			for (int i = 0; i < rows; i++) {
				delete[] data[i];
			}
			delete[] data;
		}
		if (columnnames != nullptr) {
			delete[] columnnames;
		}

		columns = other.columns;
		rows = other.rows;

		data = new double* [rows];
		for (int i = 0; i < rows; i++) {
			data[i] = new double[columns];
		}

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				data[i][j] = other.data[i][j];
			}
		}

		columnnames = new string[columns];

		for (int i = 0; i < columns; i++) {
			columnnames[i] = other.columnnames[i];
		}
	}
	return *this;
}