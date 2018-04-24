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

bool CurrentAccount::canTransferOut(const double& amt, string& trOutError) const
{
	//IF AN ERROR SHOULD BE SHOWN
	if (!canWithdraw(amt))
		trOutError = "ERROR: AMOUNT WOULD EXCEED YOUR OVERDRAFT LIMIT";

	return canWithdraw(amt);
}


const string CurrentAccount::prepareFormattedAccountDetails() const
{
	assert(getAccountType(getAccountNumber()[0]) != "UNKOWN");
	ostringstream os;
	double availableFunds = getBalance() + getOverdraftLimit();

	os << BankAccount::prepareFormattedAccountDetails();
	os << "\n      OVERDRAFT LIMIT: \234" << setw(10) << fixed << setprecision(2) << getOverdraftLimit();
	os << "\n      AVAILABLE FUNDS: \234" << setw(10) << fixed << setprecision(2) << availableFunds;
	os << "\n      ----------------------------------------";

	return os.str();
}

const string CurrentAccount::prepareFormattedMiniAccountDetails() const
{
	assert(getAccountType(getAccountNumber()[0]) != "UNKNOWN");
	ostringstream os;
	double availableFunds = getBalance() + getOverdraftLimit();

	os << BankAccount::prepareFormattedMiniAccountDetails();
	os << "\n      AVAILABLE FUNDS: \234" << setw(10) << fixed << setprecision(2) << availableFunds;
	os << "\n      ----------------------------------------";

	return os.str();
}

istream& CurrentAccount::getAccountDataFromStream(istream& is) {
	//get BankAccount details from stream
	BankAccount::getAccountDataFromStream(is);
	is >> overdraftLimit_;
	return is;
}

ostream& CurrentAccount::putAccountDetailsInStream(ostream & os) const
{
	BankAccount::putAccountDetailsInStream(os);
	os << overdraftLimit_ << "\n";
	return os;
}
