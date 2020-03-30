#ifndef LAB_4_5_TESTREPO_H
#define LAB_4_5_TESTREPO_H
#pragma once
#include "Repo.h"

class TestRepo {
    private: Repo r;
             void testAdd();
             void testFind();
             void testDelete();
             void testUpdate();
             void testGetAll();

    public:
            TestRepo();
            void testAll();

};


#endif //LAB_4_5_TESTREPO_H
