#include "UI.h"
#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

UI:: UI()= default;

UI:: UI(const Service& S){
    s = S;

}

UI:: ~UI()= default;

void UI::showMenu() {
    cout<<endl;
    cout<<"1.Add an expense for the current day into the list"<<endl;
    cout<<"2.Insert an expense into the list"<<endl;
    cout<<"3.Show all expenses"<<endl;
    cout<<"4.Delete what you want"<<endl;
    cout<<"5.Show all expenses of a certain type "<<endl;
    cout<<"6.Show all expenses of a certain type and above sum"<<endl;
    cout<<"7.Show all expenses of a certain type and a given sum"<<endl;
    cout<<"8.Show the total sum of expenses of a certain type "<<endl;
    cout<<"9. Show max sum of a day"<<endl;
    cout<<"a. Show sums spent everyday in descending order"<<endl;
    cout<<"b. Show sums spent everyday for a type in a.o."<<endl;
    cout<<"c. Filter type"<<endl;
    cout<<"d. Filter type below sum"<<endl;
    cout<<"e. Filter type exact sum"<<endl;
    cout<<"z.Exit"<<endl;
}

void UI:: Menu()
    {
       char option;
       bool run = true;
        while (run)
            {   this->showMenu();
                cout<<"Select option:";
                cin>>option;
                switch (option){
                    case '1':
                        this->handleAddExpense();
                        break;
                    case '2':
                        this->handleInsertExpense();
                        break;
                    case '3':
                        this->handleShowAllExpenses();
                        break;
                    case '4':
                        this->handleDeleteWhatYouWant();
                        break;
                    case '5':
                        this->handleShowAllExpensesOfACertainType();
                        break;
                    case '6':
                        this->handleShowAllExpensesOfACertainTypeAndAboveSum();
                        break;
                    case '7':
                        this->handleShowExpensesOfTypeAndSum();
                        break;
                    case '8':
                        this->handleShowSumOfAType();
                        break;
                    case 'z':
                        run = false;
                        break;
                    case '9':
                        this->handleShowMaxSumOfDay();
                        break;
                    case 'a':
                        this->handleShowSumsAndDaysInDO();
                        break;
                    case 'b':
                        this->handleShowSumsAndDaysForTypeInAO();
                        break;
                    case 'c':
                        this->handleFilterType();
                        break;
                    case 'd':
                        this->handleFilterTypeBelowSum();
                        break;
                    case 'e':
                        this->handleFilterTypeExactSum();
                        break;
                    default:
                        cout<<"Unrecognized command. Try again:"<<endl;
                        break;
                }

            }
    }

void UI::handleAddExpense() {
    int a_sum;
    char *a_type;
    cout << "Give a sum:";
    cin >> a_sum;
    cout << "Give a type: ";
    cin >> a_type;
    this->s.addExpenseOnCurrentDay(a_sum, a_type);
}

void UI::handleInsertExpense() {
    int day;
    int sum;
    char type[100];
    cout << "Give a day: ";
    cin >> day;
    cout << "Give sum: ";
    cin >> sum;
    cout << "Give a type: ";
    cin >> type;
    s.insertExpense(day, sum, type);
}

void UI::handleDeleteWhatYouWant(){
    int command;
    cout<< "Give command:";
    cin >> command;
    if (command == 1)
        {
            int day;
            cout<<"Give day";
            cin>>day;
            s.deleteExpensesOfAGivenDay(day);
        }
    else if (command == 2)
        {
            int first_day;
            int last_day;
            cout<<"Give first day:";
            cin>>first_day;
            cout<<"Give last day:";
            cin>>last_day;
            s.deleteExpensesInInterval(first_day,  last_day);
        }
    else if (command == 3)
        {
            char type[100];
            cout << "Give the type of the expense: ";
            cin >> type;
            s.deleteExpensesOfAType(type);
        }

}


void UI:: handleShowAllExpenses(){

    int size = s.getSize();
    for (int i = 0; i < size ; i++)
        {
            cout<<s.getAll()[i]<<endl;
        }
}

void UI:: handleShowAllExpensesOfACertainType() {
    char type[100];
    cout<< "Give type: ";
    cin >> type;
    for (FamilyExpenses i: s.getExpensesOfAType(type))
        cout<<i<<endl;
}

void UI:: handleShowAllExpensesOfACertainTypeAndAboveSum() {
    int a_sum;
    char type[100];
    cout << "Give the type of the expense: ";
    cin >> type;
    cout << "Give a sum:";
    cin >> a_sum;
    for (FamilyExpenses i: s.getExpensesOfATypeAndAboveSum(type, a_sum))
        cout<<i<<endl;
}

void UI:: handleShowExpensesOfTypeAndSum(){
    int a_sum;
    char type[100];
    cout << "Give the type of the expense: ";
    cin >> type;
    cout << "Give a sum:";
    cin >> a_sum;
    for (FamilyExpenses i: s.getExpensesOfTypeAndSum(type, a_sum))
        cout<<i<<endl;

    }

void UI::handleShowSumOfAType() {
    char type[100];
    cout << "Give type:";
    cin >> type;
    cout << s.getSumOfAType(type);
}

void UI:: handleShowMaxSumOfDay(){
    cout << "Ziua in care s-au cheltuit cei mai multi bani este: "<< s.getMaxSumOfADay()<<endl;
}

void UI:: handleShowSumsAndDaysInDO(){
    vector<pair<int, int>>S = s.getSumsAndDaysInDO();
    for( int i = 0; i<S.size(); i++){
        cout << "  Day is: " <<S[i].first << " and sum spent is: " << S[i].second << endl;
    }

}

void UI:: handleShowSumsAndDaysForTypeInAO(){
    char type[100];
    cout<< "Give the type: ";
    cin >> type;
    vector<pair<int, int>> S = s.getSumsAndDaysForTypeInAO(type);
    cout << "These are the sums spent everyday for type: "<<type<<endl;
    for (int i = 0; i <  S.size(); i++)
        cout<<" Day is: "<<S[i].first << " and sum spent is: "<<S[i].second <<endl;
}

void UI:: handleFilterType(){
    char type[100];
    cout << "Give a type: ";
    cin >> type;
    for (FamilyExpenses i: s.deleteAllButType(type))
        s.deleteExpense(i);
}

void UI::handleFilterTypeBelowSum(){
    char type[100];
    int sum;
    cout<<"Give a type: ";
    cin >> type;
    cout << "Give a sum: ";
    cin >> sum;
    s.deleteAllButTypeBelowSum(type, sum);
}

void UI:: handleFilterTypeExactSum(){
    char type[100];
    int sum;
    cout<<"Give a type: ";
    cin >> type;
    cout << "Give a sum: ";
    cin >> sum;
    s.deleteAllButTypeExactSum(type, sum);
}






