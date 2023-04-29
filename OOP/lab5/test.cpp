#include "pch.h"
#include "../oop_lab5_prog/CTable.hpp"
#include "../oop_lab5_prog/CTableUnq.hpp"

double const epsilon = 0.000001;

class CTableTestClass : public ::testing::Test {
protected:
    // Set up test case
    virtual void SetUp() override {
        table = new CTable(3, 7, "Col");
    }

    // Tear down test case
    virtual void TearDown() override {
        delete table;
    }

    CTable* table;
};

TEST_F(CTableTestClass, DefaultConstructor) {
    EXPECT_EQ(table->getRows(), 3);
    EXPECT_EQ(table->getColumns(), 7);
}

TEST(CTableConstructorTest, ColumnsRowsConstructor) {
    CTable Table(5, 6);

    EXPECT_EQ(Table.getRows(), 5);
    EXPECT_EQ(Table.getColumns(), 6);
}

TEST(CTableConstructorTest, ColumnsRowsColumnNamesConstructor) {

    string columnNames[3] = { "Col1", "fgg", "_what?" };
    int num = sizeof(columnNames)/sizeof(string);

    CTable Table(3, 5, columnNames, num);

    EXPECT_EQ(Table.getRows(), 3);
    EXPECT_EQ(Table.getColumns(), 5);
    EXPECT_EQ(Table.getColumnName(0), "Col1");
    EXPECT_EQ(Table.getColumnName(1), "fgg");
    EXPECT_EQ(Table.getColumnName(2), "_what?");
    EXPECT_EQ(Table.getColumnName(3), "");
}

TEST(CTableConstructorTest, ColumnsRowsDefaultColumnNameConstructor) {
    CTable Table(3, 5, "Column");

    EXPECT_EQ(Table.getRows(), 3);
    EXPECT_EQ(Table.getColumns(), 5);
    EXPECT_EQ(Table.getColumnName(0), "Column1");
}
TEST_F(CTableTestClass, CopyConstructor) {
    table->setValue(0, 0, 6.1);

    CTable copyTable(*table);

    EXPECT_EQ(copyTable.getColumns(), table->getColumns());
    EXPECT_EQ(copyTable.getRows(), table->getRows());

    EXPECT_NEAR(copyTable.getValue(0, 0), table->getValue(0, 0), epsilon);
}

TEST(CTableTest, MoveConstructor) {
    CTable otherTable(3, 5);
    otherTable.setValue(0, 0, 2.5);
    otherTable.setValue(1, 1, 5);

    CTable tableMoved(move(otherTable));

    EXPECT_EQ(tableMoved.getRows(), 3);
    EXPECT_EQ(tableMoved.getColumns(), 5);
    EXPECT_NEAR(tableMoved.getValue(0, 0), 2.5, epsilon);
    EXPECT_NEAR(tableMoved.getValue(1, 1), 5, epsilon);

    EXPECT_EQ(otherTable.getColumns(), 0);
    EXPECT_EQ(otherTable.getRows(), 0);
}

TEST_F(CTableTestClass, AssignmentOperator) {
    CTable otherTable(3, 5);
    otherTable.setValue(0, 0, 1.23);
    otherTable.setValue(1, 1, 4.56);


    *table = otherTable;

    EXPECT_EQ(table->getRows(), 3);
    EXPECT_EQ(table->getColumns(), 5);
    EXPECT_DOUBLE_EQ(table->getValue(0, 0), 1.23);
    EXPECT_DOUBLE_EQ(table->getValue(1, 1), 4.56);
}

