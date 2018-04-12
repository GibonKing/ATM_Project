//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)

#include "UserInterface.h" 

//---------------------------------------------------------------------------
//public member functions
//---------------------------------------------------------------------------

void UserInterface::wait() const
{
	cout << "\n";
	outputLine("Press RETURN to go back to menu...");
	char ch;
	cin.get(ch);
	cin.get(ch);
}
void UserInterface::endProgram() const
{
	cout << "\n";
	outputLine("Press RETURN to end program...");
	char ch;
	cin.get(ch);
	cin.get(ch);
}
int UserInterface::showMainMenuAndGetCommand() const
{
	system("cls");
	cout << "\n\n";
	outputHeader("WELCOME TO THE ATM");
	outputLine(" 0                            Leave ATM ");
	outputLine(" 1                      Enter your card ");
	outputLine("----------------------------------------");
	return (readInCommand());
}

int UserInterface::showAccountMenuAndGetCommand(const string& accNum) const
{
	outputHeader("ACCOUNT " + accNum + " MENU");
	outputLine(" 0                    Back to card menu ");
	outputLine(" 1                      Display balance ");
	outputLine(" 2                Withdraw from account ");
	outputLine(" 3                 Deposit into account ");
	outputLine(" 4                       Show statement ");
	outputLine(" 5                    Show all deposits  // TO BE IMPLEMENTED FOR Task 1c Preparation");
	outputLine(" 6                  Show mini statement  // TO BE IMPLEMENTED FOR Task 1c");
	outputLine(" 7                  Search Transactions  // TO BE IMPLEMENTED FOR Task 1c");
	outputLine(" 8    Clear all transactions up to date  // TO BE IMPLEMENTED FOR Task 1c");
	outputLine(" 9          Transfer to another account  // TO BE IMPLEMENTED FOR Task 1c");
	outputLine("----------------------------------------");
	return (readInCommand());
}

const string UserInterface::readInCardToBeProcessed() const {
	return askForInput("ENTER YOUR CARD NUMBER");
}

void UserInterface::showValidateCardOnScreen(int validCode, const string& cardNumber) const
{
	switch (validCode)
	{
	case VALID_CARD: {
		// Card exists and is accessible (and is not already open: TO BE IMPLEMENTED)
	} break;
	case UNKNOWN_CARD: {
		outputLine("ERROR: CARD " + cardNumber + " DOES NOT EXIST");
	} break;
	case EMPTY_CARD: {
		outputLine("ERROR: CARD " + cardNumber + " DOES NOT LINK TO ANY ACCOUNTS");
	} break;
	}
}

int UserInterface::showCardMenuAndGetCommand(const string& cardNumber) const
{
	outputHeader("CARD " + cardNumber + " MENU");
	outputLine(" 0           Stop banking & remove card ");
	outputLine(" 1            Manage individual account ");
	outputLine(" 2           Show total funds available  // TO BE IMPLEMENTED FOR Task 1c");
	outputLine("----------------------------------------");
	return (readInCommand());
}

void UserInterface::showCardAccounts(const string& cardNumber, const string& cardDetails) const
{
	outputHeader("CARD " + cardNumber + " ACCOUNTS");
	cout << cardDetails;
	outputLine("----------------------------------------\n");
}

const string UserInterface::readInAccountToBeProcessed() const {
	return askForInput("SELECT ACCOUNT TO MANAGE");
}

void UserInterface::showValidateAccountOnScreen(int validCode, const string& accNum) const
{
	switch (validCode)
	{
	case VALID_ACCOUNT:
	{
		// Account exists and is accessible with that card (and not already open: TO BE IMPLEMENTED)
	} break;
	case INVALID_ACCOUNT_TYPE:
	{
		outputLine("ERROR: ACCOUNT " + accNum + " IS NOT A RECOGNISED TYPE OF ACCOUNT!");
	} break;
	case UNKNOWN_ACCOUNT:
	{
		outputLine("ERROR: ACCOUNT " + accNum + " DOES NOT EXIST!");
	} break;
	case UNACCESSIBLE_ACCOUNT:
	{
		outputLine("ERROR: ACCOUNT " + accNum + " IS NOT ACCESSIBLE WITH THIS CARD!");
	} break;
	}
}

//static 
const string UserInterface::cardFilename(const string& cn) {
	//read in card name & produce cashcard filename
	return FILEPATH + "card_" + cn + ".txt";	//read in card name & produce cashcard filename
}
//static
const string UserInterface::accountFilename(const string& an) {
	return FILEPATH + "account_" + an + ".txt";
}

//input functions

