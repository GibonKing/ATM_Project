//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)

#ifndef SavingsAccountH
#define SavingsAccountH

//---------------------------------------------------------------------------
//SavingsAccount: class declaration
//---------------------------------------------------------------------------

//#include "Date.h"
//#include "Transaction.h"
//#include "TransactionList.h"
#include "BankAccount.h"

//#include <fstream>
//#include <cassert>
//using namespace std;


class SavingsAccount :public BankAccount {
public:
	SavingsAccount();
	~SavingsAccount();
	double getMinimumBalance() const;
private:
	double minimumBalance_;
};
#endif