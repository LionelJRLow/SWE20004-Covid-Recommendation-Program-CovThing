#include "patient.h"
#include "highrisk.h"
#include "symptom.h"

using namespace std;
int main() {
	int choice;
	vector<string> patients;//change get to accept patients add patientdata into patients
	patient p;
	HighRisk hr;
	hr.CreateHighRisk();
	Symptoms s;
	s.CreateSymptoms();
	cout << "1 - Enter Data" << endl
		<< "2 - Display Location" << endl
		<< "3 - Display Symptom" << endl
		<< "4 - Display Covid Positive" << endl
		<< "5 - Update Patient" << endl
		<< "6 - Quit" << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		p.InsertPatient();
		break;

	case 2:
		hr.DisplayHighRisk();
		break;

	case 3:
		s.DisplaySymptoms();
		break;

	case 4:

		break;

	case 5:
		p.getPatient(patients);
		cout << "Enter id : "; cin >> choice;
		p.updatePatient(choice,patients);
		break;

	case 6:
		cout << "exiting program" << endl;
		return 0;
		break;

	default:
		cout << "Didnt enter valid option" << endl;
		break;
	}
	return 0;
	//hr.updateHighRisk();
	//s.Exit();
}