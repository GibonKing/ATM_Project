//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)

#include "ISAAccount.h"

ISAAccount::ISAAccount()
	: SavingsAccount()
{

}

ISAAccount::~ISAAccount()
{

}

double ISAAccount::getMaximumYearlyDeposit() const
{
	return maximumYearlyDeposit_;
}

double ISAAccount::getCurrentYearlyDeposit() const
{
	return currentYearlyDeposit_;
}

Date ISAAccount::getEndDepositPeriod() const
{
	return endDepositPeriod_;
}

void ISAAccount::updateCurrentYearlyDeposit(const double& amount)
{
	currentYearlyDeposit_ += amount;
}

const string ISAAccount::prepareFormattedAccountDetails() const
{
	assert(getAccountType(getAccountNumber()[0]) != "UNKOWN");
	ostringstream os;

	os << SavingsAccount::prepareFormattedAccountDetails();
	os << "\n      MAXIMUM YEARLY DEPOSIT: \234" << setw(10) << getMaximumYearlyDeposit();
	os << "\n      CURRENT YEARLY DEPOSIT: \234" << setw(10) << getCurrentYearlyDeposit();
	os << "\n      END DEPOSIT PERIOD:         " << endDepositPeriod_.toFormattedString();

	return os.str();
}

istream& ISAAccount::getAccountDataFromStream(istream& is) {
	//get BankAccount details from stream
	SavingsAccount::getAccountDataFromStream(is);
	is >> maximumYearlyDeposit_;
	is >> currentYearlyDeposit_;
	is >> endDepositPeriod_;
	return is;
}

bool ISAAccount::canDeposit(const double& amount) const
{
	return (currentYearlyDeposit_ + amount <= maximumYearlyDeposit_);
}

void ISAAccount::recordDeposit(double amountToDeposit) 
{
	updateCurrentYearlyDeposit(amountToDeposit);
	BankAccount::recordDeposit(amountToDeposit);
}

