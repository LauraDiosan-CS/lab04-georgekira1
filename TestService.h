#ifndef LAB_4_5_TESTSERVICE_H
#define LAB_4_5_TESTSERVICE_H
#pragma once
#include "Service.h"
#include<vector>

class TestService {
    private:Service s;
    void testAddExpense();
    void testDeleteExpense();
    void testUpdate();
    void testDeleteExpensesOfAGivenDay();
    void testDeleteExpenseInRange();
    void testGetSumOfAType();
    void testMaxSumOfADay();
    void testFilterType();


    public:
        TestService();
        void testAll();
};


#endif //LAB_4_5_TESTSERVICE_H
