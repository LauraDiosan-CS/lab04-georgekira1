#include "Service.h"
#include<iostream>
#include<cstring>
#include<vector>
#include<ctime>
using namespace std;

Service:: Service(){

}

Service:: Service(const Repo& R)
    {
        r = R;
    }

Service:: ~Service(){

}

int Service:: findExpense(const FamilyExpenses& fe){
    return r.findExpense(fe);
}

void Service:: addFamilyExpense(const FamilyExpenses& fe){
    return r.addFamilyExpense(fe);
}

void Service:: deleteExpense(const FamilyExpenses& fe){
    return r.deleteExpense(fe);
}

void Service:: updateExpense(int position, const FamilyExpenses &fe) {
    return r.updateExpense(position, fe);
}

int Service:: getSize() {
    return r.getSize();
}

FamilyExpenses* Service:: getAll() {
    return r.getAll();
}


void Service:: addExpenseOnCurrentDay(int sum, char* type){
    time_t now = time(NULL);
    tm localTime;
    localtime_s(&localTime, &now);
    int local_day = (&localTime)-> tm_mday;
    FamilyExpenses fe(local_day, sum, type);
    r.addFamilyExpense(fe);
}
void Service:: insertExpense(int day, int sum, char type[100]){
    FamilyExpenses fe(day, sum, type);
    r.addFamilyExpense(fe);
}
void Service:: deleteExpensesOfAGivenDay(int day){
    vector<FamilyExpenses> to_delete;
    for (int i = 0; i < r.getSize(); i++)
    {
        if (r.getAll()[i].getDay() == day)
        {
            to_delete.push_back(r.getAll()[i]);
        }
    }
    for (int i = 0; i<to_delete.size(); i++)
        r. deleteExpense(to_delete[i]);
}

void Service:: deleteExpensesInInterval(int first_day, int last_day) {
    vector<FamilyExpenses> to_delete;
    for (int i = 0; i < r.getSize(); i++) {
        if (r.getAll()[i].getDay() >= first_day && r.getAll()[i].getDay() <= last_day)
        {
            to_delete.push_back(r.getAll()[i]);
        }
    }
    for (int i = 0; i < to_delete.size(); i++)
        r.deleteExpense(to_delete[i]);

}

void Service:: deleteExpensesOfAType(char a_type[100]){
    vector<FamilyExpenses> to_delete;
    for (int i = 0; i<r.getSize(); i++)
    {
        if (strcmp(r.getAll()[i].getType(), a_type) == 0)
            to_delete.push_back(r.getAll()[i]);
    }
    for (int i =0; i<to_delete.size(); i++)
        r.deleteExpense(to_delete[i]);
}

vector<FamilyExpenses> Service:: getExpensesOfAType(char a_type[100]){
    vector <FamilyExpenses> to_show;
    int ok = 1;
    for(int i = 0; i< r.getSize(); i++)
        {
            if (strcmp(r.getAll()[i].getType(), a_type) == 0) {
                to_show.push_back(r.getAll()[i]);
                ok = 0;
            }
        }
    if (ok)
    {
        cout<<" There is no expense of that type! "<<endl;
    } else{
        return to_show;
    }

}
vector<FamilyExpenses> Service:: getExpensesOfATypeAndAboveSum(char a_type[100], int sum){
    vector <FamilyExpenses> to_show;
    int ok = 1;
    for(int i = 0; i< r.getSize(); i++)
    {
        if (strcmp(r.getAll()[i].getType(), a_type) == 0 && r.getAll()[i].getSum() > sum) {
            to_show.push_back(r.getAll()[i]);
            ok =0;
        }
    }
    if (ok)
    {
        cout<<" There is no expense of that type and more expensive than given sum! "<<endl;
    } else{
        return to_show;
    }
}

vector <FamilyExpenses> Service:: getExpensesOfTypeAndSum(char a_type[100], int sum){
    vector <FamilyExpenses> to_show;
    int ok = 1;
    for(int i = 0; i< r.getSize(); i++)
    {
        if (strcmp(r.getAll()[i].getType(), a_type) == 0 && r.getAll()[i].getSum() == sum) {
            to_show.push_back(r.getAll()[i]);
            ok =0;
        }
    }
    if (ok)
    {
        cout<<" There is no expense of that type and sum! "<<endl;
    } else{
        return to_show;
    }
}


