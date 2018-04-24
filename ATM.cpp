//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)

#include "ATM.h"

//---------------------------------------------------------------------------
//ATM: class implementation
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//public member functions
//---------------------------------------------------------------------------

//____constructors & destructors

ATM::ATM()
	: p_theActiveAccount_(nullptr), p_theCard_(nullptr)
{}

ATM::~ATM()
{
	assert(p_theActiveAccount_ == nullptr);
	assert(p_theCard_ == nullptr);
}

//____other public member functions

void ATM::activateCashPoint() {
	int command( theUI_.showMainMenuAndGetCommand());
	while (command != QUIT_COMMAND)
	{
		executeCardCommand(command);
		theUI_.wait();
		command = theUI_.showMainMenuAndGetCommand();
	}
	theUI_.showByeScreen();
}

//---------------------------------------------------------------------------
//private support member functions
//---------------------------------------------------------------------------

void ATM::executeCardCommand(int option) {
	switch (option)
	{
		case 1:
		{
			string cardNum(theUI_.readInCardToBeProcessed());
			string cardFilename(theUI_.cardFilename(cardNum));
			int validCardCode(validateCard(cardFilename));	
			theUI_.showValidateCardOnScreen(validCardCode, cardNum);
			if (validCardCode == VALID_CARD) 
			{
				//dynamically create a card and store card data
				activateCard(cardFilename);

				//select request for active card 
				int option = theUI_.showCardMenuAndGetCommand(cardNum);
				while (option != QUIT_COMMAND)
				{
					switch (option)
					{
					case 1: m_card1_manageIndividualAccount();
						break;
					case 2: m_card2_showFundsAvailableOnAllAccounts();
						break;
						default:
							theUI_.showErrorInvalidCommand();
					}

					theUI_.wait();
					option = theUI_.showCardMenuAndGetCommand(cardNum);
				}

				//free memory space used by active card
				releaseCard();
			}
			break;
		}
		default:theUI_.showErrorInvalidCommand();
	}
}
void ATM::m_card1_manageIndividualAccount() {
	assert(p_theCard_ != nullptr);
	theUI_.showCardAccounts(p_theCard_->getCardNumber(), p_theCard_->toFormattedString());
	executeAccountCommand();
}
int ATM::validateCard(const string& filename) const {
	//check that the card exists (valid)
	if (!canOpenFile(filename))   //invalid card
		return UNKNOWN_CARD;
	else
		//card empty (exist but no bank account listed on card)
		if (!accountsListedOnCard(filename))
			return EMPTY_CARD;
		else
			//card valid (exists and linked to at least one bank account)
			return VALID_CARD;
}

