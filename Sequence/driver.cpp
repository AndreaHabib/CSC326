#include<iostream>
#include "SEQUENCE.h"
#include "sequence.cpp"
#include<string>
#include<cstdlib>
using namespace std;
template <class value_type>
void selection(sequence<value_type>& call, int choice);
void menu();
int main() {
	int choice;
	sequence<int> call;
	string loop = "y";
	while (loop == "y" || loop == "Yes" || loop == "yes" || loop == "Y") {
		system("color 0F");
		system("CLS");
		cout << "You currently have " << call.num_element() << " items." << endl << flush;
		menu();
	    cin >> choice;
		selection(call, choice);
		cout << "Would you like to choose another operation?" << endl;
		loop = "k";
		while (loop != "y" && loop != "Yes" && loop != "yes" && loop != "Y" && loop != "N" && loop != "No" && loop != "n" && loop != "no") {
			cin >> loop;
			if (loop != "y" && loop != "Yes" && loop != "yes" && loop != "Y" && loop != "N" && loop != "No" && loop != "n" && loop != "no") {
				cin.clear();
				cout << "Please enter Yes or No!" << endl;
				cin.ignore();
			}
		}
	}
	system("PAUSE");
	return 0;
}
void menu() {
	cout << "------------------------------" << endl;
	cout << "1. Add new Item" << endl;
	cout << "2. Insert new Item" << endl;
	cout << "3. Set any Item" << endl;
	cout << "4. Remove any Item" << endl;
	cout << "5. Display array elements" << endl;
	cout << "6. Display array element at specific location" << endl;
	cout << "------------------------------" << endl;
	cout << "Please enter a number between 1 and 6: (-1 to exit) ";
}
template<class value_type>
void selection(sequence<value_type>& call, int choice) {
	value_type entry;
	int position;
	switch (choice) {
	case 1:
		cout << "Enter Item to add: ";
		cin >> entry;
		call.push_back(entry);
		break;
	case 2:
		cout << "Enter Item to insert: ";
		cin >> entry;
		cout << "Enter which position to insert: ";
		cin >> position;
		call.insert(entry, position);
		break;
	case 3:
		cout << "Enter Item to set: ";
		cin >> entry;
		cout << "Enter which position to overwrite: ";
		cin >> position;
		call.set(entry, position);
		break;
	case 4:
		cout << "Enter which position to remove: ";
		cin >> position;
		call.remove_current(position);
		break;
	case 5:
		call.print();
		break;
	case 6:
		cout << "Enter the position of the element you want to display: ";
		cin >> position;
		if (call.at(position) != -1) {
			cout << call.at(position) << endl;
		}
		break;
	case -1:
		exit(1);
	default:
		cout << "Invalid!" << endl;
		break;
	}
}
