//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)


#ifndef UserInterfaceH 
#define UserInterfaceH

//---------------------------------------------------------------------------
//UserInterface: class declaration
//---------------------------------------------------------------------------

#include "constants.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include "Date.h"
#include "Time.h"

using namespace std;

class UserInterface {
public:
	void showByeScreen() const;

	int showMainMenuAndGetCommand() const;
	int showCardMenuAndGetCommand(const string& cardNum) const;
	int showAccountMenuAndGetCommand(const string& accNum) const;

	void showErrorInvalidCommand() const;
	void wait() const;
	void endProgram() const;
	const string readInCardToBeProcessed() const;
	void showValidateCardOnScreen(int validCode, const string& cardNum) const;
	void showCardAccounts(const string& cardNum, const string& cardSt) const;
	const string readInAccountToBeProcessed() const;
	void showValidateAccountOnScreen(int valid, const string& acctNum) const;
	void showMiniStatementOnScreen(const bool&, const double&, const string&) const;

	static const string cardFilename(const string& cn);
	static const string accountFilename(const string& an);

	double readInWithdrawalAmount() const;
	double readInDepositAmount() const;
	Date readInValidDate(Date d) const;

	int readInNumberOfTransactions() const;

	void showProduceBalanceOnScreen(double bal) const;
	void showDepositOnScreen(bool auth, double deposit) const;
	void showWithdrawalOnScreen(bool auth, double withdrawal) const;
	void showStatementOnScreen(const string&) const;
	void showAllDepositsOnScreen(const bool&, const string&, const double&) const;
	void showFundsAvailableOnScreen(const bool&, const string&, const double&) const;

	//3b
	void showNoTransactionsOnScreen() const;
	void showSearchMenu() const;
	int readInSearchCommand() const;
	double readInAmount() const;
	string readInString() const;
	void readInDate(int&, int&, int&) const;

	//3c
	void showTransactionsUpToDateOnScreen(bool, Date, int, string) const;
	bool readInConfirmDeletion() const;
	void showDeletionOfTransactionsUpToDateOnScreen(int n, Date d, bool deletionConfirmed) const;

	template <class T>
	void showMatchingTransactionsOnScreen(const T& criteria, const int& size, const string& message) const
	{
		outputHeader("SEARCH RESULTS");
		cout << "\n THERE ARE " << size << " TRANSACTIONS IN BANK ACCOUNT MATCHING SEARCH CRITERIA : "  << criteria;

		cout << "\n		 " << message;

	}
	

private:
	//support functions
	int readInCommand() const;
	double readInPositiveAmount() const;
	int readInPositiveNumber() const;
	void outputHeader(const string&) const;
	string askForInput(const string&) const;
	void outputLine(const string&) const;
};

#endif
