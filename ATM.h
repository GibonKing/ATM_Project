//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number: 1
//Team: 
//Alex Fullarton, 26038657, CS4G
//Jake Hanne, 26027599, CS4G
//Dave Harrison, 26011054, CS4G
#ifndef ATMH
#define ATMH 

//---------------------------------------------------------------------------
//ATM: class declaration
//---------------------------------------------------------------------------

#include "Card.h"
#include "CurrentAccount.h"
#include "ChildAccount.h"
#include "ISAAccount.h"
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
	UserInterface& theUI_ = UserInterface::getInstance();

	//support functions
    int  validateCard(const string&) const;
	void executeCardCommand(int);
	int  validateAccount(const string&) const;
	void executeAccountCommand();

	//card menu commands
	void m_card1_manageIndividualAccount();
	void m_card2_showFundsAvailableOnAllAccounts();

	//account menu commands
    void m_acct1_produceBalance() const;
    void m_acct2_withdrawFromBankAccount();
    void m_acct3_depositToBankAccount();
    void m_acct4_produceStatement() const;
	void m_acct5_showAllDepositsTransactions() const;
	void m_acct6_showMiniStatement() const;
	void m_acct7_searchForTransactions() const;
	void m_acct8_clearAllTransactionsUpToDate();
	void m_acct9_transferCashToAnotherAccount();

	//Search Menu Commands (3b)
	void m_trl_showTransactionsForAmount() const;
	void m_trl_showTransactionsForTitle() const;
	void m_trl_showTransactionsForDate() const;

	//Search for Transactions (3c)
	void searchTransactions() const;

	//Transfer Commands (3d)
	void attemptTransfer(BankAccount* ba) const;
	void recordTransfer(const double&, BankAccount*) const;

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
