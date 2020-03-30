#include "TestExpense.h"
#include <cassert>
#include<cstring>
#include <iostream>
using namespace std;

TestExpense:: TestExpense()
{
    char* type_1 = new char[10];
    strcpy(type_1, "internet");
    char* type_2 = new char[10];
    strcpy(type_2, "food");
    char* type_3 = new char[10];
    strcpy(type_3, "bills");
    char* type_4 = new char[10];
    strcpy(type_4, "other");

    FamilyExpenses expense_1(1, 1, type_1 );
    FamilyExpenses expense_2(2, 2, type_2 );
    FamilyExpenses expense_3(3, 3, type_3);
    FamilyExpenses expense_4(4, 4, type_4 );

    this->expenses.push_back(expense_1);
    this->expenses.push_back(expense_2);
    this->expenses.push_back(expense_3);
    this->expenses.push_back(expense_4);

}

void TestExpense:: testAll(){
    this->testGetDay();
    this->testGetSum();
    this->testGetType();
    this->testSetDay();
    this->testSetSum();
    this->testSetType();

}

void TestExpense:: testGetDay() {
    for (int i = 0; i < expenses.size(); i++) {
        assert(expenses[i].getDay() == i + 1);
    }
}

void TestExpense:: testGetSum() {
    for (int i = 0; i < expenses.size(); i++) {
        assert(expenses[i].getSum() == i + 1);
    }
}

void TestExpense:: testGetType() {
    assert(strcmp(expenses[0].getType(), "internet") == 0);
    assert(strcmp(expenses[1].getType(), "food") == 0);
    assert(strcmp(expenses[2].getType(), "bills") == 0);
    assert(strcmp(expenses[3].getType(), "other") == 0);
}

void TestExpense:: testSetDay() {
    expenses[0].setDay(2);
    expenses[1].setDay(3);
    expenses[2].setDay(4);
    expenses[3].setDay(5);
    for (int i = 0; i < expenses.size(); i++) {
        assert(expenses[i].getDay() == i + 2);
    }
}

void TestExpense:: testSetSum() {
    expenses[0].setSum(2);
    expenses[1].setSum(3);
    expenses[2].setSum(4);
    expenses[3].setSum(5);
    for (int i = 0; i < expenses.size(); i++) {
        assert(expenses[i].getSum() == i + 2);
    }
}

void TestExpense:: testSetType() {
    char* type_1 = new char[10];
    strcpy(type_1, "internet");
    char* type_2 = new char[10];
    strcpy(type_2, "food");
    char* type_3 = new char[10];
    strcpy(type_3, "bills");
    char* type_4 = new char[10];
    strcpy(type_4, "other");
    expenses[0].setType(type_2);
    expenses[1].setType(type_3);
    expenses[2].setType(type_4);
    expenses[3].setType(type_1);
    assert(strcmp(expenses[0].getType(), "food") == 0);
    assert(strcmp(expenses[1].getType(), "bills") == 0);
    assert(strcmp(expenses[2].getType(), "other") == 0);
    assert(strcmp(expenses[3].getType(), "internet") == 0);
}






