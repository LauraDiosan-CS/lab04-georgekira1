#include"UI.h"
#include "TestExpense.h"
#include"TestRepo.h"
#include "TestService.h"
#include"FamilyExpenses.h"
#include "Repo.h"
#include"Service.h"


int main()
    {
        TestExpense test_expense;
        test_expense.testAll();

        TestRepo test_repo;
        test_repo.testAll();

        TestService test_service;
        test_service.testAll();


        UI console;
        console.Menu();
    }

