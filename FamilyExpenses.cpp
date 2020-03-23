#include "FamilyExpenses.h"
#include<iostream>
#include<cstring>


FamilyExpenses:: FamilyExpenses(){
    this->day = 0;
    this->sum = 0;
    this->type = nullptr;
}

FamilyExpenses:: FamilyExpenses(int day, int sum, char* type){
    this->day = day;
    this->sum = sum;
    this->type = new char[strlen(type)+1];
    strcpy(this->type, type);
}

FamilyExpenses:: FamilyExpenses( const FamilyExpenses& fe){
   this->day = fe.day;
   this->sum = fe.sum;
   this->type = new char[strlen(fe.type)+1];
   strcpy(this->type, fe.type);

}

FamilyExpenses::~FamilyExpenses() {
    if (this->type != nullptr)
        {
            delete[] this->type;
            this->type = nullptr;
        }
}

int FamilyExpenses:: getDay(){
    return this->day;
}

int FamilyExpenses:: getSum(){
    return this->sum;
}

char* FamilyExpenses:: getType(){
    return this->type;
}

void FamilyExpenses:: setDay(int a_day) {
    this->day = a_day;
}

void FamilyExpenses:: setSum(int a_sum) {
    this->sum = a_sum;
}

void FamilyExpenses:: setType(char *a_type) {
    if (this->type != nullptr)
        {
            delete [] this->type;
            this->type = nullptr;
        }
    this->type = new char[strlen(a_type)+1];
    strcpy(this->type, a_type);
}

FamilyExpenses& FamilyExpenses:: operator=(const FamilyExpenses& fe){
    this->setType(fe.type);
    this->setDay(fe.day);
    this->setSum(fe.sum);
    return *this;
}

bool FamilyExpenses:: operator==(const FamilyExpenses& fe) {
    return (this->day == fe.day) && (this->sum = fe.sum) && (strcmp(this->type, fe.type) == 0);
}


