//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)

#include "Date.h"

//---------------------------------------------------------------------------
//Date: class implementation
//---------------------------------------------------------------------------

//____public member functions

//____constructors & destructors
Date::Date() 						//default constructor
: day_(0), month_(0), year_(0)
{}
Date::Date(int d, int m, int y) 	//constructor
: day_(d), month_(m), year_(y)
{}

//____other public member functions
int Date::getDay() const {
	return day_;
}
int Date::getMonth() const {
	return month_;
}
int Date::getYear() const {
	return year_;
}
const Date Date::currentDate() {	//returns the current date
	time_t now(time(0));
	struct tm t;
	localtime_s(&t, &now);
	return Date(t.tm_mday, t.tm_mon + 1,  t.tm_year + 1900);
}
bool Date::isValid(Date cd)
{
	bool valid(false);

	//If date is greaterthan or equal to creation date and less than or equal to current date
	if (!((*this) < cd) && !(currentDate() < (*this)))
	{
		switch (month_)
		{
		//28 days
		case 2:
			if ((day_ <= 28) && (day_ >= 1))
				valid = true;
			break;
		//30 days
		case 4:
		case 6:
		case 9:
		case 11:
			if ((day_ <= 30) && (day_ >= 1))
				valid = true;
			break;
		//31 days
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if ((day_ <= 31) && (day_ >= 1))
				valid = true;
			break;
		default:
			break;
		}	
	}

	return valid;
}
void Date::setDate(int d, int m, int y) {
	day_ = d;
	month_ = m;
	year_ = y;
}
string Date::toFormattedString() const {
//return date formatted as string ("DD/MM/YYYY")
	ostringstream os;
	os << setfill('0');
	os << setw(2) << day_ << "/";
	os << setw(2) << month_ << "/";
	os << setw(4) << year_;
	return (os.str());
}

ostream& Date::putDataInStream(ostream& os) const {
//put (unformatted) date (D/M/Y) into an output stream
	os << day_ << "/";
	os << month_ << "/";
	os << year_;
	return os;
}
istream& Date::getDataFromStream(istream& is) {
//read in date from (semi-formatted) input stream (D/M/Y)
	char ch;			//(any) colon field delimiter
	is >> day_ >> ch >> month_ >> ch >> year_;
	return is;
}

//---------------------------------------------------------------------------
//overloaded operator functions
//---------------------------------------------------------------------------

bool Date::operator==(const Date& d) const { //comparison operator
	return
		((day_ == d.day_) &&
		 (month_ == d.month_) &&
		 (year_ == d.year_));
}
bool Date::operator!=(const Date& d) const {
	return (!(*this == d));
}
bool Date::operator<(const Date& d) const { //NEW
//true if (strictly) earlier than d (i.e., *this < d)
	return ((year_ < d.year_)
	     || ((year_ == d.year_) && (month_ < d.month_) )
	     || ((year_ == d.year_) && (month_ == d.month_) && (day_ < d.day_)));
}

bool Date::operator>(const Date& d) const { //NEW
											//true if (strictly) earlier than d (i.e., *this < d)
	return (d < (*this));

}

//---------------------------------------------------------------------------
//non-member operator functions
//---------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Date& aDate) {
    return (aDate.putDataInStream(os));
}
istream& operator>>(istream& is, Date& aDate) {
	return (aDate.getDataFromStream(is));
}
