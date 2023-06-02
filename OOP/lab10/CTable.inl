#ifndef CTABLE_INL
#define CTABLE_INL

#include "CTable.hpp"
#include "Exceptions.hpp"

template <typename T>
CTable<T>::CTable() noexcept : rows(0), columns(0), data(), columnnames() {}

template <typename T>
CTable<T>::CTable(int rows, int columns) {
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
		data.resize(rows);

		for (int i = 0; i < rows; ++i) {
			data[i].resize(columns);
		}

		columnnames.resize(columns);
		for (int i = 0; i < columns; ++i) {
			columnnames[i] = "Column" + to_string(i + 1);
		}

		for (auto row : data) {
			for (auto elem : row) {
				elem = T();
			}
		}

	}
	catch (const bad_alloc& ex) {
		cout << ex.what() << endl;
		return;
	}
}

template <typename T>
CTable<T>::CTable(int rows, int columns, vector<string>& names) noexcept : CTable(rows, columns) {

	for (int i = 0; i < columns; ++i) {
		if (i < names.size()) {
			columnnames.push_back(names[i]);
		}
		else {
			columnnames.push_back("");
		}
	}
}

template <typename T>
CTable<T>::CTable(int rows, int columns, const string& defaultColumnName) noexcept : CTable(rows, columns) {

	for (int i = 0; i < columns; i++) {
		columnnames.push_back(defaultColumnName + to_string(i + 1));
	}

}

//конструктор копіювання
template <typename T>
CTable<T>::CTable(const CTable& other) {

	columns = other.columns;
	rows = other.rows;

	try {
		data.resize(rows);
		for (int i = 0; i < rows; i++) {
			data[i].resize(columns);
		}

		for (int i = 0; i < rows; i++) {
			copy(other.data[i].begin(), other.data[i].end(), data[i].begin());
		}

		columnnames.resize(columns);
		copy(other.columnnames.begin(), other.columnnames.end(), columnnames.begin());

	}
	catch (const bad_alloc& ex) {
		cout << ex.what() << endl;
		return;
	}
}

//конструктор переміщення
template <typename T>
CTable<T>::CTable(CTable&& other) noexcept : CTable<T>(other.rows, other.columns) {
	data = move(other.data);
	columnnames = move(other.columnnames);

	other.data = {};
	other.columnnames = {};
	other.rows = 0;
	other.columns = 0;
}

template <typename T>
CTable<T>::~CTable() noexcept {}

template <typename T>
int CTable<T>::getColumns() const noexcept {
	return columns;
}

