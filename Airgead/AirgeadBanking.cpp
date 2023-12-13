/*
* Ryan Carter
* 02/04/2023
* Project 2: Airgead Banking
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include "AirgeadBanking.h"

//calculates balance with monthly deposit
double AirgeadBanking::calcBalanceWithDeposit(double t_investment, double t_deposit, double t_interest, int t_years)
{
    //prints header
    balanceHeader(true);

    //declares and initializes vars
    double m_interestAmount = 0;
    double m_balance = t_investment;

    //iterates through amount of years and then through each month
    for (int i = 0; i < t_years; ++i)
    {
        //adds all monthly interest to yearly interest var
        double m_yearlyInterest = 0;
        for (int j = 0; j < 12; ++j)
        {
            //calculates monthly (and yearly) interest and balance
            m_interestAmount = (m_balance + t_deposit) * ((t_interest / 100) / 12);
            m_yearlyInterest += m_interestAmount;
            m_balance += m_interestAmount + t_deposit;
        }

        //prints current year info
        printDetails(i + 1, m_balance, m_yearlyInterest);
    }

    //prompts user for more inputs
    cout << endl << "Press Enter to continue . . ." << endl;

    //returns balance
    return m_balance;
}

//calculates balance without monthly deposit
double AirgeadBanking::calcBalanceWithoutDeposit(double t_investment, double t_interest, int t_years)
{
    //prints header
    balanceHeader(false);

    //declares and initializes vars
    double m_interestAmount = 0;
    double m_balance = t_investment;

    //iterates through amount of years and then through each month
    for (int i = 0; i < t_years; ++i)
    {
        //adds all monthly interest to yearly interest var
        double m_yearlyInterest = 0;
        for (int j = 0; j < 12; ++j)
        {
            //calculates monthly (and yearly) interest and balance
            m_interestAmount = (m_balance) * ((t_interest / 100) / 12);
            m_yearlyInterest += m_interestAmount;
            m_balance += m_interestAmount;
        }

        //prints current year info
        printDetails(i + 1, m_balance, m_yearlyInterest);
    }

    //returns balance
    return m_balance;
}

//prints year, balance, and interest
void AirgeadBanking::printDetails(int t_year, double t_balance, double t_interest)
{
    //converts balance and year to string so numbers will be aligned
    std::string m_balString = std::to_string(t_balance);
    std::string m_yearString = std::to_string(t_year);

    //prints statement
    cout << "  " << t_year << printChar((24 - m_balString.size() - m_yearString.size()), ' ') << fixed << setprecision(2) << 
        "$" << t_balance << printChar(18, ' ') << "$" << t_interest << endl;
}

//prints a character a certain amount of times
string AirgeadBanking::printChar(int t_amount, char t_char)
{
    //declares + initializes string var
    string m_list = "";

    //iterates through a specified num of tiemes
    for (int i = 0; i < t_amount; ++i)
    {
        //prints char
        m_list += t_char;
    }

    //returns string var
    return m_list;
}

//displays user input menu
void AirgeadBanking::displayMenu(bool t_displayStats, double t_amount, double t_deposit, double t_interest, int t_years)
{
    //prints header without input vals
    if (!t_displayStats)
    {
        //header
        cout << printChar(36, '*') << endl << printChar(12, '*') << " Data Input " << printChar(12, '*') << endl;
        cout << printChar(2, '*') << " (Exit using negative numbers.) " << printChar(2, '*') << endl << printChar(36, '*') << endl;

        //body
        cout << "Initial Investment Amount: " << endl << "Monthly Deposit: " << endl << "Annual Interest: " << endl <<
            "Number of years: " << endl << "Press Enter to continue . . . " << endl;
    }
    //prints header with input vals
    else
    {
        //header
        cout << endl << printChar(36, '*') << endl << printChar(12, '*') << " Data Input " << printChar(12, '*') << endl << printChar(36, '*') << endl;

        //body with user vals
        cout << "Initial Investment Amount:  $" << fixed << setprecision(2) << t_amount << endl;
        cout << "Monthly Deposit:  $" << t_deposit << endl;
        cout << "Annual Interest:  %" << fixed << setprecision(0) << t_interest << endl;
        cout << "Number of years:  " << t_years << endl;
        cout << "Press Enter to continue . . . " << endl << endl;
    }
}

//prints header for balance and interest
void AirgeadBanking::balanceHeader(bool t_hasDeposit)
{
    //prints header for monthly deposit calculation
    if (t_hasDeposit)
    {
        cout << endl << endl << "  Balance and Interest With Additional Monthly Deposits" << endl << printChar(58, '=') << endl;
        cout << " Year" << printChar(6, ' ') << "Year End Balance" << printChar(5, ' ') << "Year End Earned Interest" << endl <<
            printChar(58, '-') << endl;
    }
    //prints header for calculation without monthly deposit
    else
    {
        cout << " Balance and Interest Without Additional Monthly Deposits" << endl << printChar(58, '=') << endl;
        cout << " Year" << printChar(6, ' ') << "Year End Balance" << printChar(5, ' ') << "Year End Earned Interest" << endl <<
            printChar(58, '-') << endl;
    }
}