//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)

#include "ISAAccount.h"

//---------------------------------------------------------------------------
//BankAccount: class implementation
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//public member functions
//---------------------------------------------------------------------------

//____constructors & destructors

ISAAccount::ISAAccount()
	: SavingsAccount::SavingsAccount(), maximumYearlyDeposit_(0.0), currentYearlyDeposit_(0.0), endDepositPeriod_()
{}
ISAAccount::~ISAAccount()
{}


//____other public member functions

double ISAAccount::getMaximumYearlyDeposit() const {
	return maximumYearlyDeposit_;
}
double ISAAccount::getCurrentYearlyDeposit() const {
	return currentYearlyDeposit_;
}
Date ISAAccount::getEndDepositPeriod() const {
	return endDepositPeriod_;
}

//---------------------------------------------------------------------------
//private support member functions
//---------------------------------------------------------------------------

void ISAAccount::updateCurrentYearlyDeposit(double a) {

}