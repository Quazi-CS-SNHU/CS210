/*
Author: Quazi Mainuddin
Date: 06/12/2025
Objective: The Corner Grocer needs a program that analyzes the text records they generate throughout the day. 
Records list items purchased in chronological order from the time the store opens to the time it closes. 
Outputs how often items are purchased.

Input file: CS210_Project_Three_Input_File.txt
Outout file: 
*/

//pre-processor directives
#include <iostream>
#include <fstream>
#include <string>
#include <map> //map data type is used here for frequency mapping
#include <iomanip>

using namespace std;

//Class ItemTracker
class ItemTracker {

//Private
private:
    map<string, int> itemFrequency; //map data type

    void loadItemsFromFile(const string& filename) {
        ifstream inputFile(filename); // read file
        string item;

        //handle error 
        if (!inputFile) {
            cerr << "Error: Could not open input file." << endl;
            exit(1);
        }

        //read the file if successful 
        while (inputFile >> item) {
            ++itemFrequency[item];
        }

        //close the file
        inputFile.close();
    }

    void writeFrequencyToFile(const string& filename) {
        ofstream outputFile(filename); //open file to write to

        for (const auto& pair : itemFrequency) {
            outputFile << pair.first << " " << pair.second << endl;
        }

        outputFile.close();//close output file
    }

public:
    //declare item tracker to read file and load items from file
    ItemTracker(const string& inputFile) {
        loadItemsFromFile(inputFile);
        writeFrequencyToFile("frequency.dat");
    }

    //Function to find item frequency
    void findItemFrequency(const string& item) const {
        auto it = itemFrequency.find(item);
        if (it != itemFrequency.end()) {
            cout << item << " was purchased " << it->second << " times.\n";
        } else {
            cout << item << " was not found in the purchase records.\n";
        }
    }

    //Function to print all frequencies
    void printAllFrequencies() const {
        for (const auto& pair : itemFrequency) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    //Print as a histrogram
    void printHistogram() const {
        for (const auto& pair : itemFrequency) {
            cout << setw(15) << left << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) {
                cout << "*";
            }//loop through frequency to create the histogram
            cout << endl;
        }
    }
};

//menu as a function call
void displayMenu() {
    cout << "\n========= Corner Grocer Item Tracker =========\n";
    cout << "1. Look up frequency of a specific item\n";
    cout << "2. Display all items with purchase frequencies\n";
    cout << "3. Display histogram of item purchases\n";
    cout << "4. Exit\n";
    cout << "============================================\n";
    cout << "Enter your choice: ";
}

int main() {
    ItemTracker tracker("CS210_Project_Three_Input_File.txt"); // define the input file and create the itemtracker class
    int choice; // menu choice from user
    string item;  // string to search

    //loop thru til exit choice
    do {
        displayMenu();
        cin >> choice;

        //choice input validation
        while (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 4: ";
            cin >> choice;
        }

        //use switch for appropriate selection from choice
        switch (choice) {
        case 1:
            cout << "Enter the item to search for: ";
            cin >> item;
            tracker.findItemFrequency(item);
            break;
        case 2:
            tracker.printAllFrequencies();
            break;
        case 3:
            tracker.printHistogram();
            break;
        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }

    } while (choice != 4);//exit choice selected

    return 0;
}
