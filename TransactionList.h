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
	//Assume default string / Title
	template <class T>
	TransactionList getTransactionsForSearchCriteria(const T& t) const
	{
		//Copy of list
		List<Transaction> trlist = listOfTransactions_;
		TransactionList trReturn;

		//For every item in the list (Most recent first)
		for (int i(0); i < listOfTransactions_.length(); i++)
		{
			//If first item in list is correct value
			if (trlist.first().getTitle() == t)
			{
				//Add it to temporary transaction list
				trReturn.addNewTransaction(trlist.first());
			}
			//Go to next transaction
			trlist = trlist.tail();
		}

		//Return ammended transaction list
		return trReturn;
	};

	template<>
	TransactionList getTransactionsForSearchCriteria<double>(const double& a) const
	{
		//Copy of list
		List<Transaction> trlist = listOfTransactions_;
		TransactionList trReturn;
		//For every item in the list (Most recent first)
		for (int i(0); i < listOfTransactions_.length(); i++)
		{
			//If first item in list is correct value
			if (trlist.first().getAmount() == a)
			{
				//Add it to temporary transaction list
				trReturn.addNewTransaction(trlist.first());
			}
			//Go to next transaction
			trlist = trlist.tail();
		}

		//Return ammended transaction list
		return trReturn;
	};

	template<>
	TransactionList getTransactionsForSearchCriteria<Date>(const Date& d) const
	{
		//Copy of list
		List<Transaction> trlist = listOfTransactions_;
		TransactionList trReturn;

		//For every item in the list (Most recent first)
		for (int i(0); i < listOfTransactions_.length(); i++)
		{
			//If first item in list is correct value
			if (trlist.first().getDate() == d)
			{
				//Add it to temporary transaction list
				trReturn.addNewTransactionEnd(trlist.first());
			}
			//Go to next transaction
			trlist = trlist.tail();
		}

		//Return ammended transaction list
		return trReturn;
	};

	//Q3c
	TransactionList getTransactionsUpToDate(const Date&);
	void deleteTransactionsUpToDate(const Date&);

	//Mutators
	void   addNewTransaction(const Transaction&);
	void   addNewTransactionEnd(const Transaction&);
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

