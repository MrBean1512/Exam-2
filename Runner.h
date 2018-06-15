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