TEST(CTableTest, InputOperator) {

    stringstream ss;
    ss << "Rows: 3, Columns: 4" << endl
       << "Table: " << endl
       << "Column1 Column2 Column3 Column4" << endl
       << "1.0 2.0 3.0 4.0" << endl
       << "5.0 6.0 7.0 8.0" << endl
       << "9.0 10.0 11.0 12.0" << endl;

    CTable table;
    ss >> table;

    EXPECT_EQ(table.getRows(), 3);
    EXPECT_EQ(table.getColumns(), 4);
    EXPECT_EQ(table.getColumnName(0), "Column1");
    EXPECT_EQ(table.getColumnName(1), "Column2");
    EXPECT_EQ(table.getColumnName(2), "Column3");
    EXPECT_EQ(table.getColumnName(3), "Column4");
    
    EXPECT_DOUBLE_EQ(table.getValue(0, 0), 1.0);
    EXPECT_DOUBLE_EQ(table.getValue(0, 1), 2.0);
    EXPECT_DOUBLE_EQ(table.getValue(0, 2), 3.0);
    EXPECT_DOUBLE_EQ(table.getValue(0, 3), 4.0);
    EXPECT_DOUBLE_EQ(table.getValue(1, 0), 5.0);
    EXPECT_DOUBLE_EQ(table.getValue(1, 1), 6.0);
    EXPECT_DOUBLE_EQ(table.getValue(1, 2), 7.0);
    EXPECT_DOUBLE_EQ(table.getValue(1, 3), 8.0);
    EXPECT_DOUBLE_EQ(table.getValue(2, 0), 9.0);
    EXPECT_DOUBLE_EQ(table.getValue(2, 1), 10.0);
    EXPECT_DOUBLE_EQ(table.getValue(2, 2), 11.0);
    EXPECT_DOUBLE_EQ(table.getValue(2, 3), 12.0);
}

TEST(CTableTest, OutputOperator) {

    CTable table(2, 3, "default");
    table.setValue(0, 0, 1.1);
    table.setValue(0, 1, 2.2);
    table.setValue(0, 2, 3.3);
    table.setValue(1, 0, 4.4);
    table.setValue(1, 1, 5.5);
    table.setValue(1, 2, 6.6);

    stringstream ss;
    ss << table;

    string expected_output = "Rows: 2, Columns: 3\nTable:\n\ndefault1 default2 default3 \n1.1 2.2 3.3 \n4.4 5.5 6.6 \n";
    EXPECT_EQ(ss.str(), expected_output);
}
TEST(CTableTest, CopyAssignmentOperator) {
    CTable table1(3, 5);
    CTable table2(2, 6);
    table1.setValue(0, 0, 575);
    table1.setValue(1, 1, 3.45);

    table2 = table1;

    EXPECT_EQ(table2.getRows(), 3);
    EXPECT_EQ(table2.getColumns(), 5);
    EXPECT_NEAR(table2.getValue(0, 0), 575, epsilon);
    EXPECT_NEAR(table2.getValue(1, 1), 3.45, epsilon);
}

TEST(CTableTest, MoveAssignmentOperator) {
    
    CTable table1(3, 5);
    CTable table2(2, 10);
    table1.setValue(0, 0, 575);
    table1.setValue(1, 1, 3.45);

    table2 = move(table1);

    EXPECT_EQ(table2.getRows(), 3);
    EXPECT_EQ(table2.getColumns(), 5);
    EXPECT_NEAR(table2.getValue(0, 0), 575, epsilon);
    EXPECT_NEAR(table2.getValue(1, 1), 3.45, epsilon);

    EXPECT_DEATH(table1.getValue(0, 0), "");
}
TEST_F(CTableTestClass, Destructor) {
    unique_ptr<CTable> table(new CTable(3, 5));
    table.release();

    EXPECT_DEATH(table->getRows(), "");
}

