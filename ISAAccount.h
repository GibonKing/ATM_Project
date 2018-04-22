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
	virtual istream& getAccountDataFromStream(istream& is);
	virtual bool canDeposit(const double&) const;
	virtual void recordDeposit(double amountToDeposit);

private:

	double maximumYearlyDeposit_;
	double currentYearlyDeposit_;
	Date endDepositPeriod_;

	void updateCurrentYearlyDeposit(const double&);
};

#endif