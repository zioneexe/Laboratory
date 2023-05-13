#ifndef CTABLE_HPP
#define CTABLE_HPP

#include <cassert>
#include <iostream>
#include <string>
#include <memory>
#include <typeinfo>
#include <algorithm>

using namespace std;

class CTable {
public:
    CTable() noexcept;
    CTable(int rows, int columns);
    CTable(int rows, int columns, string* names, int num) noexcept;
    CTable(int rows, int columns, const string& defaultColumnName) noexcept;
    CTable(const CTable& other);
    CTable(CTable&& other) noexcept;
    ~CTable() noexcept;

    int getColumns() const noexcept;
    int getRows() const noexcept;
    string getColumnName(int columnIndex) const;
    string getColumnType(int columnIndex) const;
    double getValue(int rowIndex, int columnIndex) const;

    void setColumnName(int columnIndex, const string& columnName);
    void setColumnCount(int numColumns);
    void setRowCount(int numRows);
    void setValue(int rowIndex, int columnIndex, const double& value);

    void clearTable() noexcept;
    void printTable() noexcept;

    CTable& operator=(const CTable& other);
    CTable& operator=(CTable&& other) noexcept;

    CTable operator+(const CTable& other) const;
    CTable operator*(const CTable& other) const;

    friend istream& operator>>(istream& is, CTable& table);
    friend ostream& operator<<(ostream& os, const CTable& table);


private:
    int rows;
    int columns;
    unique_ptr<unique_ptr<double[]>[]> data;
    unique_ptr<string[]> columnnames;
};

#endif