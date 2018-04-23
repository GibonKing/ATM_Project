#ifndef ChildAccountH
#define ChildAccountH

//---------------------------------------------------------
//ChildAccount: class declaration
//---------------------------------------------------------

#include "SavingsAccount.h"

class ChildAccount : public SavingsAccount {
public:
	ChildAccount();
	~ChildAccount();
	double getMaximumPaidIn() const;
	double getMinimumPaidIn() const;
	virtual const string prepareFormattedAccountDetails() const;
	virtual istream& getAccountDataFromStream(istream& is);
	virtual bool canDeposit(const double&) const;
	virtual bool canWithdraw(double amount) const;
private:
	double maximumPaidIn_;
	double minimumPaidIn_;
};

#endif // !1
