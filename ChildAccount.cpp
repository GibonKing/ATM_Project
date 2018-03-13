//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)

#include "ChildAccount.h"

//---------------------------------------------------------------------------
//BankAccount: class implementation
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//public member functions
//---------------------------------------------------------------------------

//____constructors & destructors

ChildAccount::ChildAccount()
	: SavingsAccount::SavingsAccount(), maximumPaidIn_(0.0), minimumPaidIn_(0.0)
{}
ChildAccount::~ChildAccount()
{}


//____other public member functions

double ChildAccount::getMaximumPaidIn() const {
	return maximumPaidIn_;
}
double ChildAccount::getMinimumPaidOut() const {
	return minimumPaidIn_;
}