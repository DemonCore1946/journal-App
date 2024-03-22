#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

class journal{
	public:
		int rem();
		int pop();
		int add();
		int see();
}jour;

int main(){
	int code;

	while (1){
		int option;

		cout << "------------JOURNAL-------------" << endl;
		cout << "|" << endl;
		cout << "|   1) Add" << endl;
		cout << "|   2) See" << endl;
		cout << "|   3) Pop" << endl;
		cout << "|   4) Clear" << endl;
		cout << "|   5) Exit" << endl;
		cout << "|" << endl;
		cout << "|   Choice :: ";
		cin >> option;

		cout << "|" << endl;

		switch(option){
			case(1):
				code = jour.add();
			break;
			case(2):
				code = jour.see();
			break;
			case(3):
				code = jour.pop();
			break;
			case(4):
				code = jour.rem();
			break;
			case(5):
				return 0;
			break;
			default:
				cout << "Invalid Input" << endl;
		}
	}
}

int journal::rem(){
	int code = remove("data/journal.txt");

	fstream file;
	file.open("data/journal.txt");
	file.close();

	return code;
}

int journal::pop(){
	int code;

	string line;
	vector<string> lines;

	ifstream inFile("data/journal.txt");

	while (getline(inFile, line)){
		lines.push_back(line);
	}

	inFile.close();

	code = remove("data/journal.txt");

	fstream outFile("data/journal.txt", ios::app);

	for (int i = 0; i < lines.size()-1; i++){
		outFile << lines[i] << "\n";
	}

	outFile.close();

	return 0;
}
int journal::add(){
	string answer;

	cout << "------------JOURNAL::ADD-------------" << endl;
	cout << "|" << endl;
	cout << "|  What do you want to add :: ";

	cin.ignore();
	getline(cin, answer);

	ofstream file;
	file.open("data/journal.txt", ios::app);
	file << answer << "\n";
	file.close();

	cout << "|" << endl;

	return 0;
}

int journal::see(){
	string contents;

	string nextline = "\n";
	string word;
	ifstream file;
	file.open("data/journal.txt");

	cout << "------------JOURNAL::SEE-------------" << endl;
	cout << "|" << endl;
	
	while (getline(file, word)){
		cout << "|  " << word << endl;
	}

	cout << "|" << endl;
	
	file.close();

	return 0;
}
