/*
* Ryan Carter
* 02/04/2023
* Project 2: Airgead Banking
*/

//#define guard
#ifndef AIRGEAD_AIRGEADBANKING_H_
#define AIRGEAD_AIRGEADBANKING_H_

//creates a class and its necessary functions
class AirgeadBanking
{
	public:
		double calcBalanceWithDeposit(double t_investment, double t_deposit, double t_interest, int t_years);
		double calcBalanceWithoutDeposit(double t_investment, double t_interest, int t_years);
		void printDetails(int t_year, double t_balance, double t_interest);
		string printChar(int t_amount, char t_char);
		void displayMenu(bool t_displayStats, double t_amount = 0, double t_deposit = 0, double t_interest = 0, int t_years = 0);
		void balanceHeader(bool t_hasDeposit);

};

#endif //AIRGEAD_AIRGEADBANKING_H_