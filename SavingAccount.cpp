//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)

#include "SavingsAccount.h"

//---------------------------------------------------------------------------
//BankAccount: class implementation
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//public member functions
//---------------------------------------------------------------------------

//____constructors & destructors

SavingsAccount::SavingsAccount()
	: BankAccount::BankAccount(), minimumBalance_(0.0)
{}
SavingsAccount::~SavingsAccount()
{}


//____other public member functions

double SavingsAccount::getMinimumBalance() const{
	return minimumBalance_;
}