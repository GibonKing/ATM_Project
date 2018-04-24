//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)

#ifndef CurrentAccountH
#define CurrentAccountH

//---------------------------------------------------------------------------
//CurrentAccount: class declaration
//---------------------------------------------------------------------------

#include "BankAccount.h"

class CurrentAccount : public BankAccount
{
public:
	CurrentAccount();
	~CurrentAccount();

	double getOverdraftLimit() const;
	virtual double maxBorrowable() const;

	virtual const string prepareFormattedAccountDetails() const;
	virtual const string prepareFormattedMiniAccountDetails() const;

	virtual bool canTransferOut(const double&, string&) const;

	virtual istream& getAccountDataFromStream(istream& is);
	virtual ostream& putAccountDetailsInStream(ostream& os) const;

private:

	double overdraftLimit_;
};

#endif