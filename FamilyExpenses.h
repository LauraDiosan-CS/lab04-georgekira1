#ifndef LAB_4_5_FAMILYEXPENSES_H
#define LAB_4_5_FAMILYEXPENSES_H
#pragma once
#include <ostream>
#include <vector>

using namespace std;

class FamilyExpenses {
    private:
    int day;
    int sum;
    char* type;
    public:
        FamilyExpenses();
        FamilyExpenses(int day, int sum, char* type);
        FamilyExpenses( const FamilyExpenses& fe);
        ~FamilyExpenses();
        int getDay();
        int getSum();
        char* getType();
        void setDay(int day);
        void setSum(int sum);
        void setType(char* type);
        FamilyExpenses& operator=(const FamilyExpenses& fe);
        bool operator==(const FamilyExpenses& fe);
        friend ostream& operator<<(ostream& os, const FamilyExpenses& e);
        //friend ostream& operator>>(ostream& os, const FamilyExpenses& e);



};


#endif //LAB_4_5_FAMILYEXPENSES_H
