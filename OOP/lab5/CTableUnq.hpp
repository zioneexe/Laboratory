#ifndef CTABLEUNQ_HPP
#define CTABLEUNQ_HPP

#include <cassert>
#include <iostream>
#include <string>
#include <memory>
#include <typeinfo>
#include <algorithm>

using namespace std;

class CTableUnq {
public:
    CTableUnq();
    CTableUnq(int rows, int columns);
    CTableUnq(int rows, int columns, string *names, int num);
    CTableUnq(int rows, int columns, const string& defaultColumnName);
    CTableUnq(const CTableUnq& other);
    CTableUnq(CTableUnq&& other) noexcept;
    ~CTableUnq();

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

    CTableUnq& operator=(const CTableUnq& other);
    CTableUnq& operator=(CTableUnq&& other) noexcept;

    CTableUnq operator+(const CTableUnq& other) const;
    CTableUnq operator*(const CTableUnq& other) const;

    friend istream& operator>>(istream& is, CTableUnq& table);
    friend ostream& operator<<(ostream& os, const CTableUnq& table);

private:
    int rows;
    int columns;
    unique_ptr<unique_ptr<double[]>[]> data;
    unique_ptr<string[]> columnnames;
};

#endif