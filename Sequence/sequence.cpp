#include "SEQUENCE.h"
#include<iostream>
#include<string>
#include <windows.h>
#include <cassert>
#define assertm(exp, msg) assert(((void)msg, exp))
using namespace std; 
template <class value_type>
sequence<value_type>::sequence() {
	data = new value_type[10];
	capacity = 10;
	num_used = 0;
}
template <class value_type>
sequence<value_type>::sequence(int size) {
	data = new value_type[size];
	capacity = size;
	num_used = 0;
}
template <class value_type>
sequence<value_type>::~sequence() {
	delete[] data;
	data = NULL;
}
template <class value_type>
bool sequence<value_type>::full() const{
	return (num_used == capacity);
}
template <class value_type>
bool sequence<value_type>::empty() const {
	return (num_used == 0);
}
template <class value_type>
int sequence<value_type>::num_element() const {
	return num_used;
}
template <class value_type>
int sequence<value_type>::max_capacity() const {
	return capacity;
}
template <class value_type>
value_type sequence<value_type>::at(int position) const {
	system("CLS");
	if (!empty()) {
		assertm(position > -1 && position < num_used, "GOING OUT OF BOUNDS");
		return data[position];
	}
}
template <class value_type>
void sequence<value_type>::set(const value_type& entry, int position) {
	system("CLS");
	assert(position > -1 && position < num_used);
	if (!empty()) {
			data[position] = entry;
			cout << entry << " has been SET at position: " << position << "!" << endl << flush;
	}
	else {
		cout << "No element to set!" << endl << flush;
	}
}
template <class value_type>
void sequence<value_type>::insert(const value_type& entry, int position) {
	system("CLS");
	if (!empty()) {
		assertm(position > -1 && position < num_used + 1, "GOING OUT OF BOUNDS");
		num_used++;
		for (int i = num_used - 1; i >= position; i--)
		{
			data[i + 1] = data[i];
		}
	}
	else {
			cout << "Unable to insert!" << endl;
			return;
	}
		data[position] = entry;
		cout << entry << " has been INSERTED to position: " << position << "!" << endl;
}
template <class value_type>
void sequence<value_type>::push_back(const value_type& entry) {
	system("color 0A");
	system("CLS");
	if (!full()) {
		data[num_element()] = entry;
	}
	else {
		expand();
		data[num_element()] = entry;
	}
	num_used++;
	cout << entry << " has been ADDED to position: " << num_element() - 1 << "!" << endl << flush;
}
template <class value_type>
void sequence<value_type>::remove_current(int position) {
	system("color 0C");
	system("CLS");
	if (!empty()) {
		assertm(position > -1 && position < max_capacity(), "GOING OUT OF BOUNDS");
		if (position <= num_used) {
			num_used--;
			for (int j = position; j < num_used; j++)
				data[j] = data[j + 1];
			cout << data[position] << " has been REMOVED at position: " << position <<"!" << endl << flush;
		}
		else {
			cout << "Position doesn't exist!" << endl << flush;
		}
	}
	else {
		cout << "No items to remove!" << endl << flush;
	}
}
template <class value_type>
void sequence<value_type>::print()const {
	system("CLS");
	if (!empty()) {
		cout << "Elements in data:" << endl << flush;
		for (int i = 0; i < num_used; i++)
		{
			cout << i << ". " << data[i] << " " << endl;
		}
		cout << endl;
	}
	else {
		cout << "No elements to display!" << endl << flush;
	}
}
template <class value_type>
void sequence<value_type>::expand() {
	cout << "Resizing data..." << endl;
	int newSize = 2 * capacity;
	value_type* newData = new value_type[newSize];
	for (int i = 0; i < capacity; i++) {
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
	capacity = newSize;
}