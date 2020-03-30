#include "TestService.h"
#include <cassert>
#include <cstring>
#include <iostream>
using namespace std;

TestService:: TestService()= default;

void TestService:: testAll(){
    this->testAddExpense();
    this->testDeleteExpense();
    this->testDeleteExpensesOfAGivenDay();
    this->testDeleteExpenseInRange();
    this->testGetSumOfAType();
    this->testMaxSumOfADay();
    this->testFilterType();
    this->testUpdate();
}

void TestService:: testAddExpense(){
    char* type_1 = new char[100];
    strcpy(type_1, "internet");

    FamilyExpenses expense_1(1, 1, type_1 );

    s.addFamilyExpense(expense_1);

    assert(s.getSize() == 1);

}

void TestService:: testDeleteExpense(){
    char* type_1 = new char[100];
    strcpy(type_1, "internet");

    FamilyExpenses expense_1(1, 1, type_1 );

    s.deleteExpense(expense_1);

    assert(s.getSize() == 0);

}

void TestService:: testUpdate(){
    int position = 1;

    char* type_1 = new char[100];
    strcpy(type_1, "bills");
    char* type_2 = new char[10];
    strcpy(type_2, "food");

    FamilyExpenses expense_1(1, 1, type_1 );
    FamilyExpenses expense_2(2, 2, type_2 );

    s.updateExpense(position, expense_1);

    assert(s.getAll()[1] == expense_1);
}

void TestService:: testDeleteExpensesOfAGivenDay(){
    int day = 5;
    char* type_1 = new char[100];
    strcpy(type_1, "internet");
    char* type_2 = new char[10];
    strcpy(type_2, "food");

    FamilyExpenses expense_1(1, 1, type_1 );
    FamilyExpenses expense_2(day, 2, type_2 );


    s.addFamilyExpense(expense_1);
    s.addFamilyExpense(expense_2);

    s.deleteExpensesOfAGivenDay(day);

    assert(s.getSize() == 1);

}

void TestService:: testDeleteExpenseInRange(){
    int first_day = 1;
    int last_day = 2;

    char* type_1 = new char[100];
    strcpy(type_1, "internet");
    char* type_2 = new char[10];
    strcpy(type_2, "food");
    char* type_3 = new char[10];
    strcpy(type_3, "bills");

    FamilyExpenses expense_1(1, 1, type_1 );
    FamilyExpenses expense_2(2, 2, type_2 );
    FamilyExpenses expense_3(3, 3, type_3);

    s.addFamilyExpense(expense_2);
    s.addFamilyExpense(expense_3);

    s.deleteExpensesInInterval(first_day, last_day);

    assert(s.getSize() == 1);
}

void TestService:: testGetSumOfAType(){
    char* a_type = new char[10];
    strcpy(a_type, "bills");

    char* type_1 = new char[100];
    strcpy(type_1, "bills");
    char* type_2 = new char[10];
    strcpy(type_2, "food");
    char* type_3 = new char[10];
    strcpy(type_3, "bills");

    FamilyExpenses expense_1(1, 1, type_1 );
    FamilyExpenses expense_2(2, 2, type_2 );
    FamilyExpenses expense_3(3, 3, type_3);

    s.addFamilyExpense(expense_1);
    s.addFamilyExpense(expense_2);

    assert(s.getSumOfAType(a_type) == 4);

}

void TestService:: testMaxSumOfADay(){
    char* type_1 = new char[100];
    strcpy(type_1, "bills");
    char* type_2 = new char[10];
    strcpy(type_2, "food");
    char* type_3 = new char[10];
    strcpy(type_3, "bills");
    char* type_4 = new char[10];
    strcpy(type_4, "bills");

    FamilyExpenses expense_1(1, 1, type_1 );
    FamilyExpenses expense_2(2, 2, type_2 );
    FamilyExpenses expense_3(3, 3, type_3);
    FamilyExpenses expense_4(1, 3, type_4);

    s.addFamilyExpense(expense_4);

    assert(s.getMaxSumOfADay() == 1);

}

void TestService:: testFilterType(){
    char* a_type = new char[10];
    strcpy(a_type, "food");

    char* type_1 = new char[100];
    strcpy(type_1, "bills");
    char* type_2 = new char[10];
    strcpy(type_2, "food");
    char* type_3 = new char[10];
    strcpy(type_3, "bills");
    char* type_4 = new char[10];
    strcpy(type_4, "bills");

    FamilyExpenses expense_1(1, 1, type_1 );
    FamilyExpenses expense_2(2, 2, type_2 );
    FamilyExpenses expense_3(3, 3, type_3);
    FamilyExpenses expense_4(1, 3, type_4);

    s.deleteAllButType(a_type);

    assert(s.getSize() == 4);

}
