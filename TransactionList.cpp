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
	list<Transaction> trl = getTransactionList();

	for (int i = 0; i < count; i++)
	{
		cumulativeTotal = cumulativeTotal + trl.front().getAmount();
		trl.pop_front();
	}
	return cumulativeTotal;
}

list<Transaction> TransactionList::getTransactionList() const
{
	return listOfTransactions_;
}

TransactionList TransactionList::getMostRecentTransactions(const int& noOfTransactions) const
{
	list<Transaction> trl = listOfTransactions_;
	TransactionList trlRecent;

	for (int i = 0; i < noOfTransactions; i++)
	{
		trlRecent.addNewTransactionEnd(trl.front());
		trl.pop_front();
	}

	return trlRecent;
}

TransactionList TransactionList::getTransactionsUpToDate(const Date& d)
{

	if (listOfTransactions_.size() != 0)
	{
		if (listOfTransactions_.front().getDate() > d)
		{
			deleteFirstTransaction();
			return getTransactionsUpToDate(d);
		}
		else
		{
			return (*this);
		}
	}
	else
	{
		return (*this);
	}

	////For every item in the list (Most recent first)
	//for (int i(0); i < listOfTransactions_.length(); i++)
	//{
	//	//If first date in list is less than or equal to given date
	//	if (!(trlist.first().getDate() > d))
	//	{
	//		//Add it to temporary transaction list
	//		trReturn.addNewTransactionEnd(trlist.first());
	//	}
	//	//Go to next transaction
	//	trlist = trlist.tail();
	//}
	//
	////Return ammended transaction list
	//return trReturn;
}

void TransactionList::deleteTransactionsUpToDate(const Date& d)
{
	TransactionList temp = (*this);
	TransactionList tempList = temp.getTransactionsUpToDate(d);

	if (tempList.getTransactionList().size() != 0)
	{
		deleteGivenTransaction(tempList.getTransactionList().front());
		deleteTransactionsUpToDate(d);
	}

	//int numToDelete = getTransactionsUpToDate(d).size();
	//int numToAdd = size() - numToDelete;
	//
	//TransactionList tempList;
	//TransactionList copyOfList = (*this);
	//for (int i(0); i < numToAdd; i++)
	//{
	//	tempList.addNewTransaction(copyOfList.newestTransaction());
	//	copyOfList.deleteFirstTransaction();
	//}
	//
	//listOfTransactions_ = tempList.getTransactionList();
}


//____other public member functions

void TransactionList::addNewTransaction(const Transaction& tr) {
    listOfTransactions_.push_front(tr);
}
void TransactionList::addNewTransactionEnd(const Transaction& tr) {
	listOfTransactions_.push_back(tr);
}
const Transaction TransactionList::newestTransaction() const {
    return (listOfTransactions_.front());
}
const TransactionList TransactionList::olderTransactions() const {
	TransactionList trlist(*this);
    trlist.deleteFirstTransaction();
    return trlist;
}
void TransactionList::deleteFirstTransaction() {
    listOfTransactions_.pop_front();
}
void TransactionList::deleteGivenTransaction(const Transaction& tr) {
    
	list<Transaction>::iterator pos;

	pos = find(listOfTransactions_.begin(), listOfTransactions_.end(), tr);
	listOfTransactions_.erase(pos);

}
int TransactionList::size() const {
    return (listOfTransactions_.size());
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
		listOfTransactions_.push_back(aTransaction);   //add transaction to list of transactions
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
