#ifndef LAB_4_5_SERVICE_H
#define LAB_4_5_SERVICE_H

#include <vector>
#include<algorithm>
#include "FamilyExpenses.h"
#include "Repo.h"


class Service {
    private:
        Repo r;
    public:
        Service();
        ~Service();
        Service(const Repo& R);
        void addFamilyExpense(const FamilyExpenses& fe);
        int findExpense(const FamilyExpenses& fe);
        void deleteExpense(const FamilyExpenses& fe);
        void updateExpense(int position, const FamilyExpenses& fe);
        int getSize();
        FamilyExpenses* getAll();
        void addExpenseOnCurrentDay(int sum, char* type);
        void insertExpense(int day, int sum, char type[100]);
        void deleteExpensesOfAGivenDay(int day);
        void deleteExpensesInInterval(int first_day, int last_day);
        void deleteExpensesOfAType(char a_type[100]);
        vector<FamilyExpenses> getExpensesOfAType(char a_type[100]);
        vector<FamilyExpenses> getExpensesOfATypeAndAboveSum(char a_type[100], int sum);
        vector<FamilyExpenses> getExpensesOfTypeAndSum(char a_type[100], int sum);
        int getSumOfAType(char a_type[100]);
        int getMaxSumOfADay();
        vector<pair<int, int>> getSumsAndDaysInDO();
        vector<pair<int, int>> getSumsAndDaysForTypeInAO(char type[100]);
        vector<FamilyExpenses> deleteAllButType(char* type);
        void deleteAllButTypeBelowSum(char* type, int a_sum);
        void deleteAllButTypeExactSum(char* type, int a_sum);


};


#endif //LAB_4_5_SERVICE_H
