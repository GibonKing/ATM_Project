//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)

#ifndef ChildAccountH
#define ChildAccountH

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
	double getMaximumPaidIn();
	double getMinimumPaidOut();
private:
	double maximumPaidIn;
	double minimumPaidOut;
};
#endif