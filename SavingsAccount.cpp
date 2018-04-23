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

bool SavingsAccount::canTransferOut(const double& amt, string& trOutError)
{
	//IF AN ERROR SHOULD BE SHOWN
	if (!canWithdraw(amt))
		trOutError = "ERROR: AMOUNT WOULD EXCEED YOUR MINIMUM BALANCE LIMIT";

	return canWithdraw(amt);
}

bool SavingsAccount::canTransferIn(const double& amt, string& trInError)
{
	//IF AN ERROR SHOULD BE SHOWN
	if (!canDeposit(amt))
		trInError = "ERROR: AMOUNT WOULD EXCEED TARGET ACCOUNT'S MAXIMUM BALANCE LIMIT";

	return canWithdraw(amt);
}


const string SavingsAccount::prepareFormattedAccountDetails() const
{
	assert(getAccountType(getAccountNumber()[0]) != "UNKOWN");
	ostringstream os;
	double availableFunds = getBalance() - getMinimumBalance();

	os << BankAccount::prepareFormattedAccountDetails();
	os << "\n      MINIMUM BALANCE: \234" << setw(10) << fixed << setprecision(2) << getMinimumBalance();
	os << "\n      AVAILABLE FUNDS: \234" << setw(10) << fixed << setprecision(2) << availableFunds << endl;
	os << "\n      ----------------------------------------";

	return os.str();
}

const string SavingsAccount::prepareFormattedMiniAccountDetails() const
{
	assert(getAccountType(getAccountNumber()[0]) != "UNKNOWN");
	ostringstream os;
	double availableFunds = getBalance() - getMinimumBalance();

	os << BankAccount::prepareFormattedMiniAccountDetails();
	os << "\n      AVAILABLE FUNDS: \234" << setw(10) << fixed << setprecision(2) << availableFunds;
	os << "\n      ----------------------------------------";

	return os.str();
}

istream& SavingsAccount::getAccountDataFromStream(istream& is) {
	//get BankAccount details from stream
	BankAccount::getAccountDataFromStream(is);
	is >> minimumBalance;
	return is;
}

ostream& SavingsAccount::putAccountDetailsInStream(ostream& os) const
{
	BankAccount::putAccountDetailsInStream(os);
	os << minimumBalance << "\n";
	return os;
}