int Service:: getSumOfAType(char a_type[100]) {
    int sum = 0;
    for (int i = 0; i< r.getSize(); i++)
        {
            if (strcmp(r.getAll()[i].getType(), a_type) == 0)
                sum+=r.getAll()[i].getSum();
        }
    return sum;
}

int Service:: getMaxSumOfADay(){
   int sum[100];
   int nr = 0;
  for (int i = 0; i< r.getSize(); i++)
    {
        int a_sum = r.getAll()[i].getSum();
        for (int j = i+1; j < r.getSize(); j++ )
            {
                if (r.getAll()[i].getDay() == r.getAll()[j].getDay())
                    a_sum += r.getAll()[j].getSum();
            }
        sum[nr] = a_sum;
        sum[nr+1] = r.getAll()[i].getDay();
        nr += 2;

    }
  int max = sum[0];
  for (int a=0; a < nr ; a+=2 )
    {
        if (sum[a] > max)
            max = sum[a];
    }
  for (int b = 0; b < nr; b++)
    {
        if (sum[b] == max)
            return sum[b+1];
    }

}

vector<pair<int, int>> Service :: getSumsAndDaysInDO(){
    vector<pair<int, int>> days_with_sums;
    vector<int> days;
    for (int i = 0; i < r.getSize(); i++)
        {   int found = 0;
            for (int j = 0; j < days.size(); j++)
                {
                    if (r.getAll()[i].getDay() == days[j])
                        found = 1;
                }
             if (found == 0)
                 days.push_back(r.getAll()[i].getDay());
        }
    for (int a = 0; a < days.size(); a++)
        {
            int a_sum = 0;
            for (int i = 0; i < r.getSize(); i++)
                {
                    if (days[a] == r.getAll()[i].getDay())
                        a_sum += r.getAll()[i].getSum();
                }
            days_with_sums.push_back(make_pair(days[a], a_sum));

        }
    sort(days_with_sums.begin(), days_with_sums.end(), [](auto& left, auto& right) {
        return left.second > right.second;
    });
    return days_with_sums;
}

vector<pair<int,int>> Service :: getSumsAndDaysForTypeInAO(char type[100]){
    vector<pair<int, int> > days_with_sums;
    vector<int> unique_days;
    for (int i = 0; i< r.getSize(); i++)
        {
            int found = 0;
            for ( int a = 0; a<unique_days.size(); a++)
                {
                    if (r.getAll()[i].getDay() == unique_days[a])
                        found = 1;
                }
            if ( found == 0)
                unique_days.push_back(r.getAll()[i].getDay());
        }
    for (int a = 0; a<unique_days.size(); a++)
        {
            int a_sum = 0;
            for (int i = 0; i<r.getSize(); i++)
                {
                    if (unique_days[a] == r.getAll()[i].getDay() && strcmp(r.getAll()[i].getType(), type) == 0)
                        a_sum += r.getAll()[i].getSum();
                }
            days_with_sums.push_back(make_pair(unique_days[a], a_sum));
        }
    sort(days_with_sums.begin(), days_with_sums.end(), [](auto& left, auto& right) {
        return left.second < right.second;
    });
    return days_with_sums;
}

vector<FamilyExpenses> Service :: deleteAllButType(char* type){
    vector<FamilyExpenses> expenses_to_delete;
    for (int i = 0 ; i < r.getSize(); i++)
        {
            if (!(strcmp(r.getAll()[i].getType(), type) == 0))
                expenses_to_delete.push_back(r.getAll()[i]);
        }
    return expenses_to_delete;
}

void Service:: deleteAllButTypeBelowSum(char* type, int a_sum){
    vector <FamilyExpenses> expenses_to_delete;
    for (int i = 0; i< r.getSize(); i++)
        {
            if (!(strcmp(r.getAll()[i].getType(), type)==0) || r.getAll()[i].getSum() >= a_sum)
                expenses_to_delete.push_back(r.getAll()[i]);
        }
    for (FamilyExpenses i: expenses_to_delete) {
        deleteExpense(i);
    }
}

void Service:: deleteAllButTypeExactSum(char* type, int a_sum) {
    vector<FamilyExpenses> expenses_to_delete;
    for (int i = 0; i < r.getSize(); i++) {
        if (!(strcmp(r.getAll()[i].getType(), type) == 0) || !(r.getAll()[i].getSum() == a_sum))
            expenses_to_delete.push_back(r.getAll()[i]);
    }
    for (FamilyExpenses i: expenses_to_delete) {
        deleteExpense(i);
    }
}