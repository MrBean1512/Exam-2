//I affirm that all code given below was written solely by me, David Martin, and that any help I received adhered to the rules stated for this exam.
#ifndef RUNNER_H_
#define RUNNER_H_
#include <iostream>
using namespace std;
class Runner
{
public:			
	Runner();
	Runner(string, string, int);
	string getFirstName();
	string getLastName();
	int getPace();
	void setPace(int);
	bool operator<(Runner& r) { return (pace < r.getPace()); }
	bool operator>(Runner& r) { return (pace > r.getPace()); }
private:
	string firstName;
	string lastName;
	int pace;
};
#endif
