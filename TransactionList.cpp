//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)

#include "TransactionList.h"

//---------------------------------------------------------------------------
//TransactionList: class implementation
//---------------------------------------------------------------------------

//____public member functions

//____constructors & destructors



//Getters

double TransactionList::getTotalNumberTransactions() const {
	return size();
}

double TransactionList::getTotalTransactions() const
{
	double cumulativeTotal(0);
	const int count = size();
	List<Transaction> trl = getTransactionList();

	for (int i = 0; i < count; i++)
	{
		cumulativeTotal = cumulativeTotal + trl.first().getAmount();
		trl = trl.tail();
	}
	return cumulativeTotal;
}

List<Transaction> TransactionList::getTransactionList() const
{
	return listOfTransactions_;
}

TransactionList TransactionList::getMostRecentTransactions(const int& noOfTransactions) const
{
	List<Transaction> trl = listOfTransactions_;
	TransactionList trlRecent;

	for (int i = 0; i < noOfTransactions; i++)
	{
		trlRecent.addNewTransactionEnd(trl.first());
		trl = trl.tail();
	}

	return trlRecent;
}

TransactionList TransactionList::getTransactionsUpToDate(const Date& d) const
{

	//ADD RECURSION TO ALL GET TRANSACTIONS

	//Copy of list
	List<Transaction> trlist = listOfTransactions_;
	TransactionList trReturn;

	//For every item in the list (Most recent first)
	for (int i(0); i < listOfTransactions_.length(); i++)
	{
		//If first date in list is less than or equal to given date
		if (!(trlist.first().getDate() > d))
		{
			//Add it to temporary transaction list
			trReturn.addNewTransactionEnd(trlist.first());
		}
		//Go to next transaction
		trlist = trlist.tail();
	}

	//Return ammended transaction list
	return trReturn;
}

void TransactionList::deleteTransactionsUpToDate(const Date& d)
{

	int numToDelete = getTransactionsUpToDate(d).size();
	int numToAdd = size() - numToDelete;

	TransactionList tempList;
	TransactionList copyOfList = (*this);
	for (int i(0); i < numToAdd; i++)
	{
		tempList.addNewTransaction(copyOfList.newestTransaction());
		copyOfList.deleteFirstTransaction();
	}

	listOfTransactions_ = tempList.getTransactionList();

}


//____other public member functions

void TransactionList::addNewTransaction(const Transaction& tr) {
    listOfTransactions_.addInFront(tr);
}
void TransactionList::addNewTransactionEnd(const Transaction& tr) {
	listOfTransactions_.addAtEnd(tr);
}
const Transaction TransactionList::newestTransaction() const {
    return (listOfTransactions_.first());
}
const TransactionList TransactionList::olderTransactions() const {
	TransactionList trlist(*this);
    trlist.deleteFirstTransaction();
    return trlist;
}
void TransactionList::deleteFirstTransaction() {
    listOfTransactions_.deleteFirst();
}
void TransactionList::deleteGivenTransaction(const Transaction& tr) {
    listOfTransactions_.deleteOne(tr);
}
int TransactionList::size() const {
    return (listOfTransactions_.length());
}

const string TransactionList::toFormattedString() const {
//return transaction list as a (formatted) string
	ostringstream os_transactionlist;
    TransactionList tempTrList(*this);
	while (! (tempTrList.size() == 0))
    {
		os_transactionlist << endl << tempTrList.newestTransaction().toFormattedString();
        tempTrList.deleteFirstTransaction();
    }
	return (os_transactionlist.str());
}

ostream& TransactionList::putDataInStream(ostream& os) const {
//put (unformatted) transaction list into an output stream
    TransactionList tempTrList(*this);
	while (! (tempTrList.size() == 0))
    {
		os << tempTrList.newestTransaction() << endl;
        tempTrList.deleteFirstTransaction();
    }
	return os;
}
istream& TransactionList::getDataFromStream(istream& is) {
//read in (unformatted) transaction list from input stream
	Transaction aTransaction;
	is >> aTransaction;	//read first transaction
	while (is) 	//while not end of file
	{
		listOfTransactions_.addAtEnd(aTransaction);   //add transaction to list of transactions
		is >> aTransaction;	//read in next transaction
	}
	return is;
}


//---------------------------------------------------------------------------
//non-member operator functions
//---------------------------------------------------------------------------

ostream& operator<<(ostream& os, const TransactionList& aTransactionList) {
    return (aTransactionList.putDataInStream(os));
}
istream& operator>>(istream& is, TransactionList& aTransactionList) {
	return (aTransactionList.getDataFromStream(is));
}
