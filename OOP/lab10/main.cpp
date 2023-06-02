#include "CTable.hpp"
#include "CBitField.hpp"
#include <set>
#include <stack>
#include <unordered_map>

using namespace std;

void InteractiveProgram();
void SetDemonstration();
void UOMultimapDemonstration();
void StackDemonstration();

void InteractiveProgram() {
	cout << endl << "\t\t\t\t//Interactive program" << endl;

	int choice = 0;
	string _choice;

	do {
		cout << "Enter your choice: " << endl;
		cout << "1 ----------> int" << endl;
		cout << "2 ----------> bool" << endl;
		cout << "3 ----------> CBitField" << endl;
		cout << "4 ----------> exit" << endl;

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
			int rows, cols;
			cout << endl << "Enter your number of rows and columns: " << endl;
			cin >> rows >> cols;
			CTable<int> IntTable(rows, cols);
			TestingTable(IntTable);
			break;
		}
		case 2:
		{
			int rows, cols;
			cout << endl << "Enter your number of rows and columns: " << endl;
			cin >> rows >> cols;
			CTable<bool> BoolTable(rows, cols);
			TestingTable(BoolTable);
			break;
		}
		case 3:
		{
			int rows, cols;
			cout << endl << "Enter your number of rows and columns: " << endl;
			cin >> rows >> cols;
			CTable<CBitField> BitFieldTable(rows, cols);
			TestingTable(BitFieldTable);
			break;
		}
		}
	} while (choice != 4);

	cout << endl << "..exiting program." << endl;
}

void SetDemonstration() {
	cout << endl << "\t\t\t\t//Set demonstration" << endl;

	set<int> newSet = {165, 322, 0, 444, 0, 20, 6, -10, 5};

	//Inserting unique values and values that are already present in the set
	cout << endl << "Inserting elements.." << endl;
	newSet.insert(10);
	newSet.insert(20);
	newSet.insert(30);
	newSet.insert(20);
	newSet.insert(9);
	newSet.insert(3);
	newSet.insert(76);

	//Iterating through the container to read values
	cout << "Here are all elements of the set: \n{ ";
	for (const auto& element : newSet) {
		cout << element << "  ";
	}
	cout << "}" << endl;

	cout << endl << "Size of the set: " << newSet.size() << endl;

	//Successful and unsuccessful search by key
	auto keyRange = newSet.equal_range(445);
	if (keyRange.first == keyRange.second) {
		cout << endl << "Elements with the key given are not found." << endl;
	}
	else {
		for (auto it = keyRange.first; it != keyRange.second; ++it) {
			cout << "Elements found with the key given: " << endl;
			cout << *it << endl;
		}
	}

	//Deleting existing and non-existing elements
	cout << endl << "Deleting elements.." << endl;
	newSet.erase(0);
	newSet.erase(76);
	newSet.erase(-45);
	newSet.erase(23);

	//Iterating through the container to read values
	cout << endl << "Here are all elements of the set: \n{ ";
	for (const auto& element : newSet) {
		cout << element << "  ";
	}
	cout << "}" << endl;
}

void UOMultimapDemonstration() {
	cout << endl << "\t\t\t\t//Unordered multimap demonstration" << endl;

	unordered_multimap<int, string> newMultimap = { { 1, "Book" }, {0, "Pen"}, {-1, "Mark Twain"}};
	

	//Inserting values with existing and non-existing key
	cout << endl << "Inserting elements.." << endl;
	newMultimap.insert({ 1, "Boy"});
	newMultimap.insert({2, "Door"});
	newMultimap.insert({105, "7even"});
	newMultimap.insert({0, "what?"});
	
	//Iterating through the container to read values
	cout << endl << "Here are all elements of the map: \n{" << endl;
	for (const auto& elem : newMultimap) {
		cout << "\t" << elem.second << endl;
	}
	cout << "}" << endl;

	cout << endl << "Size of the map: " << newMultimap.size() << endl;

	//Successful and unsuccessful search by key
	auto keyRange = newMultimap.equal_range(0);
	if (keyRange.first == keyRange.second) {
		cout << endl << "Elements with the key given are not found." << endl;
	}
	else {
		cout << endl << "Elements found with the key given: " << endl;
		for (auto it = keyRange.first; it != keyRange.second; ++it) {
			cout << "\t" << it->first << ": " << it->second << endl;
		}
	}

	//Successful and unsuccessful deleting by key
	cout << endl << "Deleting elements.." << endl;
	newMultimap.erase(0);
	newMultimap.erase(0);
	newMultimap.erase(105);
	newMultimap.erase(1000);
	newMultimap.erase(-3);

	//Iterating through the container to read values
	cout << endl << "Here are all elements of the map: \n{" << endl;
	for (const auto& elem : newMultimap) {
		cout << "\t" << elem.second << endl;
	}
	cout << "}" << endl;

}

void StackDemonstration() {
	cout << endl << "\t\t\t\t//Stack demonstration" << endl;

	stack<int> newStack;

	//Inserting values
	cout << endl << "Inserting elements.." << endl;
	newStack.push(94);
	newStack.push(209);
	newStack.push(38);
	newStack.push(-5);
	newStack.push(0);
	
	cout << endl << "Size of stack: " << newStack.size() << endl;

	cout << endl << "Top element: " << newStack.top() << endl;

	newStack.pop();
	
	cout << endl << "Top element after pop: " << newStack.top() << endl;
	
	//Deleting values
	cout << "Deleting and outputing all elements of the stack: \n{";
	while (!newStack.empty()) {
		cout << "\t" << newStack.top() << "   ";
		newStack.pop();
	}
	cout << " }" << endl;

	if (newStack.empty()) {
		cout << endl << "The stack is empty now!" << endl;
	}
	else {
		cout << endl << "The stack is not empty. The top element is: " << newStack.top() << endl;
	}
}

int main() {
	
	SetDemonstration();
	UOMultimapDemonstration();
	StackDemonstration();
	InteractiveProgram();

	return 0;
}