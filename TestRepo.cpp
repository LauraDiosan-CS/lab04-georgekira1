#include "TestRepo.h"
#include <cassert>
#include <cstring>
#include <iostream>
using namespace std;

TestRepo:: TestRepo()= default;

void TestRepo:: testAll(){
    this->testAdd();
    this->testFind();
    this->testDelete();
    this->testUpdate();
    this->testGetAll();

}

void TestRepo:: testAdd(){
    char* type_1 = new char[10];
    strcpy(type_1, "internet");
    char* type_2 = new char[10];
    strcpy(type_2, "food");
    FamilyExpenses expense_1(1, 1, type_1 );
    FamilyExpenses expense_2(2, 2, type_2 );

    r.addFamilyExpense(expense_1);
    r.addFamilyExpense(expense_2);

    assert(r.getSize() == 2);
}

void TestRepo:: testFind(){
    char* type_1 = new char[10];
    strcpy(type_1, "internet");
    char* type_2 = new char[10];
    strcpy(type_2, "food");
    char* type_3 = new char[10];
    strcpy(type_3, "bills");
    FamilyExpenses expense_1(1, 1, type_1 );
    FamilyExpenses expense_2(2, 2, type_2 );
    FamilyExpenses expense_3(3, 3, type_3);

    assert(r.findExpense(expense_1) == 0);
    assert(r.findExpense(expense_2) == 1);
    assert(r.findExpense(expense_3) == -1);
}

void TestRepo:: testDelete(){
    char* type_1 = new char[10];
    strcpy(type_1, "internet");
    char* type_2 = new char[10];
    strcpy(type_2, "food");

    FamilyExpenses expense_1(1, 1, type_1 );
    FamilyExpenses expense_2(2, 2, type_2 );

    r.deleteExpense(expense_1);
    r.deleteExpense(expense_2);

    assert(r.getSize() == 0);
}

void TestRepo:: testUpdate(){
    char* type_1 = new char[10];
    strcpy(type_1, "internet");
    char* type_2 = new char[10];
    strcpy(type_2, "food");
    char* type_3 = new char[10];
    strcpy(type_3, "bills");

    FamilyExpenses expense_1(1, 1, type_1 );
    FamilyExpenses expense_2(2, 2, type_2 );
    FamilyExpenses expense_3(3, 3, type_3);

    r.addFamilyExpense(expense_1);
    r.addFamilyExpense(expense_2);

    r.updateExpense(1, expense_3);

    assert(r.getAll()[1] == expense_3);
}

void TestRepo:: testGetAll(){
    char* type_1 = new char[10];
    strcpy(type_1, "internet");
    char* type_3 = new char[10];
    strcpy(type_3, "bills");

    FamilyExpenses expense_1(1, 1, type_1 );
    FamilyExpenses expense_3(3, 3, type_3);

    assert(r.getAll()[0] == expense_1);
    assert(r.getAll()[1] == expense_3);
}