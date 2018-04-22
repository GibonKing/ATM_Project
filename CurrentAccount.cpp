//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)

#include "CurrentAccount.h"

CurrentAccount::CurrentAccount()
	: BankAccount()
{

}

CurrentAccount::~CurrentAccount()
{

}

double CurrentAccount::getOverdraftLimit() const
{
	return overdraftLimit_;
}

double CurrentAccount::maxBorrowable() const
{
	return (getBalance() + getOverdraftLimit());
}

const string CurrentAccount::prepareFormattedAccountDetails() const
{
	assert(getAccountType(getAccountNumber()[0]) != "UNKOWN");
	ostringstream os;

	os << BankAccount::prepareFormattedAccountDetails();
	os << "\n      OVERDRAFT LIMIT: \234" << setw(10) << getOverdraftLimit();
	os << "\n      ----------------------------------------";

	return os.str();
}

istream& CurrentAccount::getAccountDataFromStream(istream& is) {
	//get BankAccount details from stream
	BankAccount::getAccountDataFromStream(is);
	is >> overdraftLimit_;
	return is;
}