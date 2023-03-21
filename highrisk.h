#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


class HighRisk
{

public:
	void CreateHighRisk()
	{
		// Create and open a text file
		ofstream MyFile("HighRisk.txt");
	}

	void DisplayHighRisk()
	{
		string HighRiskRecord;
		int i = 1;
		// Read from the text file using user input to get file.
		ifstream record("HighRisk.txt");
		if (record.is_open())
		{
			cout << setfill('-') << setw(5) << "-" << " High Risk Locations " << setfill('-') << setw(5) << "-" << endl;
			cout << setfill(' ');
			while (getline(record, HighRiskRecord))
			{
				cout << i << ". " << HighRiskRecord << endl;
				i++;
			}
		}
		else
		{
			cout << "Error!" << endl;
			cout << "Could not open Records for Students" << endl;
		}
		// Close the file
		record.close();
	}

	void updateHighRisk(string location)
	{
		ofstream record("HighRisk.txt");
		record << location;
	}

};