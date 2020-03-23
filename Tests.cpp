#include "Tests.h"
#include "FamilyExpenses.h"
#include "Repo.h"
#include <cassert>
#include <cstring>
using namespace std;
void testFamilyExpenses()
    {
        char* type_1 = new char[10];

        strcpy(type_1, "internet");

        FamilyExpenses expense_1(2, 70, type_1);

        assert(expense_1.getDay()==2);
        assert(expense_1.getSum()==70);
        assert(strcmp(expense_1.getType(), "internet") == 0);

        expense_1.setDay(3);
        expense_1.setSum(71);
        expense_1.setType("food");

        assert(expense_1.getDay()==3);
        assert(expense_1.getSum()==71);
        assert(strcmp(expense_1.getType(),"food")==0);

        cout<<"Teste entitate trecute"<<endl;

    }

void testRepo()
    {
        char* type_1 = new char[10];
        char* type_2 = new char[10];

        strcpy(type_1, "internet");
        strcpy(type_2, "clothes");

        FamilyExpenses expense_1(2, 70, type_1);
        FamilyExpenses expense_2(3, 71, type_2);

        Repo r;
        r.addFamilyExpense(expense_1);
        r.addFamilyExpense(expense_2);

        assert(r.getSize() == 2);
        assert(r.getAll()[0] == expense_1);
        assert(r.getAll()[1] == expense_2);

        r.deleteExpense(expense_1);

        assert(r.getSize() == 1);

        r.updateExpenseDay(0, 5);
        assert(r.getAll()[0].getDay() == 5);
        r.updateExpenseSum(0, 50);
        assert(r.getAll()[0].getSum() == 50);
        r.updateExpenseType(0, "clothes");
        assert(strcmp(r.getAll()[0].getType(), "clothes") == 0 );

        cout<<"Teste repository trecute";


    }