TEST(CTableTest, AdditionOperator) {
    
    CTable table1(2, 3, "data");
    table1.setValue(0, 0, 1.5);
    table1.setValue(0, 1, 2.5);
    table1.setValue(0, 2, 3.5);
    table1.setValue(1, 0, 4.5);
    table1.setValue(1, 1, 5.5);
    table1.setValue(1, 2, 6.5);

    CTable table2(3, 2, "Data");
    table2.setValue(0, 0, 7.5);
    table2.setValue(0, 1, 8.5);
    table2.setValue(1, 0, 9.5);
    table2.setValue(1, 1, 10.5);
    table2.setValue(2, 0, 11.5);
    table2.setValue(2, 1, 12.5);

    CTable result = table1 + table2;

    ASSERT_EQ(result.getRows(), 5);
    ASSERT_EQ(result.getColumns(), 3);
   
    EXPECT_EQ(result.getColumnName(0), "data1");
    EXPECT_EQ(result.getColumnName(1), "data2");
    EXPECT_EQ(result.getColumnName(2), "data3");

    ASSERT_DOUBLE_EQ(result.getValue(0, 0), 1.5);
    ASSERT_DOUBLE_EQ(result.getValue(0, 1), 2.5);
    ASSERT_DOUBLE_EQ(result.getValue(0, 2), 3.5);
    ASSERT_DOUBLE_EQ(result.getValue(1, 0), 4.5);
    ASSERT_DOUBLE_EQ(result.getValue(1, 1), 5.5);
    ASSERT_DOUBLE_EQ(result.getValue(1, 2), 6.5);
    ASSERT_DOUBLE_EQ(result.getValue(2, 0), 7.5);
    ASSERT_DOUBLE_EQ(result.getValue(2, 1), 8.5);
    ASSERT_DOUBLE_EQ(result.getValue(2, 2), 0);
    ASSERT_DOUBLE_EQ(result.getValue(3, 0), 9.5);
    ASSERT_DOUBLE_EQ(result.getValue(3, 1), 10.5);
    ASSERT_DOUBLE_EQ(result.getValue(3, 2), 0);
    ASSERT_DOUBLE_EQ(result.getValue(4, 0), 11.5);
    ASSERT_DOUBLE_EQ(result.getValue(4, 1), 12.5);
    ASSERT_DOUBLE_EQ(result.getValue(4, 2), 0);

}

TEST(CTableTest, MultiplicationOperator) {
    CTable table1(3, 2);
    table1.setValue(0, 0, 1.0);
    table1.setValue(0, 1, 2.0);
    table1.setValue(1, 0, 3.0);
    table1.setValue(1, 1, 4.0);
    table1.setValue(2, 0, 5.0);
    table1.setValue(2, 1, 6.0);

    CTable table2(2, 3);
    table2.setValue(0, 0, 7.0);
    table2.setValue(0, 1, 8.0);
    table2.setValue(0, 2, 9.0);
    table2.setValue(1, 0, 10.0);
    table2.setValue(1, 1, 11.0);
    table2.setValue(1, 2, 12.0);

    CTable result = table1 * table2;

    EXPECT_EQ(result.getRows(), 6);
    EXPECT_EQ(result.getColumns(), 5);

    EXPECT_DOUBLE_EQ(result.getValue(0, 0), 1.0);
    EXPECT_DOUBLE_EQ(result.getValue(0, 1), 2.0);
    EXPECT_DOUBLE_EQ(result.getValue(0, 2), 7.0);
    EXPECT_DOUBLE_EQ(result.getValue(0, 3), 8.0);
    EXPECT_DOUBLE_EQ(result.getValue(0, 4), 9.0);

    EXPECT_DOUBLE_EQ(result.getValue(5, 0), 5.0);
    EXPECT_DOUBLE_EQ(result.getValue(5, 1), 6.0);
    EXPECT_DOUBLE_EQ(result.getValue(5, 2), 10.0);
    EXPECT_DOUBLE_EQ(result.getValue(5, 3), 11.0);
    EXPECT_DOUBLE_EQ(result.getValue(5, 4), 12.0);

}

