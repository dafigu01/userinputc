#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void reverseStr(string& str) {

	int n = str.length();
	for (int i = 0; i < n / 2; i++)
		swap(str[i], str[n - i - 1]);
}

int main() {
	ofstream outputfile;
	fstream outputfile1;
	fstream inputfile1;
	string userInput;

	cout << "Enter Something Here: " << endl;
	getline(cin, userInput);
	outputfile.open("/Users/danielfigueroa/Desktop/CSC450_CT5_mod5.txt", ios::app);
	outputfile << userInput << endl;

	ifstream inputfile("/Users/danielfigueroa/Desktop/CSC450_CT5_mod5.txt");
	ofstream outputfile2("/Users/danielfigueroa/Desktop/CSC450_CT5_mod5-2.txt");
	outputfile2 << inputfile.rdbuf();
	outputfile.close();
	outputfile2.close();

	inputfile1.open("/Users/danielfigueroa/Desktop/CSC450_CT5_mod5-2.txt", ios::in);
	outputfile1.open("/Users/danielfigueroa/Desktop/CSC450_CT5_mod5-reverse.txt", ios::in|ios::out|ios::trunc);

	while(inputfile1) {
		getline(inputfile1, userInput);
		reverseStr(userInput);
		outputfile1<<userInput<<endl;
	}
	return 0;
}
