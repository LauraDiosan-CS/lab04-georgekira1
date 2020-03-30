#ifndef LAB_4_5_UI_H
#define LAB_4_5_UI_H
#include "Service.h"
#include "FamilyExpenses.h"
#include"Repo.h"

class UI {
    private:
            Service s;
            void showMenu();
            void handleAddExpense();
            void handleInsertExpense();
            void handleShowAllExpenses();
            void handleDeleteWhatYouWant();
            void handleShowAllExpensesOfACertainType();
            void handleShowAllExpensesOfACertainTypeAndAboveSum();
            void handleShowExpensesOfTypeAndSum();
            void handleShowSumOfAType();
            void handleShowMaxSumOfDay();
            void handleShowSumsAndDaysInDO();
            void handleShowSumsAndDaysForTypeInAO();
            void handleFilterType();
            void handleFilterTypeBelowSum();
            void handleFilterTypeExactSum();


    public:
            UI();
            UI(const Service& S);
            ~UI();
            void Menu();
};


#endif //LAB_4_5_UI_H
