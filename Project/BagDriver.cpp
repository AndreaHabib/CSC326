#include <iostream> // For cout and cin
#include <string>   // For string objects
#include "Bag.h"    // For ADT bag
#include <tuple>
using namespace std;
int isFragile(Bag<string>&, string);
int main()
{
	int numEgg, numBread, i;
	Bag<string> storeBag;
	Bag<string> fragileBag;

	storeBag.add("Egg");
	storeBag.add("Apples");
	storeBag.add("Milk");
	storeBag.add("Bread");
	storeBag.add("Cereal");
	storeBag.add("Sauce");
	cout << "Items in Bag: " << endl;
	storeBag.displayBagContents();
	cout << endl;
	numEgg = isFragile(storeBag, string("Egg"));
	numBread = isFragile(storeBag, string("Bread"));
	cout << "Number of items removed: Eggs: " << numEgg << " Bread: " << numBread << endl;

	for (i = 0; i < numEgg; i++) {
		fragileBag.add("Egg");
	}
	for (i = 0; i < numBread; i++) {
		fragileBag.add("Bread");
	}
	cout << endl;
	cout << "Items in Store Bag: " << endl;
	storeBag.displayBagContents();
	cout << endl;
	cout << "Items in Fragile Bag: " << endl;
	fragileBag.displayBagContents();

	return 0;
}; // end main
//template <class ItemType>
int isFragile(Bag<string>& bag, string item) {
	int numItems = 0;
	while (bag.contains(item)) {
		bag.remove(item);
		numItems++;
	}
	return numItems; 
}
//Items in Bag :
//Egg
//Apples
//Milk
//Bread
//Cereal
//Sauce
//
//Number of items removed : Eggs: 1 Bread : 1
//
//Items in Store Bag :
//Sauce
//Apples
//Milk
//Cereal
//
//Items in Fragile Bag :
//Egg
//Bread