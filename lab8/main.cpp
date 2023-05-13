#include "CTable.hpp"
#include "Exceptions.hpp"

int main() {

	cout << endl << "Interactive program" << endl;
	cout << endl << "//exception caller" << endl;
	cout << endl << "...to get input stream error write a random option" << endl << endl;

	int choice = 0;
	string _choice;

	do {
		int flag = 0;

		cout << "Enter your choice: " << endl;
		cout << "1 ----------> memory issues" << endl;
		cout << "2 ----------> error getting or setting column name" << endl;
		cout << "3 ----------> error getting column type" << endl;
		cout << "4 ----------> error getting or setting table value" << endl;
		cout << "5 ----------> error adding tables with diff col number" << endl;
		cout << "6 ----------> error multiplying table with zero columns" << endl;
		cout << "7 ----------> output stream error" << endl;
		cout << "8 ----------> exit" << endl;
		
		IStreamError err;
		cout << "// ";
		cin >> _choice;
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
			if (choice != 1 and choice != 2 and choice != 3 and choice != 4 and choice != 5
				and choice != 6 and choice != 7 and choice != 8 ) {
				throw logic_error("Incorrect choice.");
			}
		}
		catch (const logic_error& ex) {
			cout << ex.what() << endl;
		}


		switch (choice) {
		case 1:
			cout << "Trying to create an array of 100000000000 CTable objects." << endl;
			try {
				int size = 10000000000000000000;
				CTable* arr = new CTable[size];
				delete [] arr;
			}
			catch (const bad_alloc& ex) {
				cout << endl << "Error: " << ex.what() << endl;
			}
			break;
		case 2:
			try {
				cout << "Creating a 3x4 table..." << endl;
				cout << "Trying to get column name with index -1." << endl;
				cout << "Trying to set column name with index 10." << endl;
				CTable* t = new CTable(3, 4);
				t->getColumnName(-1);
				t->setColumnName(10, "name");
				delete t;
			}
			catch (ColNameOutOfRange& ex) {
				cout << endl << ex.what() << endl;
			}

			break;
		case 3:
			try {
				cout << "Creating a 3x4 table..." << endl;
				cout << "Trying to get column type with index -1." << endl;
				CTable* t = new CTable(3, 4);
				t->getColumnType(-1);
				delete t;
			}
			catch (ColTypeOutOfRange& ex) {
				cout << endl << ex.what() << endl;
			}

			break;
		case 4:
			try {
				cout << "Creating a 3x4 table..." << endl;
				cout << "Trying to get value with indexes [7, -1]." << endl;
				cout << "Trying to set value with indexes [10, 23]." << endl;
				CTable* t = new CTable(3, 4);
				t->getValue(7,-1);
				t->setValue(10, 23, 0.5);
				delete t;
			}
			catch (ValueOutOfRange& ex) {
				cout << endl << ex.what() << endl;
			}

			break;
		case 5:
			try {
				cout << "Creating a 3x4 table..." << endl;
				cout << "Creating a 3x6 table..." << endl;
				cout << "Trying to UNION ALL these tables with diff number of columns." << endl;
				CTable * t1 = new CTable(3, 4);
				CTable * t2 = new CTable(3, 6);
				*t1 + *t2;
				delete t1, t2;
			}
			catch (DiffColumnsNumAddition& ex) {
				cout << endl << ex.what() << endl;
			}

			break;
		case 6:
			try {
				cout << "Creating a 3x4 table..." << endl;
				cout << "Creating a 3x0 table..." << endl;
				cout << "Trying to CROSS JOIN these tables (second has 0 columns)." << endl;
				CTable* t1 = new CTable(3, 4);
				CTable* t2 = new CTable(3, 0);
				*t1 * *t2;
				delete t1, t2;
			}
			catch (ZeroColMultiplication& ex) {
				cout << endl << ex.what() << endl;
			}

			break;
		case 7:
			try {
				cout << "Creating an empty table..." << endl;
				cout << "Trying to output the empty table." << endl;
				OStreamError err;
				CTable* t = new CTable;
				err.isEmptyTable(*t);
				cout << t;
				delete t;
			}
			catch (const OStreamError& ex) {
				cout << ex.what() << endl;
			}

			break;
		}
	} while (choice != 8);

	cout << endl << "..exiting program." << endl;

	return 0;
}