//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number: 1
//Team: 
//Alex Fullarton, 26038657, CS4G
//Jake Hanne, 26027599, CS4G
//Dave Harrison, 26011054, CS4G

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