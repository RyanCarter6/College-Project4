/*
* Ryan Carter
* 02/04/2023
* Project 2: Airgead Banking
*/

#include <iostream>
#include <string>
using namespace std;
#include "AirgeadBanking.h"

int main()
{
    //declares bank object
    AirgeadBanking bank;

    //declares user vars
    double m_userInitialInvestment, m_userDeposit, m_userInterestRate;
    int m_userYears;
    string m_nextInput;

    //displays prompt for user input
    bank.displayMenu(false);

    //gets input for vars
    cin >> m_userInitialInvestment >> m_userDeposit >> m_userInterestRate;
    cin >> m_userYears;

    //gets next input
    getline(cin, m_nextInput);

    //ends program if user inputs a negative number
    while (m_userInitialInvestment >= 0 && m_userDeposit >= 0 && m_userInterestRate >= 0 && m_userYears >= 0)
    {
        //displays user input
        bank.displayMenu(true, m_userInitialInvestment, m_userDeposit, m_userInterestRate, m_userYears);

        //gets next input
        getline(cin, m_nextInput);

        //calculates balance and interest based on user input
        bank.calcBalanceWithoutDeposit(m_userInitialInvestment, m_userInterestRate, m_userYears);
        bank.calcBalanceWithDeposit(m_userInitialInvestment, m_userDeposit, m_userInterestRate, m_userYears);

        //gets next input
        getline(cin, m_nextInput);

        //displays prompt for user input
        bank.displayMenu(false);

        //gets next input for vars
        cin >> m_userInitialInvestment >> m_userDeposit >> m_userInterestRate;
        cin >> m_userYears;

        //gets next input
        getline(cin, m_nextInput);

    }

    //tells user program ended
    std::cout << endl << "Program ended due to a negative number." << endl;
    return 0;
}