#include "CTableUnq.hpp"

CTableUnq::CTableUnq() : rows(0), columns(0), data(nullptr), columnnames(nullptr) {}

CTableUnq::CTableUnq(int rows, int columns) {
	assert(columns > 0 && rows > 0);

	this->columns = columns;
	this->rows = rows;

	data = make_unique<unique_ptr<double[]>[]>(rows);

	for (int i = 0; i < rows; ++i) {
		data[i] = make_unique<double[]>(columns);
	}

	columnnames = make_unique<string[]>(columns);
	for (int i = 0; i < columns; ++i) {
		columnnames[i] = "Column" + to_string(i + 1);
	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			data[i][j] = 0;
		}
	}
}

CTableUnq::CTableUnq(int rows, int columns, string* names, int num) : CTableUnq(rows, columns) {

	for (int i = 0; i < columns; ++i) {
		if (i < num) {
			columnnames[i] = names[i];
		}
		else {
			columnnames[i] = "";
		}
	}
}

CTableUnq::CTableUnq(int rows, int columns, const string& defaultColumnName) : CTableUnq(rows, columns) {

	for (int i = 0; i < columns; i++) {
		columnnames[i] = defaultColumnName + to_string(i + 1);
	}

}

//конструктор копіювання
CTableUnq::CTableUnq(const CTableUnq& other) {

	columns = other.columns;
	rows = other.rows;

	data = make_unique<unique_ptr<double[]>[]>(rows);
	for (int i = 0; i < rows; i++) {
		data[i] = make_unique<double[]>(columns);
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

	columnnames = make_unique<string[]>(columns);

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
CTableUnq::CTableUnq(CTableUnq&& other) noexcept : CTableUnq(other.rows, other.columns) {
	data = move(other.data);
	columnnames = move(other.columnnames);

	other.data = nullptr;
	other.columnnames = nullptr;
	other.rows = 0;
	other.columns = 0;
}


CTableUnq::~CTableUnq()
{
}


int CTableUnq::getColumns() const {
	return columns;
}

string CTableUnq::getColumnName(int columnIndex) const {
	assert(columnIndex >= 0 && columnIndex < columns);

	return columnnames[columnIndex];
}

string CTableUnq::getColumnType(int columnIndex) const {
	assert(columnIndex >= 0 && columnIndex < columns);

	return typeid(data[0][columnIndex]).name();
}

int CTableUnq::getRows() const {
	return rows;
}

double CTableUnq::getValue(int rowIndex, int columnIndex) const {
	assert(rowIndex >= 0 && rowIndex < rows && columnIndex >= 0 && columnIndex < columns);

	return data[rowIndex][columnIndex];
}

void CTableUnq::setValue(int rowIndex, int columnIndex, const double& value) {
	assert(rowIndex >= 0 && rowIndex < rows && columnIndex >= 0 && columnIndex < columns);

	data[rowIndex][columnIndex] = value;
}

void CTableUnq::setColumnCount(int numColumns) {
	assert(numColumns >= 0);

	unique_ptr<unique_ptr<double[]>[]> newData = make_unique<unique_ptr<double[]>[]>(rows);
	for (int i = 0; i < rows; ++i) {
		newData[i] = make_unique<double[]>(numColumns);
	}

	for (int i = 0; i < numColumns; ++i) {
		for (int j = 0; j < rows; ++j) {
			newData[i][j] = data[i][j];
		}
	}

	data = move(newData);

	unique_ptr<string[]> newColumnNames = make_unique<string[]>(numColumns);

	for (int i = 0; i < min(columns, numColumns); ++i) {
		newColumnNames[i] = columnnames[i];
	}


	columnnames = move(newColumnNames);

	columns = numColumns;
}

void CTableUnq::setColumnName(int columnIndex, const string& columnName) {
	assert(columnIndex >= 0 && columnIndex < columns);

	columnnames[columnIndex] = columnName;
}

void CTableUnq::setRowCount(int numRows) {
	assert(numRows >= 0);

	unique_ptr<unique_ptr<double[]>[]> newData = make_unique<unique_ptr<double[]>[]>(numRows);
	for (int i = 0; i < numRows; ++i) {
		newData[i] = make_unique<double[]>(columns);
	}

	for (int i = 0; i < min(rows, numRows); ++i) {
		for (int j = 0; j < columns; ++j) {
			newData[i][j] = data[i][j];
		}
	}

	data = move(newData);

	rows = numRows;
}

void CTableUnq::clearTable() {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			columnnames[j] = "";
			data[i][j] = 0;
		}
	}
}

void CTableUnq::printTable() {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			cout << getValue(i, j) << "\t";
		}
		cout << endl;
	}
}

CTableUnq CTableUnq::operator+(const CTableUnq& other) const {
	if (columns == other.columns) {
		CTableUnq result(rows + other.rows, columns, columnnames.get(), columns);

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
		string* colNames = (columns > other.columns) ? columnnames.get() : other.columnnames.get();

		CTableUnq result(rows + other.rows, numColumns, colNames, numColumns);

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

CTableUnq CTableUnq::operator*(const CTableUnq& other) const {
	int newColumns = columns + other.columns;
	int newRows = rows * other.rows;
	CTableUnq Result(newRows, newColumns);

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

istream& operator>>(istream& is, CTableUnq& table) {
	is.ignore(6);
	is >> table.rows;
	
	is.ignore(11);
	is >> table.columns;

	is.ignore(9);
	table.columnnames = make_unique<string[]>(table.columns);
	for (int i = 0; i < table.columns; i++) {
		is >> table.columnnames[i];
	}

	table.data = make_unique<unique_ptr<double[]>[]>(table.rows);
	for (int i = 0; i < table.rows; i++) {
		table.data[i] = make_unique<double[]>(table.rows);
	}

	for (int i = 0; i < table.rows; i++) {
		for (int j = 0; j < table.columns; j++) {
			is >> table.data[i][j];
		}
	}

	return is;
}

ostream& operator<<(ostream& os, const CTableUnq& table) {

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
CTableUnq& CTableUnq::operator=(CTableUnq&& other) noexcept {
	if (this != &other) {
		columns = other.columns;
		rows = other.rows;

		data = move(other.data);
		columnnames = move(other.columnnames);

		other.data.reset();
		other.columnnames.reset();
		other.columns = 0;
		other.rows = 0;
	}
	return *this;
}

//оператор присвоєння
CTableUnq& CTableUnq::operator=(const CTableUnq& other) {
	if (this != &other) {

		columns = other.columns;
		rows = other.rows;

		data = make_unique<unique_ptr<double[]>[]>(rows);
		for (int i = 0; i < rows; i++) {
			data[i] = make_unique<double[]>(columns);
		}

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				data[i][j] = other.data[i][j];
			}
		}

		columnnames = make_unique<string[]>(columns);

		for (int i = 0; i < columns; i++) {
			columnnames[i] = other.columnnames[i];
		}
	}
	return *this;
}