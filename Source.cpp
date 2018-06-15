//I affirm that all code given below was written solely by me, David Martin, and that any help I received adhered to the rules stated for this exam.
#include <fstream>
#include <string>
#include <iostream>
#include "Runner.h"
#include <vector>
using namespace std;

void Sort(vector<Runner> &roster, int&);
void Colors(vector<Runner> &roster);

int main()
{
	cout << "Creating tiers" << endl;
	ifstream roster("registrants.txt");
	if (!roster) {		//checks if file exists
		cout << "Registrants file doesn't exist!" << endl;
		roster.close();
		return 0;
	}

	string tempFirst;
	string tempLast;
	int tempPace;
	int size = 0;
	vector<Runner> runners;
	while (!roster.eof())		//this loop reads the registrants.txt file and stores the runners into a vector
	{
		if (roster.eof()) break;
		size++;
		roster >> tempFirst >> tempLast >> tempPace;
		runners.push_back(Runner(tempFirst, tempLast, tempPace));
	}
	roster.close();

	Sort(runners, size);
	Colors(runners);

	cout << "Runners have been seeded" << endl;

	return 0;
}

//this function sorts the runners into order
void Sort(vector<Runner> &roster, int &numOfRunners)
{
	cout << "sorting runners" << endl;
	int size = numOfRunners;
	Runner temp;
	for (int i = 0; i < size; i++)
	{
		temp.setPace(0);
		for (int j = 0 + i; j < size; j++)
		{
			if (roster[i]>roster[j])
			{
				temp = roster[j];
				roster[j] = roster[i];
				roster[i] = temp;
			}
		}
	}
	cout << "done." << endl;
}

//this function assigns runners to their colors based on their seed pace
void Colors(vector<Runner> &roster)
{
	string colors[7] = { "white.txt","yellow.txt","green.txt",
		"orange.txt","blue.txt","lylac.txt","red.txt" };
	int tiers[7] = { 360,420,480,540,600,720,1200 };
	int seedPlace = 0;	//used to calculate location in the vector
	int seedTime = 0;
	for (int i = 0; i < 7; i++)
	{
		cout << "outstreaming color: "<<i+1<<endl;
		ofstream stream;
		stream.open(colors[i]);
		while (seedTime < tiers[i])		//stuff related to sending runners into the txt files
		{
			stream << roster[seedPlace].getFirstName() << " " << roster[seedPlace].getLastName() << " " <<
				roster[seedPlace].getPace() << "#";	//I included this '#' so that it would be easy to use the getline function later on if desired
			seedTime = roster[seedPlace].getPace();
			seedPlace++;
			if (seedPlace == roster.size()) break;
		}
		stream.close();
	}
	cout << "done." << endl;
}
