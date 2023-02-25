// Nicole Swanson
// CS 210 Project 3
// 2/19/23

#include<fstream>
#include<iostream>
#include<map>

using namespace std;

// create a class for the grocer
class CornerGrocer {

// create a private member for declaring variable
private:
	map<string, int > purchaseFrequencyMap;   // create a map

// create a public class for functions that can 
public:
	void readFile(string myFile1) {    // read input file function
		ifstream inputFile;
		inputFile.open("CS210_Project_Three_Input_File.txt file.docx");

		if (inputFile.is_open()) {
			string produceName;
			while (inputFile >> produceName) {  // while loop to see produce items in file
				purchaseFrequencyMap[produceName]++;
			}
			inputFile.close();
		}
		else {
			cout << "Could not open file" << endl;
		}
	}
	void writeFile(string myFile2) {   // write to new file function
		ofstream outputFile;
		outputFile.open("frequency.data.docx");
		if (outputFile.is_open()) {
			for (auto const& produceName : purchaseFrequencyMap) {  // for loop to get produce items from file to send to saved file and save
				outputFile << produceName.first << " " << produceName.second << endl;
			}
			outputFile.close();
		}
		else {
			cout << "Could not open file" << endl;
		}
	}
	int searchProduce(string produceName) {   // function to search map for produce purchase options 
		if (purchaseFrequencyMap.find(produceName) == purchaseFrequencyMap.end()) {  // for loop to search input file
			return 0;
		}
		return purchaseFrequencyMap[produceName];
	}
	void printFrequencyList() {   // funtcion to print list of produce purchase amounts
		for (auto const& produceName : purchaseFrequencyMap) {  // for loop to print items from input file
			cout << produceName.first << " " << produceName.second << endl;
		}
	}
	void printHistogram() {   // function to print histogram 
		for (auto const& produceName : purchaseFrequencyMap) {  // for loop to print items from input file
			cout << produceName.first << " ";
			for (int i = 0; i < produceName.second; i++) {  // for loop to check for quantities and print * for output
				cout << "*";
			}
			cout << endl;
		}

	}
};

// create a menu to choose from
void printMenu() {
	cout << "Corner Grocer Produce Search" << endl;
	cout << "1. Search for produce item and display purchase frequency" << endl;
	cout << "2. Print all produce with purchase frquency" << endl;
	cout << "3. Print Histogram of produce and purchases frequency";
	cout << "4. Exit" << endl;
}

// create main
int main() {
	// declare variables
	CornerGrocer cornerGrocer;
	int choice;
	string produceName;

	// print the menu
	printMenu;
	cin >> choice; // get user input from menu options
	// while loop uses member responses to get further input and or give the appropriate ouput
	while (choice == 1) {
		cout << "Enter produce item name" << endl;
		cin >> produceName;  // get user input for produce item name for option 1
		cout << "The purchase frequency of " << produceName << " is " << cornerGrocer.searchProduce(produceName) << endl;  // output for menu option 1
	}
	if (choice == 2) {
		cornerGrocer.printFrequencyList();  // print list of produce with quantity for option 2
	}
	if (choice == 3) {
		cornerGrocer.printHistogram();   // print histogram if option 3 chosen
	}
	if (choice == 4) {  // exit for option 4
		return 0;
	}

	return 0;
}
