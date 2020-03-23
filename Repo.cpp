#include "Repo.h"
using namespace std;

Repo:: Repo(){
    this->noExpenses = 0;
}

Repo:: ~Repo(){
    this->noExpenses = 0;
}

void Repo:: addFamilyExpense(const FamilyExpenses& fe) {
    this->family_expenses[this->noExpenses++] = fe;
}

int Repo:: findExpense(const FamilyExpenses &fe) {
    for (int i=0; i<this->getSize(); i++)
        {
            if (this->family_expenses[i] == fe)
                return i;
        }
    return -1;
}

void Repo:: deleteExpense(FamilyExpenses fe) {
    int start_contor = findExpense(fe);
    if (start_contor>=0 && start_contor <= this->getSize()-1 )
        {
            for (int i=start_contor; i<this->getSize()-1; i++)
            {
                family_expenses[i] = family_expenses[i+1];
                noExpenses--;
            }
        } else{
        cout<<"We haven't found any expense!"<<endl;
    }

}

void Repo:: updateExpenseDay(int position, int new_day) {
    family_expenses[position].setDay(new_day);
}

void Repo:: updateExpenseSum(int position, int new_sum) {
    family_expenses[position].setSum(new_sum);
}

void Repo:: updateExpenseType(int position, char *new_type) {
    family_expenses[position].setType(new_type);
}

int Repo:: getSize(){
    return this->noExpenses;
}

FamilyExpenses* Repo:: getAll(){
    return this->family_expenses;
}