void ATM::m_card2_showFundsAvailableOnAllAccounts()
{
	assert(p_theCard_ != nullptr);
	List<string> accts = p_theCard_->getAccountsList();
	bool empty = accts.isEmpty();
	double maxBorrowable(0.0);
	string accountDetails("");

	if (!empty)
	{
		int length = accts.length();
		for (int i = 0; i < length; i++)
		{
			if ((accts.first()[0] != BANKACCOUNT_TYPE) && (accts.first()[0] != SAVINGSACCOUNT_TYPE))
			{
				BankAccount* p_acct = activateAccount(theUI_.accountFilename(accts.first()));
				maxBorrowable += p_acct->maxBorrowable();
				accountDetails += p_acct->prepareFormattedAccountDetails();
				releaseAccount(p_acct, "account_" + (p_acct->getAccountNumber()));
			}
			accts.deleteFirst();
		}
	}
	theUI_.showFundsAvailableOnScreen(empty, accountDetails, maxBorrowable);

}
int ATM::validateAccount(const string& filename) const {
	//check that the account is valid 
	//NOTE: MORE WORK NEEDED here in case of transfer
	if (!canOpenFile(filename))
		//account does not exist
		return UNKNOWN_ACCOUNT;
	else
		//account type not recognised
		if (BankAccount::getAccountType(filename) == "UNKNOWN")
			//if (getAccountTypeCode(filename) == UNKNOWN_ACCOUNT_TYPE)
			return INVALID_ACCOUNT_TYPE;
		else
			//unaccessible account (exists but not listed on card)
			if (!p_theCard_->onCard(filename))
				return UNACCESSIBLE_ACCOUNT;
			else
				//account valid (exists and accessible)
				return VALID_ACCOUNT;
}
void ATM::executeAccountCommand() {
	assert(p_theActiveAccount_ == nullptr);
	//process from one account
	//select active account and check that it is valid
	const string anAccountNumber(theUI_.readInAccountToBeProcessed());
	const string bankAccountFilename(theUI_.accountFilename(anAccountNumber));
	const int validAccountCode(validateAccount(bankAccountFilename));
	theUI_.showValidateAccountOnScreen(validAccountCode, anAccountNumber);

	if (validAccountCode == VALID_ACCOUNT) //valid account: exists, accessible with card and not already open
	{
		//dynamically create a bank account to store data from file
		p_theActiveAccount_ = activateAccount(bankAccountFilename);

		//select request for active account 
		int option = theUI_.showAccountMenuAndGetCommand(p_theActiveAccount_->getAccountNumber());
		while (option != QUIT_COMMAND)
		{
			switch (option)
			{
				case 1:	m_acct1_produceBalance();
					break;
				case 2: m_acct2_withdrawFromBankAccount();
					break;
				case 3:	m_acct3_depositToBankAccount();
					break;
				case 4:	m_acct4_produceStatement();
					break;
				case 5: m_acct5_showAllDepositsTransactions();
					break;
				case 6: m_acct6_showMiniStatement();
					break;
				case 7: m_acct7_searchForTransactions();
					break;
				case 8:
					m_acct8_clearAllTransactionsUpToDate();
					break;
				case 9:
					m_acct9_transferCashToAnotherAccount();
					break;
				default:theUI_.showErrorInvalidCommand();
			}
			theUI_.wait();
			option = theUI_.showAccountMenuAndGetCommand(p_theActiveAccount_->getAccountNumber());   //select another option
		}	

		//store new state of bank account in file and free bank account memory space
		p_theActiveAccount_ = releaseAccount(p_theActiveAccount_, bankAccountFilename);
	}
}

//------ menu options
//---option 1
void ATM::m_acct1_produceBalance() const {
	assert(p_theActiveAccount_ != nullptr);
	double balance(p_theActiveAccount_->getBalance());
	theUI_.showProduceBalanceOnScreen(balance);
}
//---option 2
void ATM::m_acct2_withdrawFromBankAccount() {
	assert(p_theActiveAccount_ != nullptr);
	double amountToWithdraw(theUI_.readInWithdrawalAmount());
	bool transactionAuthorised(p_theActiveAccount_->canWithdraw(amountToWithdraw));
	if (transactionAuthorised)
	{   //transaction is accepted: money can be withdrawn from account
		p_theActiveAccount_->recordWithdrawal(amountToWithdraw);
	}   //else do nothing
	theUI_.showWithdrawalOnScreen(transactionAuthorised, amountToWithdraw);
}
//---option 3
void ATM::m_acct3_depositToBankAccount() {
	assert(p_theActiveAccount_ != nullptr);
	double amountToDeposit(theUI_.readInDepositAmount());
	bool canDeposit = p_theActiveAccount_->canDeposit(amountToDeposit);
	if(canDeposit)
		p_theActiveAccount_->recordDeposit(amountToDeposit);
	theUI_.showDepositOnScreen(canDeposit, amountToDeposit);
}
//---option 4
void ATM::m_acct4_produceStatement() const {
	assert(p_theActiveAccount_ != nullptr);
	theUI_.showStatementOnScreen(p_theActiveAccount_->prepareFormattedStatement());
}

//---option 5
void ATM::m_acct5_showAllDepositsTransactions() const {
	assert(p_theActiveAccount_ != nullptr);
	bool noTransaction = p_theActiveAccount_->isEmptyTransactionList();
	
	string str;
	double total;	
	
	if (!noTransaction)
	{
		str = p_theActiveAccount_->produceAllDepositTransactions(total);
	}

	theUI_.showAllDepositsOnScreen(noTransaction, str, total);
}

