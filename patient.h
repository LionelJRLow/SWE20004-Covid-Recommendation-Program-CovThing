#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;
string totalpatient[20][9];
class patient {
public:

	int pid,dob;
	string name, address, travel, symptom, location;
	string test="write over this";
	string status = "alive";
	string testPatient(string location);//get back test
	void InsertPatient();//insert data
	void getPatient(vector<string> &patients);//get entire patient db
	void updatePatient(int id, vector<string>& patients);//update patientdb
	//void MultiInsert(int i);
};

string patient::testPatient(string location) {
	string line;//to store line
	ifstream openFile("HighRisk.txt");
	while (!openFile.eof()) {
		getline(openFile, line);
		if (line.find(location) != string::npos)//if found a match return recommend
		{										//npos will return true if no match
		//	cout << "Recommend";
			return "Recommend";
		}
		else {
		//	cout << "Not Recommend";
			return "Not Recommend";//return not recommend if no match
		}
	}
	openFile.close();
}

void patient::InsertPatient() {
	int id=0;
	string sline;
	ofstream writepatient;//for inserting into database
	ifstream read("patientno.txt");//read from patientno file
	//code to make an auto incrementing id
	if (read.fail()) {//if fail create and open again
		read.close();
		ofstream write("patientno.txt");
		write.close();
		read.open("patientno.txt");
	}
	getline(read, sline);//get patient no
	read.close();
	if (sline.empty()) {//if file was just created enter 0 into file
		ofstream write("patientno.txt");
		write << 0 << endl;
		write.close();
	}
	else {
		read.open("patientno.txt");
		getline(read, sline);
		id = stoi(sline);//get from patient no
		ofstream write("patientno.txt");
		write << id+1 << endl;//increment by 1
		write.close();
	}//end of auto increment id code

	
	/*if (sline.empty()) {//if file is empty, enter the new number of records into it, 
		id = 1;
		read.close();
		ofstream writeif("patientdetail.txt");
		writeif << id << endl;
		writeif.close();
	}
	else { //if file has existing number of records
		id = stoi(sline);
		ofstream writeelse("temppatient.txt",fstream::app);//create temp file
		writeelse << id + 1 << endl;
		while (!read.eof()) {//get each line from database
			getline(read, sline);
			writeelse << sline << endl;//copy into temp file	
		}
		writeelse.close();
		read.close();
		remove("patientdetail.txt");//delete old file
		ofstream copy("patientdetail.txt",fstream::app);
		read.open("temppatient.txt");
		while (!read.eof()) {//get each line from temp file
			getline(read, sline);
			copy << sline << endl;//copy into copy file
		}
		copy.close();
		read.close();
		//remove("temppatient.txt")
	}*/
	
	patient p;
	string patientarray[9] = {};
	p.pid = id;
	//id++


	cout << "Enter Patient Name : ";//name
	cin.ignore();
	getline(cin, p.name); cout << endl;//program ignoring this rn

	cout << "Enter Date of Birth : ";//date of birth
	cin >> p.dob; cout << endl;

	cout << "Enter Address : ";//address
	cin.ignore();
	getline(cin, p.address); cout << endl;

	cout << "Enter Overseas Travel : ";//travel
	//cin.ignore(); skipped the first line
	getline(cin, p.travel); cout << endl;

	cout << "Do you have symptoms? Enter no if none : ";//symptoms
	getline(cin, p.symptom); cout << endl;

	cout << "Enter Location : ";//location
	getline(cin, p.location); cout << endl;

	p.test=(testPatient(p.location));

	patientarray[0] = p.pid;
	patientarray[1] = p.name;
	patientarray[2] = p.dob;
	patientarray[3] = p.address;
	patientarray[4] = p.travel;
	patientarray[5] = p.symptom;
	patientarray[6] = p.location;
	patientarray[7] = p.test;
	patientarray[8] = p.status;
	
	if (writepatient.is_open())//error testing
	{ writepatient.close(); }

	writepatient.open("patientdetail.txt", fstream::app);
	//enter data into db
	writepatient << p.pid << endl;
	writepatient << p.name << endl;
	writepatient << p.dob << endl;
	writepatient << p.address << endl;
	writepatient << p.travel << endl;
	writepatient << p.symptom << endl;
	writepatient << p.location << endl;
	writepatient << p.test << endl;
	writepatient << p.status << endl;

	writepatient.close();

	for (int i = 0; i < 9; i++) {
		cout << patientarray[i]<<endl;
	}
	/*
	totalpatient[id][0] = patientarray[0];
	totalpatient[id][1] = patientarray[1];
	totalpatient[id][2] = patientarray[2];
	totalpatient[id][3] = patientarray[3];
	totalpatient[id][4] = patientarray[4];
	totalpatient[id][5] = patientarray[5];
	totalpatient[id][6] = patientarray[6];
	totalpatient[id][7] = patientarray[7];
	totalpatient[id][8] = patientarray[8];
	*/
	//cant store existing array into another array in c++ so i did this instead
}

