//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number: 1
//Team: 
//Alex Fullarton, 26038657, CS4G
//Jake Hanne, 26027599, CS4G
//Dave Harrison, 26011054, CS4G

#ifndef ConstantsH
#define ConstantsH

#include <string>
using namespace std;

//menu command
const int QUIT_COMMAND(0);

//card state
const int VALID_CARD(0);
const int UNKNOWN_CARD(1);
const int EMPTY_CARD(2);

//account state
const int VALID_ACCOUNT(0);
const int UNKNOWN_ACCOUNT(1);
const int UNACCESSIBLE_ACCOUNT(2);
const int INVALID_ACCOUNT_TYPE(3);

//account type
const char BANKACCOUNT_TYPE('0');
const char CURRENTACCOUNT_TYPE('1');
const char SAVINGSACCOUNT_TYPE('2');
const char CHILDACCOUNT_TYPE('3');
const char ISAACCOUNT_TYPE('4');
const char UNKNOWN_ACCOUNT_TYPE('x');

//ressource path
const string FILEPATH("data\\");

#endif