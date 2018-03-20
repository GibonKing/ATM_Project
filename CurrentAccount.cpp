#include "CurrentAccount.h"

//---------------------------------------------------------------------------
//CurrentAccount: class implementation
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//public member functions
//---------------------------------------------------------------------------

//____constructors & destructors

CurrentAccount::CurrentAccount()
	: BankAccount(), overdraftLimit(100.0)
{}
CurrentAccount::~CurrentAccount()
{}

//____other public member functions

double CurrentAccount::getOverdraftLimit() const
{
	return overdraftLimit;
}

double CurrentAccount::maxBorrowable() const
{
	return (getBalance() + getOverdraftLimit());
}

const string CurrentAccount::prepareFormattedAccountDetails() const
{
	assert(getAccountType(getAccountNumber()[0]) != "UNKNOWN");
	ostringstream os;

	os << BankAccount::prepareFormattedAccountDetails();
	os << "\n      OVERDRAFT LIMIT: \234" << setw(10) << getOverdraftLimit();
	os << "\n      ----------------------------------------";
	return os.str();
}



//---------------------------------------------------------------------------
//private member functions
//---------------------------------------------------------------------------
