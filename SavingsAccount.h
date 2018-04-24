//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)

#ifndef SavingsAccountH
#define SavingsAccountH

//---------------------------------------------------------------------------
//SavingsAccount: class declaration
//---------------------------------------------------------------------------

#include "BankAccount.h"

class SavingsAccount : public BankAccount
{
public:
	SavingsAccount();
	~SavingsAccount();

	double getMinimumBalance() const;
	virtual double maxBorrowable() const;

	virtual const string prepareFormattedAccountDetails() const = 0;
	virtual const string prepareFormattedMiniAccountDetails() const;


	virtual bool canTransferOut(const double&, string&) const;
	virtual bool canTransferIn(const double&, string&) const;
	virtual void recordTransferIn(const double& transferAmount, const string& accNum);

	virtual istream& getAccountDataFromStream(istream& is);
	virtual ostream& putAccountDetailsInStream(ostream& os) const;

private:

	double minimumBalance;
};

#endif