//all the items/libraries that are included to be used
#include <boost/config.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/regex.hpp>
#include <boost/foreach.hpp>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
//list of namespaces used
using namespace std;
using namespace boost::gregorian;

//list of extra voids beside main
void reverseForeach();
void dataTime();
void regex();

//main void used
void main() {
	//string for the users name
	string userName = "";
	//asking the user to enter their name
	cout << "Please enter your name: ";
	cin >> userName;

	//making a hello string using the persons name
	string hello("Welcome" + userName + "to the program.");
	//using the boost::foreach to loop over each character in the statement and print it out ot the viewer
	BOOST_FOREACH(char ch, hello)
	{
		cout << ch;
	}

	//introduces the use of the boost::lambda in and stl function
	using namespace boost::lambda;
	typedef std::istream_iterator<int> in;
	//asks the user to enter a number
	cout << "Please enter a number" <<endl;
	for_each(
		in(cin), in(), cout << (_1 * 3) << " ");

	//takes the following statement and throws it through a few boost functions
	string s = "Time to test some boost libraries.";
	//this removes all spaces
	cout << boost::trim_left_copy(s) << "\n";
	//converts all letters to lower case
	cout << boost::to_lower_copy(s) << "\n";
	//this erases the fist occurance of the substring from the input 
	cout << boost::erase_first_copy(s, ".") << "\n";
	//removes all occurences of the string
	cout << boost::erase_all_copy(s, "raries") << "\n";

	//pause the allowing the viewer to read all the outputs
	system("pause");
	//runs the void for reverse foreach
	reverseForeach();
	//pause the allowing the viewer to read all the outputs
	system("pause");
	//runs the void for data time/gregorian
	dataTime();
	//pause the allowing the viewer to read all the outputs
	system("pause");
	//runs the void for regex
	regex();
	//pause the allowing the viewer to read all the outputs
	system("pause");
}

//void for reverse foreach
void reverseForeach() {
	//an array with 4 integers
	array<int, 4> a{ { 111, 333, 555, 666 } };
	//using the reverse foreach to display the array above backwards
	BOOST_REVERSE_FOREACH(int i, a) {
		cout << i << '\n';
	}
}

//void for data time/gregorian
void dataTime() {
	//uses a date based on the greogrian calender
	//for this one it is the date of the twin towers
	boost::gregorian::date d{ 2001, 7, 11 };
	//displays the year, month, day along with the end of the week and month
	cout << d.year() << '\n';
	cout << d.month() << '\n';
	cout << d.day() << '\n';
	cout << d.day_of_week() << '\n';
	cout << d.end_of_month() << '\n';

	//this is a string to hold an input
	string s;
	//in this case it is the day of your birth
	cout << "\nEnter birth your day YYYY-MM-DD (eg: 2002-02-01): ";
	cin >> s;
	//then it takes the entry and puts it through the gregorian function
	boost::gregorian::date birthday(boost::gregorian::from_simple_string(s));
	boost::gregorian::date today = boost::gregorian::day_clock::local_day();
	boost::gregorian::days days_alive = today - birthday;
	//this allows it to make an assumption on how many days you have been alive
	//based on the date of birth and the current date
	cout << "Days alive: " << days_alive.days() << endl;
}

//void for regrex
void regex() {
	//this is a string that says holds boost libraries
	string s = "Boost Libraries";
	//this gives the boost regex and expr 
	boost::regex expr{ "\\w+\\s\\w+" };
	//this uses the regex function to match string s with the regex expr and the displays it
	cout << boost::regex_match(s, expr) << '\n';
	//this takes whether the regex match is trye or false due to boolalpha and displays it
	cout << boolalpha << boost::regex_match(s, expr) << '\n';
}