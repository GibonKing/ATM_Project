//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)

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

	//getter (assessor) functions
    const string getAccountNumber() const;
    const Date getCreationDate() const;
	double getBalance() const;
    const TransactionList getAllDepositTransactions() const;
    bool	isEmptyTransactionList() const;

	//other operations
	const string prepareFormattedStatement() const;

    void recordDeposit(double amount);

	virtual double maxBorrowable() const;
	bool canWithdraw(double amount) const;
    void recordWithdrawal(double amount);

	void readInBankAccountFromFile(const string& fileName);
	void storeBankAccountInFile(const string& fileName) const;

	//Q1
	string produceAllDepositTransactions(double&);

	//Q3a
	void produceNMostRecentTransactions(const int& noOfTransactions, string& recentTransactions, double& totalAmount) const;

	//Q3b
	void produceTransactionsForAmount(const double&, int&, string&);
	void produceTransactionsForTitle(const string&, int&, string&);
	void produceTransactionsForDate(const Date&, int&, string&);

	//Q3c
	void produceTransactionsUpToDate(const Date&, int&, string&);
	void recordDeletionOfTransactionUpToDate(const Date& d);

	//Q3d
	bool canTransferOut(const double&); 
	bool canTransferIn(const double&);
	void recordTransferOut(const double& transferAmount, const string& accNum);
	void recordTransferIn(const double& transferAmount, const string& accNum);


	//functions to put data into and get data from streams
	ostream& putDataInStream(ostream& os) const;
	ostream& putAccountDetailsInStream(ostream& os) const;
	istream& getDataFromStream(istream& is);
	virtual istream& getAccountDataFromStream(istream& is);

	virtual const string prepareFormattedAccountDetails() const = 0;
	const string prepareFormattedMiniAccountDetails() const;
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