void patient::getPatient(vector<string> &patients) {
	ifstream read("patientdetail.txt");
	string line;
	while (!read.eof())// while not end of file 
	{
		getline(read, line);//get line and insert into vector
		patients.push_back(line);
	}
	read.close();
}

void patient::updatePatient(int id, vector<string>& patients) {//work to be done 
	//if test recommend, update location datetime status test
	//if not recommend, update status + test
	string sid = to_string(id);//id we get from user
	string line;//line we get from vector
	string input;//user input
	string symptom;
	patient p;
	ofstream write("patientdetail.txt");
	for (int i=0;i<patients.size();i++)//increment by 1 until reach end of vector
	{ 
		line = patients[i];
		if (line == sid) {
			cout << patients[i] << endl//id
				<< patients[i + 1] << endl//name
				<< patients[i + 2] << endl//address
				<< patients[i + 3] << endl//dob
				<< patients[i + 4] << endl//travel
				<< patients[i + 5] << endl//symptom
				<< patients[i + 6] << endl//location
				<< patients[i + 7] << endl//test
				<< patients[i + 8] << endl;//status
			symptom = patients[i + 5];
			//p.InsertPatient();//will skip and iteration of id for next insert but thats not important
			//patients[i] = p.pid;
			//Cannot use InsertPatient, rewrite it
			if (patients[i + 7] == "Not Recommend") {
				cout << "Enter Patient Covid Test: ";
				cin >> input;
				patients[i + 7] = input;
				cout << "Enter Patient Status: ";
				cin >> input;
				patients[i + 8] = input;
			}
			else {
				ifstream openFile("Symptoms.txt");
				while (!openFile.eof()) {
					getline(openFile, line);
					if (line.find(location) != string::npos)//if found a match get input
					{										//npos will return true if no match
						cout << "Enter DateTime: ";
						cin >> input;
						patients[i + 3] = input;
						cout << "Enter Location: ";
						cin >> input;
						patients[i + 6] = input;
						cout << "Enter Patient Covid Test: ";
						cin >> input;
						patients[i + 7] = input;
						cout << "Enter Patient Status: ";
						cin >> input;
						patients[i + 8] = input;
					}
				}

			}
		}
	}
		
	for (int i = 0; i < patients.size(); i++)
	{
		write << patients[i]<<endl;
	}
	write.close();
	
	
	/*totalpatient[id][0] = p.pid;
	totalpatient[id][1] = p.name;
	totalpatient[id][2] = p.dob;
	totalpatient[id][3] = p.address;
	totalpatient[id][4] = p.travel;
	totalpatient[id][5] = p.symptom;
	totalpatient[id][6] = p.location;
	totalpatient[id][7] = p.test;
	totalpatient[id][8] = p.status;*/
}
