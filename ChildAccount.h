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
	virtual ostream& putAccountDetailsInStream(ostream& os) const;

	virtual bool canDeposit(const double&) const;
	virtual bool canWithdraw(double amount) const;

	virtual bool canTransferOut(const double&, string&);
	virtual bool canTransferIn(const double&, string&);

private:
	double maximumPaidIn_;
	double minimumPaidIn_;
};

#endif // !1
