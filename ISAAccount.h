//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)

#ifndef ISAAccountH
#define ISAAccountH

//---------------------------------------------------------------------------
//SavingsAccount: class declaration
//---------------------------------------------------------------------------

#include "SavingsAccount.h"

class ISAAccount : public SavingsAccount
{
public:
	ISAAccount();
	~ISAAccount();

	double getMaximumYearlyDeposit() const;
	double getCurrentYearlyDeposit() const;
	Date getEndDepositPeriod() const;

	virtual const string prepareFormattedAccountDetails() const;

	virtual bool canDeposit(const double&) const;
	virtual void recordDeposit(double amountToDeposit);

	virtual bool canTransferIn(const double&, string&);
	virtual void recordTransferIn(const double& transferAmount, const string& accNum);

	virtual istream& getAccountDataFromStream(istream& is);
	virtual ostream& putAccountDetailsInStream(ostream& os) const;

private:

	double maximumYearlyDeposit_;
	double currentYearlyDeposit_;
	Date endDepositPeriod_;

	void updateCurrentYearlyDeposit(const double&);
};

#endif