double UserInterface::readInWithdrawalAmount() const {
	//ask for the amount to withdraw
	outputLine("AMOUNT TO WITHDRAW: \234");
	return (readInPositiveAmount());
}
double UserInterface::readInDepositAmount() const {
	//ask for the amount to deposit
	outputLine("AMOUNT TO DEPOSIT: \234");
	return (readInPositiveAmount());
}

Date UserInterface::readInValidDate(Date cd) const
{
	outputLine("PLEASE INPUT A DATE (DD/MM/YYYY): ");
	Date aDate;
	cin >> aDate;

	//If an incorrect date is inputted
	if (!aDate.isValid(cd))
	{
		//Loop again
		cout << "ERROR: ";
		readInValidDate(cd);
	}

	//else return date
	return aDate;
}


//output functions

void UserInterface::showProduceBalanceOnScreen(double balance) const
{
	cout << "\n      THE CURRENT BALANCE IS: " << fixed << setprecision(2) << setfill(' ') << "\234" << setw(12) << balance;
}

void UserInterface::showWithdrawalOnScreen(bool trAuthorised, double withdrawnAmount) const
{
	if (trAuthorised)
	{
		cout << "\n      TRANSACTION AUTHORISED. \234" << setw(0) << withdrawnAmount << " WITHDRAWN FROM ACCOUNT";
	}
	else
	{
		outputLine("TRANSACTION IMPOSSIBLE!"); // not enough money
	}
}

void UserInterface::showDepositOnScreen(bool trAuthorised, double depositAmount) const
{
	if (trAuthorised)
	{
		cout << "\n      TRANSACTION AUTHORISED. \234" << setw(0) << depositAmount << " DEPOSITED INTO ACCOUNT";
	}
	else
	{
		outputLine("TRANSACTION IMPOSSIBLE!"); // too much to deposit
	}
}

//void UserInterface::showAllDepositsOnScreen(TransactionList)

void UserInterface::showStatementOnScreen(const string& statement) const {
	outputHeader("PREPARING STATEMENT...");
	cout << statement;
	outputLine("----------------------------------------\n");
}

void UserInterface::showAllDepositsOnScreen(const bool& noTransaction, const string& str, const double& total) const
{
	if (noTransaction)
	{
		outputLine("NO DEPOSITS TO SHOW!");
	}
	else
	{
		cout << "\n		 TODAYS DATE: ";
		cout << "\n      TOTAL DEPOSITS MADE: " << setw(0) << total;
		cout << "\n      " << str;
	}
}

//---------------------------------------------------------------------------
// private support member functions
//---------------------------------------------------------------------------

void UserInterface::showByeScreen() const
{
	outputLine("");
	outputHeader("THANK YOU FOR USING THE ATM");
	endProgram();
}

int UserInterface::readInCommand() const
{
	cout << "\n";
	outputLine("ENTER YOUR COMMAND: ");
	int com;
	cin >> com;
	return com;
}

string UserInterface::readInString() const
{
	cout << "\n";
	outputLine("ENTER YOUR SEARCH CRITERIA: ");
	string str;
	cin >> str;
	return str;
}

void UserInterface::readInDate(int& day, int& month, int&year) const
{
	//int day, month, year;

	//Get a valid day
	cout << "\n";
	outputLine("ENTER THE DAY TO SEARCH (1 - 31): ");

	cin >> day;

	while (day < 1 || day > 31)
	{
		outputLine("INVALID DAY, TRY AGAIN: ");
		cin >> day;
	}

	//Get a valid month
	cout << "\n";
	outputLine("ENTER THE MONTH TO SEARCH (1 - 12): ");

	cin >> month;

	while (month < 1 || month > 12)
	{
		outputLine("INVALID MONTH, TRY AGAIN: ");
		cin >> month;
	}

	//Get a valid Year
	cout << "\n";
	outputLine("ENTER THE YEAR TO SEARCH: ");

	cin >> year;
}



//3b
int UserInterface::readInSearchCommand() const
{
	int command = readInCommand();

	//If command is not valid
	while (command > 3 || command < 0)
	{
		showErrorInvalidCommand();
		command = readInCommand();
	}

	return command;
}



double UserInterface::readInAmount() const
{
	outputLine("INPUT THE AMOUNT TO SEARCH FOR: ");

	double amount;
	cin >> amount;

	return amount;
}

//3c
void UserInterface::showTransactionsUpToDateOnScreen(bool isEmpty, Date d, int size, string str) const
{
	if (isEmpty)
	{
		outputLine("NO TRANSACTIONS TO SHOW UP TO " + d.toFormattedString() + ".");
	}
	else
	{
		//string s = "FOUND " + size. + " TRANSACTIONS UP TO DATE " + d.toFormattedString() + ":"
		cout << "\n      FOUND " << size << " TRANSACTIONS UP TO DATE " << d.toFormattedString() << ":\n";
		cout << "\n      " << str;
	}


}

