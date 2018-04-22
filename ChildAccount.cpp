#include "ChildAccount.h"

ChildAccount::ChildAccount()
	: SavingsAccount::SavingsAccount()
{}
ChildAccount::~ChildAccount()
{}

double ChildAccount::getMaximumPaidIn() const{
	return maximumPaidIn_;
}

double ChildAccount::getMinimumPaidIn() const{
	return minimumPaidIn_;
}

const string ChildAccount::prepareFormattedAccountDetails() const
{
	assert(getAccountType(getAccountNumber()[0]) != "UNKOWN");
	ostringstream os;

	os << SavingsAccount::prepareFormattedAccountDetails();
	os << "\n      MINIMUM PAID IN: \234" << setw(10) << getMinimumPaidIn();
	os << "\n      MAXIMUM PAID IN: \234" << setw(10) << getMaximumPaidIn();
	os << "\n      ----------------------------------------";

	return os.str();
}

istream& ChildAccount::getAccountDataFromStream(istream& is) {
	//get BankAccount details from stream
	SavingsAccount::getAccountDataFromStream(is);
	is >> minimumPaidIn_;
	is >> maximumPaidIn_;
	return is;
}

bool ChildAccount::canDeposit(const double& amount) const 
{
	return (amount <= maximumPaidIn_ && amount >= minimumPaidIn_);
}