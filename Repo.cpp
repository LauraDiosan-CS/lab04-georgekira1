#include "Repo.h"
#include<iostream>
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

void Repo:: deleteExpense(const FamilyExpenses& fe) {
    int start_contor = findExpense(fe);
    for (int i = start_contor; i <= this->noExpenses - 2; i++)
        this->family_expenses[i] = this->family_expenses[i + 1];
        this->noExpenses--;


}

void Repo:: updateExpense (int position, const FamilyExpenses& fe){
    if(position < 0 || position > this->getSize()-1)
        {
            cout<<"There isn't any expense on that position"<<endl;
        } else{
        family_expenses[position] = fe;
    }
}

int Repo:: getSize(){
    return this->noExpenses;
}

FamilyExpenses* Repo:: getAll(){
    return this->family_expenses;
}