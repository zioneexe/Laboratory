#ifndef CTABLE_HPP
#define CTABLE_HPP

#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <typeinfo>
#include <vector>
#include <algorithm>
#include <initializer_list>

using namespace std;

template <typename T>
class CTable {
public:
    CTable() noexcept;
    CTable(int rows, int columns);
    CTable(int rows, int columns, vector<string>& names) noexcept;
    CTable(int rows, int columns, const string& defaultColumnName) noexcept;
    CTable(const CTable& other);
    CTable(CTable&& other) noexcept;
    ~CTable() noexcept;

    int getColumns() const noexcept;
    int getRows() const noexcept;
    string getColumnName(int columnIndex) const;
    string getColumnType(int columnIndex) const;
    T getValue(int rowIndex, int columnIndex) const;

    void setColumnName(int columnIndex, const string& columnName);
    void setColumnCount(int numColumns);
    void setRowCount(int numRows);
    void setValue(int rowIndex, int columnIndex, const T& value);

    void clearTable() noexcept;
    void printTable() const noexcept;
    void reverseColumns() noexcept;
    vector<vector<string>> getValuesString() noexcept;
    bool isEmpty() const;
    void addColumn(int columnIndex, const string& columnName, initializer_list<T> list);
    void addRow(int rowIndex, initializer_list<T> list);
    void delColumn(int columnIndex);
    void delRow(int rowIndex);

    CTable<T>& operator=(const CTable<T>& other);
    CTable<T>& operator=(CTable<T>&& other) noexcept;

    CTable<T> operator+(const CTable<T>& other) const;
    CTable<T> operator*(const CTable<T>& other) const;

    template <typename T2>
    friend istream& operator>>(istream& is, CTable<T2>& table);
    template <typename T2>
    friend ostream& operator<<(ostream& os, const CTable<T2>& table);
    template <typename T2>
    friend bool operator == (CTable<T2>& t1, CTable<T2>& t2) noexcept;

private:
    int rows;
    int columns;
    vector<vector<T>> data;
    vector<string> columnnames;
};


template <typename T>
int FindElementInArray(vector<T>& Vector, T& Elem) noexcept;

template <typename T>
string ConvertToString(const T& value) noexcept;

template <typename T>
void TestingTable(CTable<T> table);

#include "CTable.inl"

#endif