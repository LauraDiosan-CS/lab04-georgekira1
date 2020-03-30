#ifndef LAB_4_5_TESTEXPENSE_H
#define LAB_4_5_TESTEXPENSE_H
#pragma once
#include "FamilyExpenses.h"
#include<vector>

class TestExpense {
    private: vector <FamilyExpenses> expenses;
             void testGetDay();
             void testGetSum();
             void testGetType();
             void testSetDay();
             void testSetSum();
             void testSetType();
    public:
            TestExpense();
            void testAll();
};


#endif //LAB_4_5_TESTEXPENSE_H
