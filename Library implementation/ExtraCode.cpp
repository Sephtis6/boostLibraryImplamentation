#include "stdafx.h"
#include <string>
#include <iostream>
#include <time.h>

//using namespace
using namespace std;

//this will replace my cout with a cooler name
void speak(string speakThis)
{
	cout << speakThis << endl;
}

//this will replace cin with a cooler name
string listen(string PromptUser)
{
	string userInput = "";
	cout << PromptUser << endl;
	cin >> userInput;
	return userInput;
}

//this will take the user input and place it into the correct responding vairable
string askText(string prompt)
{
	string text;
	cout << prompt;
	cin >> text;
	return text;
}
