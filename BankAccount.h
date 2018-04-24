//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number: 1
//Team: 
//Alex Fullarton, 26038657, CS4G
//Jake Hanne, 26027599, CS4G
//Dave Harrison

#ifndef BankAccountH
#define BankAccountH

//---------------------------------------------------------------------------
//BankAccount: class declaration
//---------------------------------------------------------------------------

//#include "Date.h"
//#include "Transaction.h"
#include "TransactionList.h"

#include <fstream>
#include <cassert>
using namespace std;


class BankAccount {
public:
    //constructors & destructor
	BankAccount();
    ~BankAccount();

	//Assessors
    const string getAccountNumber() const;
    const Date getCreationDate() const;
	double getBalance() const;
    const TransactionList getAllDepositTransactions() const;
    bool isEmptyTransactionList() const;
	virtual bool canWithdraw(const double&) const;
	virtual bool canDeposit(const double&) const;
	virtual double maxBorrowable() const;
	const string prepareFormattedStatement() const;
	

	//mutators
    virtual void recordDeposit(const double&);
    void recordWithdrawal(const double&);

	void readInBankAccountFromFile(const string& fileName);
	void storeBankAccountInFile(const string& fileName) const;

	//Q1 (NOT ASSESSED)
	string produceAllDepositTransactions(double&) const;

	//Q3a
	void produceNMostRecentTransactions(const int& noOfTransactions, string& recentTransactions, double& totalAmount) const;

	//Q3b
	template <class T>
	void produceTransactionsForSearchCriteria(const T& criteria, int& size, string& transactionString) const
	{
		////Make a copy of all transactions with that amount in them
		TransactionList trl = transactions_.getTransactionsForSearchCriteria(criteria);

		//Save that lists size
		size = trl.size();
		//Format the string ready for output in UI
		transactionString = trl.toFormattedString();
	}

	//Q3c
	void produceTransactionsUpToDate(const Date&, int&, string&) const;
	void recordDeletionOfTransactionUpToDate(const Date& d);

	//Q3d
	virtual bool canTransferOut(const double&, string&) const; 
	virtual bool canTransferIn(const double&, string&) const;

	void recordTransferOut(const double& transferAmount, const string& accNum);
	virtual void recordTransferIn(const double& transferAmount, const string& accNum);


	//functions to put data into and get data from streams
	ostream& putDataInStream(ostream& os) const;
	istream& getDataFromStream(istream& is);
	virtual ostream& putAccountDetailsInStream(ostream& os) const;
	virtual istream& getAccountDataFromStream(istream& is);

	virtual const string prepareFormattedAccountDetails() const = 0;
	virtual const string prepareFormattedMiniAccountDetails() const;
	const string prepareFormattedTransactionList() const;

	static const string getAccountType(const string& filename);
	static const string getAccountType(char n);
	
private:
    //data items
    string accountNumber_;
    Date   creationDate_;
	double balance_;
    TransactionList transactions_;
 
	//support functions
	void updateBalance(double amount);
	ostream& putTransactionInStream(ostream& os) const;
	istream& getTransactionsDataFromStream(istream& is);
};

//---------------------------------------------------------------------------
//non-member operator functions
//---------------------------------------------------------------------------

ostream& operator<<(ostream&, const BankAccount&);	//output operator
istream& operator>>(istream&, BankAccount&);	    //input operator

#endif
