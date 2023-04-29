#ifndef CTABLE_HPP
#define CTABLE_HPP

#include <cassert>
#include <iostream>
#include <string>
#include <memory>
#include <typeinfo>
#include <algorithm>
#include <cstdlib>

using namespace std;

class CTable {
public:
    CTable();
    CTable(int rows, int columns);
    CTable(int rows, int columns, string *names, int num);
    CTable(int rows, int columns, const string& defaultColumnName);
    CTable(const CTable& other);
    CTable(CTable&& other) noexcept;
    ~CTable();

    int getColumns() const;
    int getRows() const;
    string getColumnName(int columnIndex) const;
    string getColumnType(int columnIndex) const;
    double getValue(int rowIndex, int columnIndex) const;

    void setColumnName(int columnIndex, const string& columnName);
    void setColumnCount(int numColumns);
    void setRowCount(int numRows);
    void setValue(int rowIndex, int columnIndex, const double& value);

    void clearTable();
    void printTable();

    CTable& operator=(const CTable& other);
    CTable& operator=(CTable&& other) noexcept;

    CTable operator+(const CTable& other) const;
    CTable operator*(const CTable& other) const;

    friend istream& operator>>(istream& is, CTable& table);
    friend ostream& operator<<(ostream& os, const CTable& table);

private:
    int columns;
    int rows;
    double** data;
    string* columnnames;
};

#endif