bool UserInterface::readInConfirmDeletion() const
{
	bool deletionConfirmed(false);

	outputLine("ARE YOU SURE YOU WANT TO DELETE? (TYPE Y TO CONFIRM): ");
	char ch;
	cin >> ch;

	if (toupper(ch) == 'Y')
		deletionConfirmed = true;

	return deletionConfirmed;
}

void UserInterface::showDeletionOfTransactionsUpToDateOnScreen(int n, Date d, bool deletionConfirmed) const
{
	if (deletionConfirmed)
		cout << "\n      THE " << n << " TRANSACTIONS IN BANK ACCOUNT UP TO DATE " << d.toFormattedString() << " HAVE BEEN DELETED.";
	else
		outputLine("DELETION CANCELLED");
}
//3d
void UserInterface::showCardOnScreen(const string& cards) const
{
	outputLine(cards);
}

double UserInterface::readInTransferAmount() const
{
	outputLine("ENTER A POSITIVE AMOUNT TO TRANSFER: ");
	double amt;
	cin >> amt;

	while (amt <= 0)
	{
		outputLine("ERROR: POSITIVE VALUES ONLY, RETRY: ");
		cin >> amt;
	}

	return amt;
}

void UserInterface::showTransferOnScreen(const bool & trOutOk, const bool & trInOk, const double & transferAmount) const
{

	if (!trOutOk || !trInOk)
	{
		outputLine("CANNOT TRANSFER MONEY TO ACCOUNT");
	}
	else
	{
		outputLine("Transferred ");
		//ADD STUFF
	}
}

void UserInterface::showErrorInvalidCommand() const
{
	outputLine("INVALID COMMAND CHOICE, TRY AGAIN");
}

double UserInterface::readInPositiveAmount() const
{
	double amount;
	cin >> amount;

	while (amount <= 0.0)
	{
		outputLine("AMOUNT SHOULD BE A POSITIVE AMOUNT, TRY AGAIN: ");
		cin >> amount;
	}

	return amount;
}

int UserInterface::readInPositiveNumber() const
{
	int amount;
	cin >> amount;

	while (amount <= 0)
	{
		outputLine("INVALID NUMBER OF TRANSACTIONS, TRY AGAIN: ");
		cin >> amount;
	}

	return amount;

}

void UserInterface::outputHeader(const string& header) const
{
	// calculate lengths so we can centre the header
	const int length = header.size();
	const int borderWidth = 40;
	const int leftSpacePad = 6;
	const int paddingRequired = ((borderWidth - length) / 2) + leftSpacePad;

	outputLine("========================================");
	cout << "\n" << setfill(' ') << setw(paddingRequired) << ' ' << header;
	outputLine("========================================");
}

string UserInterface::askForInput(const string& promptForUser) const
{
	outputLine(promptForUser + ": ");
	string userInput;
	cin >> userInput;
	return userInput;
}

void UserInterface::outputLine(const string& text) const
{
	cout << "\n      " << text;
}
int UserInterface::readInNumberOfTransactions() const{
	//ask for the number of transactions to be retrieved
	outputLine("NUMBER OF TRANSACTIONS TO SHOW: ");
	return (readInPositiveNumber());
}

void UserInterface::showNoTransactionsOnScreen() const
{
	outputLine("NO TRANSACTIONS IN BANK ACCOUNT");
}

void UserInterface::showSearchMenu() const
{
	outputHeader("SEARCH MENU");

	outputLine(" 0                     Search By Amount ");

	outputLine(" 1                      Search By Title ");

	outputLine(" 2                       Search By Date ");

	outputLine(" 3                                 Exit ");

	outputLine("----------------------------------------");
}

//void UserInterface::showMatchingTransactionsOnScreen(const int& amount, const int& size, const string& message) const
//{
//	
//	outputHeader("SEARCH RESULTS");
//	cout << "\n THERE ARE " << size << " TRANSACTIONS IN BANK ACCOUNT MATCHING SEARCH CRITERIA "<< char(156) << amount;
//	
//	cout << "\n		 " << message;
//
//
//}


void UserInterface::showMiniStatementOnScreen(const bool& isEmpty, const double& total, const string& miniStatement) const
{
	if (!isEmpty)
	{
		cout << "\n		RECENT TRANSACTIONS REQUESTED AT time ON date";
		cout << miniStatement;
		cout << "\n		CUMULATIVE AMOUNT OF TRANSACTIONS: \234" << total;
	}
	else
		cout << "\n		NO TRANSACTIONS IN BANK ACCOUNT";
}

