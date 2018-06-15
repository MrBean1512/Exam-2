#include "Runner.h"
#include <iostream>
#include <string>
using namespace std;

Runner::Runner()	//this is just used for the temp runner
{
	firstName = "place";
	lastName = "holder";
	pace = 0;
}

Runner::Runner(string first, string last, int pr)
{
	firstName = first;
	lastName = last;
	pace = pr;
}

string Runner::getFirstName()
{
	return firstName;
}

string Runner::getLastName()
{
	return lastName;
}

int Runner::getPace()
{
	return pace;
}

void Runner::setPace(int pr)
{
	pace = pr;
}