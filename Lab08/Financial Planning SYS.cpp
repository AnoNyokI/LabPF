#include <iostream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

void displayData(int startingAge, int numOfYears,double lumpSumAmount, double yearlyAmount, double interestRate)
{
    cout << "Starting Age = " << startingAge << endl;
    cout << "Number of Years = " << numOfYears << endl;
    cout << "Lump Sum Amount = " << lumpSumAmount << endl;
    cout << "Yearly Amount = " << yearlyAmount << endl;
    cout << "Interest Rate (%) = " << interestRate << endl;
    cout << endl;
}

void changeData(int& startingAge, int& numOfYears,double& lumpSumAmount, double& yearlyAmount, double& interestRate)
{
    cout << "Starting Age => "; cin >> startingAge;
    cout << "Nunber of Years => "; cin >> numOfYears;
    cout << "Lump Sum Amount => "; cin >> lumpSumAmount;
    cout << "Yearly Amount => "; cin >> yearlyAmount;
    cout << "Interest Rate (%) => "; cin >> interestRate;
    cout << endl;
}

double getCashWithInterest(double cash, double interestRate)
{ 
    return cash + cash * interestRate / 100.0; 
}

void displayAge(int age)
{
    cout.width(3);
    cout << age;
}

void displayCash(double cash)
{
    cout.width(15);
    cout.precision(2);
    cout.setf(ios::fixed);
    cout << cash;
}

void displayOneLumpSumPlan(int ageStart, int numOfYears, double lumpSumAmount,double interestRate)
{
    cout << " Age | Lump Sum Plan  " << endl;
    cout << "-----+----------------" << endl;
    double cash = lumpSumAmount;
    int age = ageStart;

    while (age <= ageStart + numOfYears)
    {
        displayAge(age);
        cout << "  | ";
        displayCash(cash);
        cout << endl;
        cash = getCashWithInterest(cash, interestRate);
        ++age;
    } 
    cout << endl;
}

void displayYearlyPlan(int ageStart, int numOfYears, double yearlyAmount,double interestRate)
{
    cout << " Age |     Yearly Plan" << endl;
    cout << "-----+----------------" << endl;
    double cash = yearlyAmount;
    int age = ageStart;

    while (age <= ageStart + numOfYears)
    {
        displayAge(age);
        cout << "  | ";
        displayCash(cash);
        cout << endl;
        cash = getCashWithInterest(cash, interestRate);
        ++age;
        cash += yearlyAmount;
    } 
    cout << endl;
}

void displayComparison(int ageStart, int numOfYears, double lumpSumAmount, double yearlyAmount,double interestRate)
{
    cout << " Age |  Lump Sum Plan        Yearly Plan" << endl;
    cout << "-----+----------------------------------" << endl;
    double yearlycash = yearlyAmount;
    double lumpsumcash = lumpSumAmount;
    int age = ageStart;

    while (age <= ageStart + numOfYears)
    {
        displayAge(age);
        cout << "  | ";
        displayCash(lumpsumcash);
        cout << " ";
        displayCash(yearlycash);
        cout << endl;
        yearlycash = getCashWithInterest(yearlycash, interestRate);
        lumpsumcash = getCashWithInterest(lumpsumcash, interestRate);
        ++age;
        yearlycash += yearlyAmount;
    } 
    cout << endl;

    if(yearlycash > lumpsumcash)
    {
        cout << "You are advised to choose Yearly Plan\n\n";
    }

    if(lumpsumcash > yearlycash)
    {
        cout << "You are advised to choose Lump Sum Plan\n\n";
    }
}

void displayMenu()
{
    system("cls");
    cout << "+---------------------------------------------+" << endl;
    cout << "|           Golden Years Finance Inc.         |" << endl;      
    cout << "|=============================================|" << endl;
    cout << "| Select:                                     |" << endl;
    cout << "| 1 => Display Data                           |" << endl;
    cout << "| 2 => Change Data                            |" << endl;
    cout << "|---------------------------------------------|" << endl;
    cout << "| 3 => Display One Lump Sum Withdrawal Plan   |" << endl;
    cout << "| 4 => Display Yearly Withdrawal Plan         |" << endl;
    cout << "| 5 => Compare Both Plans                     |" << endl;
    cout << "|---------------------------------------------|" << endl;
    cout << "| Q => Quit                                   |" << endl;
    cout << "+---------------------------------------------+" << endl;
    cout << endl;
    cout << "Choice => ";
}

int main()
{
    int ageStart = 55;
    int numOfYears = 20;
    double lumpSumAmount = 400000;
    double yearlyAmount = 25000;
    double interestRate = 5;
    char choice;
    bool done = false;

    do {
        displayMenu();
        cin >> choice;
        choice = toupper(choice);
        cout << endl;

        switch (choice)
        {
            case '1': displayData(ageStart,numOfYears,lumpSumAmount,yearlyAmount,interestRate); break;
            case '2': changeData(ageStart,numOfYears,lumpSumAmount,yearlyAmount,interestRate); break;
            case '3': displayOneLumpSumPlan(ageStart,numOfYears,lumpSumAmount,interestRate); break;
            case '4': displayYearlyPlan(ageStart,numOfYears,yearlyAmount,interestRate); break;
            case '5': displayComparison(ageStart,numOfYears,lumpSumAmount,yearlyAmount,interestRate); break;
            case 'Q':
            done = true;
            break;
            default:
            cout << "Invalid selection, try again!" << endl;
            cout << endl;
            break;
        }
        system("pause");
    } while (!done);

    cout << endl;
    cout << "Good Bye!" << endl;
}