//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)

#ifndef ISAAccountH
//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number: 1
//Team: 
//Alex Fullarton, 26038657, CS4G
//Jake Hanne, 26027599, CS4G
//Dave Harrison, 26011054, CS4G

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
	virtual void recordDeposit(const double& amountToDeposit);

	virtual bool canTransferIn(const double&, string&) const;
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