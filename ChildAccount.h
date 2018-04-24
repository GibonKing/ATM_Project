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

	//assessors
	double getMaximumPaidIn() const;
	double getMinimumPaidIn() const;

	virtual bool canDeposit(const double&) const;
	virtual bool canWithdraw(const double&) const;

	virtual bool canTransferOut(const double&, string&) const;
	virtual bool canTransferIn(const double&, string&) const;

	virtual const string prepareFormattedAccountDetails() const;

	//File input/output
	virtual istream& getAccountDataFromStream(istream& is);
	virtual ostream& putAccountDetailsInStream(ostream& os) const;

private:
	double maximumPaidIn_;
	double minimumPaidIn_;
};

#endif // !1
