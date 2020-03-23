#ifndef LAB_4_5_REPO_H
#define LAB_4_5_REPO_H
#include "FamilyExpenses.h"
#pragma once

class Repo {
    private:
        FamilyExpenses family_expenses[10];
        int noExpenses;

    public:
        Repo();
        ~Repo();
        void addFamilyExpense(const FamilyExpenses& fe);
        int findExpense(const FamilyExpenses& fe);
        void deleteExpense(FamilyExpenses fe);
        void updateExpenseDay(int position, int new_day);
        void updateExpenseSum(int position, int new_sum);
        void updateExpenseType(int position, char* new_type);
        int getSize();
        FamilyExpenses* getAll();


};


#endif //LAB_4_5_REPO_H
