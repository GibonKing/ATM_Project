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

double ChildAccount::maxBorrowable() const
{
	return 0;
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

bool ChildAccount::canDeposit(const double& amount) const 
{
	return (amount <= maximumPaidIn_ && amount >= minimumPaidIn_);
}

bool ChildAccount::canWithdraw(const double& amount) const
{
	return false;
}

bool ChildAccount::canTransferOut(const double& amt, string& trOutError) const
{
	//IF AN ERROR SHOULD BE SHOWN
	if (!canWithdraw(amt))
		trOutError = "ERROR: CANNOT TRANSFER MONEY FROM A CHILD ACCOUNT";

	return canWithdraw(amt);
}

bool ChildAccount::canTransferIn(const double& amt, string& trInError) const
{
	//IF AN ERROR SHOULD BE SHOWN
	if (!canDeposit(amt))
		trInError = "ERROR: TARGET ACCOUNT CAN RECIEVE NO MORE THAN \234" + to_string((int)getMaximumPaidIn()) + " AND NO LESS THAN \234" + to_string((int)getMinimumPaidIn()) + " PER TRANSACTION";

	return canDeposit(amt);
}

istream& ChildAccount::getAccountDataFromStream(istream& is) {
	//get BankAccount details from stream
	SavingsAccount::getAccountDataFromStream(is);
	is >> minimumPaidIn_;
	is >> maximumPaidIn_;
	return is;
}

ostream& ChildAccount::putAccountDetailsInStream(ostream& os) const
{
	SavingsAccount::putAccountDetailsInStream(os);
	os << minimumPaidIn_ << "\n";
	os << maximumPaidIn_ << "\n";
	return os;
}