//---option 6
void ATM::m_acct6_showMiniStatement() const {
	assert(p_theActiveAccount_ != nullptr);

	bool isEmpty = p_theActiveAccount_->isEmptyTransactionList();
	string recentTransactions;
	double total;

	if (!isEmpty) //If transaction list is not empty
	{
		const int noOfTransactions = theUI_.readInNumberOfTransactions();
		p_theActiveAccount_->produceNMostRecentTransactions(noOfTransactions, recentTransactions, total);
	}

	const string mad = p_theActiveAccount_->prepareFormattedMiniAccountDetails();
	theUI_.showMiniStatementOnScreen(isEmpty, total, mad + recentTransactions);
}

//---option 7
void ATM::m_acct7_searchForTransactions() const 
{
	assert(p_theActiveAccount_ != nullptr);
	bool isEmpty = (p_theActiveAccount_->isEmptyTransactionList());

	//If the transaction list is empty
	if (isEmpty)
	{
		//Show mssage to screen
		theUI_.showNoTransactionsOnScreen();
	}
	//Else start searching for transactions
	else
	{
		searchTransactions();
	}

}

//--option 8
void ATM::m_acct8_clearAllTransactionsUpToDate()
{
	assert(p_theActiveAccount_ != nullptr);

	bool isEmpty = (p_theActiveAccount_->isEmptyTransactionList());
	Date d;
	string str = "";
	int n = 0;

	if (!isEmpty)
	{
		Date cd = p_theActiveAccount_->getCreationDate();
		d = theUI_.readInValidDate(cd);
		p_theActiveAccount_->produceTransactionsUpToDate(d, n, str);
	}

	theUI_.showTransactionsUpToDateOnScreen(isEmpty, d, n, str);

	if (!isEmpty && str.length() != 0)
	{
		bool deletionConfirmed = theUI_.readInConfirmDeletion();

		if (deletionConfirmed)
			p_theActiveAccount_->recordDeletionOfTransactionUpToDate(d);

		theUI_.showDeletionOfTransactionsUpToDateOnScreen(n, d, deletionConfirmed);
	}
}

void ATM::m_acct9_transferCashToAnotherAccount()
{
	string card = p_theCard_->toFormattedString();
	theUI_.showCardOnScreen(card);

	string processAccount = theUI_.readInAccountToBeProcessed();

	while (processAccount == p_theActiveAccount_->getAccountNumber())
	{
		theUI_.showErrorSameAccount();
		processAccount = theUI_.readInAccountToBeProcessed();
	}
	string fileName = theUI_.accountFilename(processAccount);

	char validAccountCode = validateAccount(fileName);

	theUI_.showValidateAccountOnScreen(validAccountCode, processAccount);


	if (validAccountCode == 0)
	{
		BankAccount* transferAccount = activateAccount(fileName);
		
		attemptTransfer(transferAccount);
	
		releaseAccount(transferAccount, fileName);
	}

}
//------search menu options
void ATM::m_trl_showTransactionsForAmount() const
{
	//Get a value
	double a = theUI_.readInSearchCriteria<double>();
	int n;
	string str;
	p_theActiveAccount_->produceTransactionsForSearchCriteria<double>(a, n, str);

	theUI_.showMatchingTransactionsOnScreen(a, n, str);
}

void ATM::m_trl_showTransactionsForTitle() const
{
	//Get a string
	string t = theUI_.readInSearchCriteria<string>();
	int n;
	string str;
	p_theActiveAccount_->produceTransactionsForSearchCriteria<string>(t, n, str);
	//
	theUI_.showMatchingTransactionsOnScreen(t, n, str);
}

void ATM::m_trl_showTransactionsForDate() const
{
	Date d = theUI_.readInSearchCriteria<Date>();

	if (!d.isValid(p_theActiveAccount_->getCreationDate()))
	{
		theUI_.showErrorInvalidCriteria();
		m_trl_showTransactionsForDate();
	}
	else
	{
		int n;
		string str;
		p_theActiveAccount_->produceTransactionsForSearchCriteria<Date>(d, n, str);
		theUI_.showMatchingTransactionsOnScreen(d, n, str);
	}
}

