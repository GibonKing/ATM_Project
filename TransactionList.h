//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)

#ifndef TransactionListH
#define TransactionListH

//---------------------------------------------------------------------------
//TransactionList: class declaration
//---------------------------------------------------------------------------

#include "ListT.h"
#include "Transaction.h"

#include <cassert> 	// for assert()
#include <sstream>

class TransactionList {
public:
	//Assessors

	double getTotalNumberTransactions() const;
	double getTotalTransactions() const;
	List<Transaction> getTransactionList() const;

	//Q3a
	TransactionList getMostRecentTransactions(const int&) const;

	//Q3b
	TransactionList getTransactionsForAmount(const double&) const;
	TransactionList getTransactionsForTitle(const string&) const;
	TransactionList getTransactionsForDate(const Date&) const;

	//Q3c
	TransactionList getTransactionsUpToDate(const Date&) const;
	void deleteTransactionsUpToDate(const Date&);

	//Mutators
	void   addNewTransaction(const Transaction&);
    const Transaction newestTransaction() const;
    const  TransactionList olderTransactions() const;
    void   deleteFirstTransaction();
    void   deleteGivenTransaction(const Transaction&);
	int    size() const;

	const string toFormattedString() const;		//return transactionlist as a (formatted) string
	ostream& putDataInStream(ostream& os) const;	//send TransactionList info into an output stream
	istream& getDataFromStream(istream& is);	//receive TransactionList info from an input stream

private:
    List<Transaction> listOfTransactions_;	//list of transactions
};

//---------------------------------------------------------------------------
//non-member operator functions
//---------------------------------------------------------------------------

ostream& operator<<(ostream&, const TransactionList&);	//insertion operator
istream& operator>>(istream& is, TransactionList& trl); //extraction operator

#endif