TEST(CTableTest, InputOutputOperators) {

    CTable Table(6, 7);

    Table.setValue(0, 0, 2.5);
    Table.setValue(0, 1, 3.75);
    Table.setValue(1, 0, -1.0);
    Table.setValue(1, 1, 0.0);
    Table.setValue(2, 0, 1234.56);
    Table.setValue(2, 1, -9876.54);

    stringstream ss;

    ss << Table;

    CTable Table2;
    ss >> Table2;

    EXPECT_EQ(Table2.getRows(), 6);
    EXPECT_EQ(Table2.getColumns(), 7);

    EXPECT_DOUBLE_EQ(Table2.getValue(0, 0), 2.5);
    EXPECT_DOUBLE_EQ(Table2.getValue(0, 1), 3.75);
    EXPECT_DOUBLE_EQ(Table2.getValue(1, 0), -1.0);
    EXPECT_DOUBLE_EQ(Table2.getValue(1, 1), 0.0);
    EXPECT_DOUBLE_EQ(Table2.getValue(2, 0), 1234.56);
    EXPECT_DOUBLE_EQ(Table2.getValue(2, 1), -9876.54);
}
TEST(CTableTest, SetAndGetColumnName) {
    CTable Table(3, 5);

    Table.setColumnName(0, "Column1");
    Table.setColumnName(1, "Column2");
    Table.setColumnName(2, "Column3");

    EXPECT_EQ(Table.getColumnName(0), "Column1");
    EXPECT_EQ(Table.getColumnName(1), "Column2");
    EXPECT_EQ(Table.getColumnName(2), "Column3");
}

TEST(CTableTest, SetAndGetValue) {
    CTable table(3, 5);

    table.setValue(0, 0, -3.2);
    table.setValue(1, 1, 0);
    table.setValue(2, 2, 544);

    EXPECT_NEAR(table.getValue(0, 0), -3.2, epsilon);
    EXPECT_NEAR(table.getValue(1, 1), 0, epsilon);
    EXPECT_NEAR(table.getValue(2, 2), 544, epsilon);
}

TEST(CTableTest, SetColumnCount) {
    CTable table(3, 5);

    table.setColumnCount(4);

    EXPECT_EQ(table.getRows(), 3);
    EXPECT_EQ(table.getColumns(), 4);

    table.setColumnName(0, "Column1");
    table.setColumnName(1, "Column2");
    table.setColumnName(2, "Column3");
    table.setColumnName(3, "Column4");

    EXPECT_EQ(table.getColumns(), 4);
    EXPECT_EQ(table.getColumnName(0), "Column1");
    EXPECT_EQ(table.getColumnName(1), "Column2");
    EXPECT_EQ(table.getColumnName(2), "Column3");
    EXPECT_EQ(table.getColumnName(3), "Column4");
}

TEST(CTableTest, SetRowCount) {

    CTable Table(3, 5);

    Table.setRowCount(6);

    EXPECT_EQ(Table.getRows(), 6);
    EXPECT_EQ(Table.getColumns(), 5); 
}

TEST(CTableUnqTest, DefaultConstructor) {
    CTableUnq Table;

    EXPECT_EQ(Table.getColumns(), 0);
    EXPECT_EQ(Table.getRows(), 0);
}

TEST(CTableUnqTest, Destructor) {
    unique_ptr<CTableUnq> Table (new CTableUnq(3,2));

    Table.release();

    EXPECT_DEATH(Table->getRows(), "");
}

TEST(CTableUnqTest, MoveAssignmentOperator) {

    CTableUnq table1(3, 2);
    table1.setColumnName(0, "Name");
    table1.setColumnName(1, "Age");
    table1.setValue(0, 0, 366);
    table1.setValue(0, 1, 7.3);

    CTableUnq table2;
    table2 = move(table1);

    EXPECT_EQ(table2.getRows(), 3);
    EXPECT_EQ(table2.getColumns(), 2);
    EXPECT_EQ(table2.getColumnName(0), "Name");
    EXPECT_EQ(table2.getColumnName(1), "Age");
    EXPECT_NEAR(table2.getValue(0, 0), 366, epsilon);
    EXPECT_NEAR(table2.getValue(0, 1), 7.3, epsilon);

    EXPECT_DEATH(table1.getColumnName(0), "");

}