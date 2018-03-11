//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)

#ifndef ATMH
#define ATMH 

//---------------------------------------------------------------------------
//ATM: class declaration
//---------------------------------------------------------------------------

#include "Card.h"
#include "BankAccount.h"
#include "UserInterface.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
using namespace std;

class ATM {
public:
	ATM();	//default constructor
	~ATM();	//destructor
    void activateCashPoint();
private:
	//data items
    BankAccount* p_theActiveAccount_;
    Card* p_theCard_;
    const UserInterface theUI_;

	//support functions
    int  validateCard(const string&) const;
	void executeCardCommand(int);
	int  validateAccount(const string&) const;
	void executeAccountCommand();

	//Search functions
	void searchTransactions();
 
	//card menu commands
	void m_card1_manageIndividualAccount();

	//account menu commands
    void m_acct1_produceBalance() const;
    void m_acct2_withdrawFromBankAccount();
    void m_acct3_depositToBankAccount();
    void m_acct4_produceStatement() const;
	void m_acct5_showAllDepositsTransactions() const;
	void m_acct7_searchForTransactions();

	//Search Menu Commands (3b)
	void m_trl_showTransactionsForAmount() const;
	void sm2_showTransactionsForTitle() const;
	void sm3_showTransactionsForDate() const;

    //support file handling functions and creation of dynamic objects
    bool canOpenFile(const string&) const;
	static char getAccountTypeCode(const string&);
	bool accountsListedOnCard(const string&) const;

    void activateCard(const string&);
	void releaseCard();

	BankAccount* activateAccount(const string&);
	BankAccount* releaseAccount(BankAccount*, string);

};

#endif
