#include <cassert>       // For assert
#include "Garage.h"  // Header file
#include <iostream>
#include <fstream>
using namespace std;
//ARRAYSTACK IMPLEMENTATION
template<class ItemType>
ArrayStack<ItemType>::ArrayStack() : top(-1)
{
}  
template<class ItemType>
void ArrayStack<ItemType>::displayItems() //display item for specific stack lane1/lane2/street
{
    if (!isEmpty()) {
        for (int i = 0; i <= top; i++)
        {
            cout << i << ": " << items[i] << endl;
        }
    }
    else {
        cout << "There are no cars here!" << endl;
    }
}
// Copy constructor and destructor are supplied by the compiler
template<class ItemType>
bool ArrayStack<ItemType>::isFull() const
{
	return top == MAX_STACK - 1;
}
template<class ItemType>
bool ArrayStack<ItemType>::isEmpty() const
{
	return top < 0;
}  // end isEmpty

template<class ItemType>
bool ArrayStack<ItemType>::push(const ItemType newEntry)
{
	bool result = false;
	if (top < MAX_STACK - 1)  // Does stack have room for newEntry?
	{
		top++;
		items[top] = newEntry;
		result = true;
	}  // end if

	return result;
}  // end push


template<class ItemType>
bool ArrayStack<ItemType>::pop()
{
	bool result = false;
	if (!isEmpty())
	{
		top--;
		result = true;
	}  // end if

	return result;
}  // end pop


template<class ItemType>
ItemType ArrayStack<ItemType>::peek() const
{
	assert(!isEmpty());  // Enforce precondition

	// Stack is not empty; return top
	return items[top];
}  // end peek

template<class ItemType>
bool ArrayStack<ItemType>::contains(const ItemType& item) { //if car is present in stack of lane1/lane2/street
	for (int i = 0; i < top + 1; i++) {
		if (items[i] == item) {
			return true;
		}
		else {
			return false;
		}
	}
}
// end ARRAYSTACK IMPLEMENTATION

//GARAGE IMPLEMENTATION

template<class ItemType>
void Garage<ItemType>::arrival(ItemType& in) //Add cars to lanes
{
   ItemType car;
   if (!lane1.isFull())
   {
       lane1.push(in); //push in car from file to lane 1
       car = lane1.peek();
       cout << car << "Car has been added to lane 1!" << endl;
   }
   else if (!lane2.isFull())
   {
       lane2.push(in); //else push in car from file to lane 2
       car = lane2.peek();
       cout << car << "Car has been added to lane 2" << endl;
   }

    else //else assert
    {
       assert("Lanes and Street currently full!");
    }
}
template<class ItemType>
void Garage<ItemType>::departure(ItemType& out) {
    cars temp(out); //contruct temp car
	cars temp1; //default construct temp car
    if (lane1.contains(temp)) //if present in lane 1
    {
		while (lane1.peek().getPlat() != temp.getPlat()) //if not euqal
		{
			temp1.setPlat(lane1.peek().getPlat()); //keep moving cars until equal
			if (!lane2.isFull())
			{
				movCars(lane1, lane2); //lane 1 to lane 2
			}
			else
			{
				movCars(lane1, street); //else if lane 2 is full, lane 1 to street
			}
		}
		temp1 = lane1.peek();

		cout << temp.getPlat() << " has left Lane 1 and has moved " << temp1.getCount() << " times" << endl; //print
		clearSt(); //move cars back to lanes
	}
	else if (lane2.contains(temp)) //else present in lane 2
	{ //same process as lane 1
		while (lane2.peek().getPlat() != temp.getPlat()) //if not equal
		{
			temp1.setPlat(lane2.peek().getPlat());
			if (!lane1.isFull())
			{
				movCars(lane2, lane1);
			}
			else
			{
				movCars(lane2, street);
			}
		}
		temp1 = lane2.peek();

		cout << temp.getPlat() << " has left Lane 2 and has moved " << temp1.getCount() << " times" << endl;
		clearSt();
	}
}
template<class ItemType>
bool Garage<ItemType>::search(ItemType item) { //search for cars in lanes using contains() from ArrayStack class
	if (lane1.contains(item)) {
		cout << "Car is found in lane 1!" << endl;
		return true;
	}
	else if (lane2.contains(item)) {
		cout << "Car is found in lane 2!" << endl;
		return true;
	}
	else if (street.contains(item)) {
		cout << "Car is found on the street!" << endl;
		return true;
	}
	else {
		cout << "Car not found!" << endl;
		return false;
	}
}
template<class ItemType>
void Garage<ItemType>::movCars(ArrayStack<ItemType>& from, ArrayStack<ItemType>& to) { //to move cars from lane to lane or from lane to street
	cars temp; //default temp car
	temp.setPlat(from.peek().getPlat());
	temp.setCount(from.peek().getCount() + 1);
	if (to.push(temp)) //if true, then pop
	{
		from.pop();
	}
}
template<class ItemType>
void Garage<ItemType>::clearSt() { //move cars back to lanes when done departure
	while (!street.isEmpty()) {
		if (!lane1.isFull()) {
			movCars(street, lane1); //from street to lane 1
		}
		else {
			movCars(street, lane2); //from street to lane 2
		}
	}
}
template<class ItemType>
void Garage<ItemType>::display() { //display all the cars using displayItems() from ArrayStack class
    cout << "Cars in Lane 1: " << endl;
    lane1.displayItems(); //lane 1 print
    cout << "Cars in Lane 2: " << endl;
    lane2.displayItems(); //lane 2 print
    cout << "Cars in Street: " << endl;
    street.displayItems(); //street print
}
