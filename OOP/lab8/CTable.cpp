#include "CTable.hpp"
#include "Exceptions.hpp"

CTable::CTable() noexcept : rows(0), columns(0), data(nullptr), columnnames(nullptr) {}

CTable::CTable(int rows, int columns) {
	try {
		if (columns < 0 or rows < 0) {
			throw logic_error("The number of rows and columns must be greater or equal than 0!");
			return;
		}
	}
	catch (const logic_error& ex) {
		cout << ex.what() << endl;
	}

	this->columns = columns;
	this->rows = rows;

	try {
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
	catch (const bad_alloc& ex) {
		cout << ex.what() << endl;
	}
}

CTable::CTable(int rows, int columns, string* names, int num) noexcept : CTable(rows, columns) {

	for (int i = 0; i < columns; ++i) {
		if (i < num) {
			columnnames[i] = names[i];
		}
		else {
			columnnames[i] = "";
		}
	}
}

CTable::CTable(int rows, int columns, const string& defaultColumnName) noexcept : CTable(rows, columns) {

	for (int i = 0; i < columns; i++) {
		columnnames[i] = defaultColumnName + to_string(i + 1);
	}

}

//конструктор копіювання
CTable::CTable(const CTable& other) {


	columns = other.columns;
	rows = other.rows;

	try {
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
	catch (const bad_alloc& ex) {
		cout << ex.what() << endl;
		return;
	}
}

//конструктор переміщення
CTable::CTable(CTable&& other) noexcept : CTable(other.rows, other.columns) {
	data = move(other.data);
	columnnames = move(other.columnnames);

	other.data = nullptr;
	other.columnnames = nullptr;
	other.rows = 0;
	other.columns = 0;
}


CTable::~CTable() noexcept
{
}


int CTable::getColumns() const noexcept {
	return columns;
}

string CTable::getColumnName(int columnIndex) const {
	try {
		if (columnIndex < 0 or columnIndex >= columns) {
			throw ColNameOutOfRange();
		}
	}
	catch (const ColNameOutOfRange& ex) {
		cout << ex.what() << endl;
		return "";
	}

	return columnnames[columnIndex];
}

string CTable::getColumnType(int columnIndex) const {
	try {
		if (columnIndex < 0 or columnIndex >= columns) {
			throw ColTypeOutOfRange();
		}
	}
	catch (const ColTypeOutOfRange& ex) {
		cout << ex.what() << endl;
		return "";
	}

	return typeid(data[0][columnIndex]).name();
}

int CTable::getRows() const noexcept {
	return rows;
}

double CTable::getValue(int rowIndex, int columnIndex) const {

	try {
		if (rowIndex < 0 or rowIndex >= rows or columnIndex < 0 or columnIndex >= columns) {
			throw ValueOutOfRange();
		}
	}
	catch (const ValueOutOfRange& ex) {
		cout << ex.what() << endl;
		return 0;
	}

	return data[rowIndex][columnIndex];
}

void CTable::setValue(int rowIndex, int columnIndex, const double& value) {
	try {
		if (rowIndex < 0 or rowIndex >= rows or columnIndex < 0 or columnIndex >= columns) {
			throw ValueOutOfRange();
		}
	}
	catch (const ValueOutOfRange& ex) {
		cout << ex.what() << endl;
		return;
 	}

	data[rowIndex][columnIndex] = value;
}

void CTable::setColumnCount(int numColumns) {
	try {
		if (numColumns < 0) {
			throw logic_error("The number of columns must be greater or equal than 0!");
		}
	}
	catch (const logic_error& ex) {
		cout << ex.what() << endl;
		return;
	}

	try {
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
	catch (const bad_alloc& ex) {
		cout << ex.what() << endl;
	}

}

void CTable::setColumnName(int columnIndex, const string& columnName) {
	try {
		if (columnIndex < 0 or columnIndex >= columns) {
			throw ColNameOutOfRange();
		}
	}
	catch (ColNameOutOfRange& ex) {
		cout << ex.what() << endl;
		return;
	}

	columnnames[columnIndex] = columnName;
}

void CTable::setRowCount(int numRows) {
	try {
		if (numRows < 0) {
			throw logic_error("The number of rows must be greater or equal than 0!");
		}
	}
	catch (const logic_error& ex) {
		cout << ex.what() << endl;
	}

	try {
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
	catch (const bad_alloc& ex) {
		cout << ex.what() << endl;
	}

}

void CTable::clearTable() noexcept {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			columnnames[j] = "";
			data[i][j] = 0;
		}
	}
}

void CTable::printTable() noexcept{
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			cout << getValue(i, j) << "\t";
		}
		cout << endl;
	}
}

CTable CTable::operator+(const CTable& other) const {
	try {
		if (columns != other.columns) {
			throw DiffColumnsNumAddition();
		}
	}
	catch (const DiffColumnsNumAddition& ex) {
		cout << ex.what() << endl;
		return *this;
	}
	
	if (columns == other.columns) {
		CTable result(rows + other.rows, columns, columnnames.get(), columns);

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
	
	try {
		if (columns == 0 or other.columns == 0) {
			throw ZeroColMultiplication();
		}
	}
	catch (ZeroColMultiplication& ex) {
		cout << ex.what() << endl;
		return *this;
	}

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
	IStreamError obj;

	is.ignore(6);
	is >> table.rows;

	is.ignore(11);
	is >> table.columns;

	is.ignore(9);

	try {
		table.columnnames = make_unique<string[]>(table.columns);

		for (int i = 0; i < table.columns; i++) {
			if (obj.isString(table.columnnames[i])) {
				throw IStreamError();
				break;
			}
			is >> table.columnnames[i];
		}

		table.data = make_unique<unique_ptr<double[]>[]>(table.rows);
		for (int i = 0; i < table.rows; i++) {
			table.data[i] = make_unique<double[]>(table.rows);
		}

		for (int i = 0; i < table.rows; i++) {
			for (int j = 0; j < table.columns; j++) {
				if (obj.isDouble(table.data[i][j])) {
					throw IStreamError();
					break;
				}
				is >> table.data[i][j];
			}
		}
	}
	catch (const bad_alloc& ex) {
		cout << ex.what() << endl;
		return is;
	}
	catch (const IStreamError& ex) {
		cout << ex.what() << endl;
		return is;
	}


	return is;
}

ostream& operator<<(ostream& os, const CTable& table) {
	OStreamError obj;

	os << "Rows: " << table.rows << ", Columns: " << table.columns << endl;

	os << "Table:" << endl << endl;

	try {
		for (int i = 0; i < table.columns; ++i) {
			if (obj.isString(table.columnnames[i])) {
				throw OStreamError();
				break;
			}
			os << table.columnnames[i] << " ";
		}
		os << endl;

		for (int i = 0; i < table.rows; ++i) {
			for (int j = 0; j < table.columns; ++j) {
				if (obj.isDouble(table.data[i][j])) {
					throw OStreamError();
					break;
				}
				os << table.data[i][j] << " ";
			}
			os << endl;
		}
	}
	catch (OStreamError& ex) {
		cout << ex.what() << endl;
		return os;
	}

	return os;
}

//оператор переміщення
CTable& CTable::operator=(CTable&& other) noexcept {
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
CTable& CTable::operator=(const CTable& other) {
	if (this != &other) {

		columns = other.columns;
		rows = other.rows;

		try {
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
		catch (const bad_alloc& ex) {
			cout << ex.what() << endl;
			return *this;
		}
	}

	return *this;
}