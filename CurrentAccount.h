//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)

#ifndef CurrentAccountH
#define CurrentAccountH

//---------------------------------------------------------------------------
//CurrentAccount: class declaration
//---------------------------------------------------------------------------

//#include "Date.h"
//#include "Transaction.h"
//#include "TransactionList.h"
#include "BankAccount.h"

//#include <fstream>
//#include <cassert>
//using namespace std;


class CurrentAccount :public BankAccount {
public:
	double getOverdraftLimit();
private:
	double overdraftLimit;
};
#endif