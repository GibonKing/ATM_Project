//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)

#ifndef ISAAccountH
#define ISAAccountH

//---------------------------------------------------------------------------
//SavingsAccount: class declaration
//---------------------------------------------------------------------------

//#include "Date.h"
//#include "Transaction.h"
//#include "TransactionList.h"
//#include "BankAccount.h"
#include "SavingsAccount.h""

//#include <fstream>
//#include <cassert>
//using namespace std;


class ChildAccount :public SavingsAccount {
public:
	double getMaximumYearlyDeposit();
	double getCurrentYearlyDeposit();
	Date getEndDepositPeriod();
private:
	double maximumYearlyDeposit;
	double currentYearlyDeposit;
	double endDepositPeriod;
	void updateCurrentYearlyDeposit(double a);
};
#endif