template <typename T>
string CTable<T>::getColumnName(int columnIndex) const {
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

template <typename T>
string CTable<T>::getColumnType(int columnIndex) const {
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

template <typename T>
int CTable<T>::getRows() const noexcept {
	return rows;
}

template <typename T>
T CTable<T>::getValue(int rowIndex, int columnIndex) const {

	try {
		if (rowIndex < 0 or rowIndex >= rows or columnIndex < 0 or columnIndex >= columns) {
			throw ValueOutOfRange();
		}
	}
	catch (const ValueOutOfRange& ex) {
		cout << ex.what() << endl;
		return T();
	}

	return data[rowIndex][columnIndex];
}

template <typename T>
void CTable<T>::setValue(int rowIndex, int columnIndex, const T& value) {
	try {
		if (typeid(T) != typeid(value)) {
			throw InvalidDataType();
		}
		if (rowIndex < 0 or rowIndex >= rows or columnIndex < 0 or columnIndex >= columns) {
			throw ValueOutOfRange();
		}
	}
	catch (const ValueOutOfRange& ex) {
		cout << ex.what() << endl;
		return;
	}
	catch (const InvalidDataType& ex) {
		cout << ex.what() << endl;
		return;
	}

	data[rowIndex][columnIndex] = value;
}

template <typename T>
void CTable<T>::setColumnCount(int numColumns) {
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
		vector<vector<T>> newData(rows, vector<T>(numColumns));

		for (int i = 0; i < rows; ++i) {
			copy(data[i].begin(), data[i].begin() + min(columns, numColumns), newData[i].begin());
		}
		data = move(newData);

		vector<string> newColumnNames(numColumns);
		copy(columnnames.begin(), columnnames.end(), newColumnNames.begin());
		columnnames = move(newColumnNames);

		columns = numColumns;
	}
	catch (const bad_alloc& ex) {
		cout << ex.what() << endl;
		return;
	}

}

template <typename T>
void CTable<T>::setColumnName(int columnIndex, const string& columnName) {
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

template <typename T>
void CTable<T>::setRowCount(int numRows) {
	try {
		if (numRows < 0) {
			throw logic_error("The number of rows must be greater or equal than 0!");
		}
	}
	catch (const logic_error& ex) {
		cout << ex.what() << endl;
	}

	try {
		vector<vector<T>> newData(numRows, vector<T>(columns));

		for (int i = 0; i < min(rows, numRows); ++i) {
			copy(data[i].begin(), data[i].end(), newData[i].begin());
		}
		data = move(newData);

		rows = numRows;
	}
	catch (const bad_alloc& ex) {
		cout << ex.what() << endl;
		return;
	}

}

template <typename T>
void CTable<T>::clearTable() noexcept {
	data.clear();
	columnnames.clear();
}

template <typename T>
void CTable<T>::printTable() const noexcept {
	cout << endl << "Your table: " << endl;
	for (const auto& row : data) {
		for (const auto& elem: row) {
			cout << elem << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

//-----------------------------------------------------------------------------------------------

template <typename T>
void CTable<T>::reverseColumns() noexcept{
	reverse(columnnames.begin(), columnnames.end());
	for (auto& row : data) {
		reverse(row.begin(), row.end());
	}
}

template <typename T>
vector<vector<string>> CTable<T>::getValuesString() noexcept {
	vector<vector<string>> outputData(rows+1, vector<string>(columns));

	copy(columnnames.begin(), columnnames.end(), outputData[0].begin());

	for (auto row : data) {
		vector<string> stringRow;
		for (auto element : row) {
			stringRow.push_back(ConvertToString(element));
		}
		outputData.push_back(stringRow);
	}

	return outputData;
}

//-----------------------------------------------------------------------------------------------

template <typename T>
bool CTable<T>::isEmpty() const {
	bool check = data.empty();
	
	if (check) {
		throw OStreamError();
	}
	
	return check;
}

template <typename T>
void CTable<T>::addColumn(int columnIndex, const string& columnName, initializer_list<T> list) {
	if (columnIndex < 0 || columnIndex >= columns) {
		throw ColIndexOutOfRange();
	}

	if (list.size() != columns) {
		throw invalid_argument("Number of elements in initializer list differs from the number of columns");
	}

	auto it = list.begin();
	for (auto& row : data) {
		row.insert(row.begin() + columnIndex, *it);
		++it;
	}

	vector<string>::iterator it = columnnames.begin();
	advance(it, columnIndex);
	columnnames.insert(it, columnName);
}

template <typename T>
void CTable<T>::addRow(int rowIndex, initializer_list<T> list) {
	if (rowIndex < 0 || rowIndex >= rows) {
		throw RowIndexOutOfRange();
	}

	if (list.size() != rows) {
		throw invalid_argument("Number of elements in initializer list differs from the number of rows");
	}

	data.insert(data.begin() + rowIndex, vector<T>(list));
}

template <typename T>
void CTable<T>::delColumn(int columnIndex) {
	try {
		if (columnIndex < 0 or columnIndex >= columns) {
			throw ColIndexOutOfRange();
		}
	}
	catch (const ColIndexOutOfRange& ex) {
		cout << ex.what() << endl;
		return "";
	}

	columnnames.erase(columnIndex);
	for (auto& row : data) {
		row.erase(columnIndex);
	}
}

template <typename T>
void CTable<T>::delRow(int rowIndex) {
	try {
		if (rowIndex < 0 or rowIndex >= rows) {
			throw RowIndexOutOfRange();
		}
	}
	catch (const RowIndexOutOfRange& ex) {
		cout << ex.what() << endl;
		return "";
	}

	data.erase(rowIndex);
}

template <typename T>
CTable<T> CTable<T>::operator+(const CTable<T>& other) const {
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
		CTable result(rows + other.rows, columns, columnnames);

		for (int i = 0; i < rows; ++i) {
			copy(data[i].begin(), data[i].end(), result.data[i].begin());
		}

		for (int i = 0; i < other.rows; ++i) {
			copy(other.data[i].begin(), other.data[i].end(), result.data[rows + i].begin());
		}

		return result;
	}
}

template <typename T>
CTable<T> CTable<T>::operator*(const CTable<T>& other) const {

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
	CTable result(newRows, newColumns);

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < other.rows; ++j) {
			copy(data[i].begin(), data[i].end(), result.data[(i * other.rows) + j].begin());
			copy(other.data[j].begin(), other.data[j].end(), result.data[(i * other.rows) + j].begin() + columns);
		}
	}

	return result;
}

template <typename T2>
istream& operator>>(istream& is, CTable<T2>& table) {
	IStreamError obj;

	is.ignore(6);
	is >> table.rows;

	is.ignore(11);
	is >> table.columns;

	is.ignore(9);

	try {
		table.columnnames.resize(table.columns);

		for (auto it = table.columnnames.begin(); it != table.columnnames.end(); ++it) {
			if (obj.isString(*it)) {
				throw IStreamError();
				break;
			}
			is >> *it;
		}

		table.data.resize(table.rows);
		
		for (int i = 0; i < table.rows; i++) {
			table.data[i].resize(table.rows);
		}

		for_each(table.data.begin(), table.data.end(), [&](const vector<T2>& row) {
			for_each(row.begin(), row.end(), [&](const T2& elem) {
				is >> elem;
			});
		});
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

template <typename T2>
ostream& operator<<(ostream& os, const CTable<T2>& table) {
	OStreamError obj;

	os << "Rows: " << table.rows << ", Columns: " << table.columns << endl;

	os << "Table:" << endl << endl;

	try {
		table.isEmpty();

		for_each(table.columnnames.begin(), table.columnnames.end(), [&](const string& colName) {
			if (!obj.isString(colName)) {
				throw OStreamError();
			}
			os << colName << " ";
		});
		os << endl;

		for_each(table.data.begin(), table.data.end(), [&](const vector<T2>& row) {
			for_each(row.begin(), row.end(), [&](const T2& value) {
				os << value << " ";
			});
			os << endl;
		});
	}
	catch (const OStreamError& ex) {
		cout << ex.what() << endl;
		return os;
	}

	return os;
}

//оператор порівняння
template <typename T2>
bool operator == (CTable<T2>& t1, CTable<T2>& t2) noexcept{
	return t1.rows == t2.rows && t1.columns == t2.columns && equal(t1.data.begin(), t1.data.end(), t2.data.begin());
}

//оператор переміщення
template <typename T>
CTable<T>& CTable<T>::operator=(CTable<T>&& other) noexcept {
	if (this != &other) {
		columns = other.columns;
		rows = other.rows;

		data = move(other.data);
		columnnames = move(other.columnnames);

		other.columns = 0;
		other.rows = 0;
	}
	return *this;
}

//оператор присвоєння
template <typename T>
CTable<T>& CTable<T>::operator=(const CTable<T>& other) {
	if (this != &other) {

		columns = other.columns;
		rows = other.rows;

		try {
			data.resize(rows);

			for (int i = 0; i < rows; i++) {
				data[i].resize(columns);
			}

			data = other.data;

			columnnames.resize(columns);

			columnnames = other.columnnames;
		}
		catch (const bad_alloc& ex) {
			cout << ex.what() << endl;
			return *this;
		}
	}

	return *this;
}

template <typename T>
int FindElementInArray(vector<T>& Vector, T& Elem) noexcept {
	typename vector<T>::iterator it;
	int index = 0;
	
	for (it = Vector.begin(); it != Vector.end(); ++it, ++index) {
		if (*it == Elem) {
			cout << endl << "The element is found! Index returned.";
			return index;
		}
	}

	cout << endl << "The element is not found. Array size returned instead. ";
	return Vector.size();
}

template <typename T>
string ConvertToString(const T& value) noexcept{
	ostringstream oss;
	oss << value;
	return oss.str();
}

template <typename T>
void TestingTable(CTable<T> table) {
	cout << "Creating a(an) [" << typeid(table).name() << "] type table..." << endl;
	cout << endl << "Now you are able to fill the table." << endl;

	for (int i = 0; i < table.getRows(); ++i) {
		for (int j = 0; j < table.getColumns(); ++j) {
			T val = T();
			bool flag;
			do {
				try {
					flag = false;
					cin >> val;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(32767, '\n');
						throw InvalidDataType();
					}
					else {
						table.setValue(i, j, val);
					}
				}
				catch (InvalidDataType& ex) {
					cout << ex.what() << endl;
					flag = true;
				}
			} while (flag);
		}
	}

	table.printTable();

	int choice = 0;
	string _choice;

	do {
		cout << endl << endl << "Choose your option.\n1. Work with the table.\n2. Create the vector of OTHER tables and test FindElementInArray function.\n3. Clear the table.\n4. Move back to menu." << endl;
		//cout << endl << endl << "Choose your option.\n1. Work with the table.\n2. Create the vector of OTHER tables and test FindElementInArray function.\n3. Clear the table.\n4. New features\n5. Move back to menu." << endl;

		int flag = 0;

		IStreamError err;
		cout << "// ";
		cin >> _choice;

		try {
			err.isDigit(_choice);
		}
		catch (const IStreamError& ex) {
			cout << ex.what() << endl;
			flag = 1;
		}

		if (flag) continue;
		choice = stoi(_choice);

		try {
			if (choice != 1 and choice != 2 and choice != 3 and choice != 4) {
				throw logic_error("Incorrect choice.");
			}
		}
		catch (const logic_error& ex) {
			cout << ex.what() << endl;
		}


		switch (choice) {
		case 1:
		{
			cout << endl << "Rows: " << table.getRows() << " Columns: " << table.getColumns() << endl;
			T val2 = T();
			string name;
			int pos, i, j;
			cout << endl << "Enter new column name: " << endl;
			cin >> name;
			cout << endl << "Choose position: " << endl;
			cin >> pos;
			cout << "Col name: " << table.getColumnName(pos) << endl;
			table.setColumnName(pos, name);
			cout << "Col name: " << table.getColumnName(pos) << endl;

			cout << endl << "Choose row and col indexes (i and j): " << endl;
			cin >> i >> j;
			cout << "Value: " << table.getValue(i, j) << endl;

			cout << endl << "Enter new value: " << endl;
			bool flag2;
			do {
				try {
					flag2 = false;
					cin >> val2;
					if (cin.fail()) {
						cin.clear();
						cin.ignore(32767, '\n');
						throw InvalidDataType();
					}
					else {
						table.setValue(i, j, val2);
					}
				}
				catch (InvalidDataType& ex) {
					cout << ex.what() << endl;
					flag2 = true;
				}
				cout << endl << "Table with the value changed: " << endl;
				table.printTable();
				cout << endl << "Reversing columns of the table... " << endl;
				table.reverseColumns();
				table.printTable();
				cout << endl << "Getting string of values: [" << endl;
				vector<vector<string>> Values = table.getValuesString();
				for (const auto& row : Values) {
					for (const auto& elem : row) {
						cout << elem << "\t";
					}
				}
				cout << "]" << endl;
 
			} while (flag2);

			cout << "Value: " << table.getValue(i, j) << endl;
			table.printTable();
		}
		case 2:
		{
			cout << "Testing FindElementInArray function." << endl;
			cout << "creating the vector with CTable objects.." << endl;
			vector<CTable<T>> vec;
			CTable<T> a, b(1, 2), c(3, 5), d(2, 1);
			vec.emplace_back(a);
			vec.emplace_back(b);
			vec.emplace_back(c);
			vec.emplace_back(d);

			CTable<T> elem1(2, 1);
			CTable<T> elem2(6, 7);
			int result1 = FindElementInArray(vec, elem1);
			cout << endl << "The result of function call is : " << result1 << endl;
			int result2 = FindElementInArray(vec, elem2);
			cout << endl << "The result of function call is : " << result2 << endl;
			break;
		}
		case 3:
		{
			table.clearTable();
			cout << endl << "The table is cleansed." << endl;
			table.printTable();
			break;
		}
		//case 4:
		//{
		//	CTable<int> table;
		//	cout << table;
		//	table.addColumn(2, "newCol", {2,4,5,9});
		//	table.addRow(0, { 1,2,3 });
		//	cout << table;
		//}
		}
	} while (choice != 4);
}

#endif