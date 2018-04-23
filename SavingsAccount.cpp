//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)

#include "SavingsAccount.h"

SavingsAccount::SavingsAccount()
	: BankAccount()
{

}

SavingsAccount::~SavingsAccount()
{

}

double SavingsAccount::getMinimumBalance() const
{
	return minimumBalance;
}

double SavingsAccount::maxBorrowable() const
{
	return (getBalance() - getMinimumBalance());
}

const string SavingsAccount::prepareFormattedAccountDetails() const
{
	assert(getAccountType(getAccountNumber()[0]) != "UNKOWN");

	ostringstream os;
	os << BankAccount::prepareFormattedAccountDetails();
	os << "\n      MINIMUM BALANCE: \234" << setw(10) << getMinimumBalance();

	return os.str();
}

const string SavingsAccount::prepareFormattedMiniAccountDetails() const
{
	assert(getAccountType(getAccountNumber()[0]) != "UNKNOWN");
	ostringstream os;
	double availableFunds = getBalance() - getMinimumBalance();

	os << BankAccount::prepareFormattedMiniAccountDetails();
	os << "\n      AVAILABLE FUNDS: \234" << setw(10) << fixed << setprecision(2) << availableFunds << endl;

	return os.str();
}

istream& SavingsAccount::getAccountDataFromStream(istream& is) {
	//get BankAccount details from stream
	BankAccount::getAccountDataFromStream(is);
	is >> minimumBalance;
	return is;
}
