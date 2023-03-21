#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> 
#include <iomanip>

using namespace std;

class Symptoms
{

public:
	void CreateSymptoms()
	{
		// Create and open a text file
		ofstream MyFile("Symptoms.txt");
		MyFile << "Low Risk\tMedium Risk\tHigh Risk\nFever\nDry Cough";
	}

	void DisplaySymptoms()
	{
		string Symptoms_record;
		// Read from file
		ifstream record("Symptoms.txt");
		if (record.is_open())
		{
			string line;
			//Formats the table structure
			while (getline(record, line)) {
				cout << line << '\n';
			}
			cout << endl; //New line
			record.close();
		}
		else
		{
			cout << "Error! Could not find Symptoms record" << endl;

		}
		// Close the file
		record.close();
	}
	//Exit the app
	void Exit()
	{
		cout << "Goodbye\n" << endl;
		exit(0);
	}



};