void ATM::attemptTransfer(BankAccount* ba) const
{
	double transferAmount = theUI_.readInTransferAmount();

	string trOutError = "";
	string trInError = "";

	bool trOutOk = p_theActiveAccount_->canTransferOut(transferAmount, trOutError);
	bool trInOk = ba->canTransferIn(transferAmount, trInError); 
	
	if (trOutOk && trInOk)
		recordTransfer(transferAmount, ba);

	theUI_.showTransferOnScreen(trOutOk, trInOk, trOutError, trInError, transferAmount);
}

void ATM::recordTransfer(const double& transferAmount, BankAccount* ba) const
{
	string tAN = ba->getAccountNumber(); 
	string aAN = p_theActiveAccount_->getAccountNumber();

	p_theActiveAccount_->recordTransferOut(transferAmount, tAN);
	ba->recordTransferIn(transferAmount, aAN);
}

//------Search Functions
void ATM::searchTransactions() const
{
	//Show UI
	theUI_.showSearchMenu();
	
	//Read Input
	int option = theUI_.readInSearchCommand();
	assert(option <= 3 && option >= 0);

	switch (option)
	{
	case 0:
		m_trl_showTransactionsForAmount();
		break;
	case 1:
		m_trl_showTransactionsForTitle();
		break;
	case 2:
		m_trl_showTransactionsForDate();
		break;
	default:
		break;
	}
}


//------private file functions

bool ATM::canOpenFile(const string& filename) const {
	//check if a file already exist
	ifstream inFile;
	inFile.open(filename.c_str(), ios::in); 	//open file
	//if does not exist fail() return true
	return (!inFile.fail());	//close file automatically when inFile goes out of scope
}

bool ATM::accountsListedOnCard(const string& cashCardFileName) const {
	//check that card is linked with account data
	ifstream inFile;
	inFile.open(cashCardFileName.c_str(), ios::in); 	//open file
	assert(!inFile.fail()); //file should exist at this point 
	//check that it contains some info in addition to card number
	string temp;
	inFile >> temp; //read card number
	inFile >> temp;	//ready first account data or eof if end of file found
	return (!inFile.eof());
}

void ATM::activateCard(const string& filename) {
	//dynamically create a cash card to store data from file
	//effectively create the cash card instance with the data
	assert(p_theCard_ == nullptr);
	p_theCard_ = new Card;
	assert(p_theCard_ != nullptr);
	p_theCard_->readInCardFromFile(filename);
}

void ATM::releaseCard() {
	//release the memory allocated to the dynamic instance of a card
	delete p_theCard_;
	p_theCard_ = nullptr;
}
//static member function
char ATM::getAccountTypeCode(const string& filename) {
	//(simply) identify type/class of account from the account number
	//starts with 0 for bank account, 1 for current account, 2 for saving account, etc.
	return filename[13]; //14th char from the filename ("data/account_101.txt")
}

BankAccount* ATM::activateAccount(const string& filename) {
	//Pre-condition: type of the account is valid
	assert(BankAccount::getAccountType(filename) != "UNKNOWN");
	//effectively create the active bank account instance of the appropriate class
	//and store the appropriate data read from the file
	BankAccount* p_BA(nullptr);
	switch (getAccountTypeCode(filename))
	{
		case CURRENTACCOUNT_TYPE:	//NOT NEEDED WITH ABSTRACT CLASSES
			p_BA = new CurrentAccount;    //points to a BankAccount object
			break;
		case CHILDACCOUNT_TYPE:
			p_BA = new ChildAccount;
			break;
		case ISAACCOUNT_TYPE:
			p_BA = new ISAAccount;
			break;
	}
	assert(p_BA != nullptr); //check that the dynamic allocation has succeeded
	p_BA->readInBankAccountFromFile(filename); //read account details from file
	//use dynamic memory allocation: the bank account created will have to be released in releaseAccount
	return p_BA;
}

BankAccount* ATM::releaseAccount(BankAccount* p_BA, string filename) {
	//store (possibly updated) data back in file
	assert(p_BA != nullptr);
	p_BA->storeBankAccountInFile(filename);
	//effectively destroy the bank account instance
	delete p_BA;
	return nullptr;
}