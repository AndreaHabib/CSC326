#ifndef GARAGE
#define GARAGE

#include "ArrayStack.h"
#include <fstream>
#include <string>
using namespace std;
class cars {
private:
	string platNum;
	int movCount;
public:
	cars() {
		platNum = "";
		movCount = 0;
	}
	cars(const string& plateNumber) {
		platNum = plateNumber;
		movCount = 0;
	}
	string getPlat() { return this->platNum; }
	int getCount() { return this->movCount; }
	void incMov() { movCount++; }
	void setCount(int countM) { movCount = countM; }
	void setPlat(const string& plateNumber) { platNum = plateNumber; }
	friend ostream& operator<< (ostream& os, cars& c)
	{
		os << c.platNum << " " << c.movCount << endl;
		return os;
	}
	friend bool operator== (const cars& car1, const cars& car2) {
		return car1.platNum == car2.platNum;
	}
};
template<class ItemType>
class Garage
{
private:
	ArrayStack<ItemType> lane1, lane2, street;

public:
	void display();
	void arrival(ItemType& in);
	void departure(ItemType& in);
	void movCars(ArrayStack<ItemType>&, ArrayStack<ItemType>&);
	void clearSt();
	bool search(ItemType);
	/*void retrieveCar(ArrayStack<ItemType>& dest, ArrayStack<ItemType>& source, int current, const cars& car);*/
};

#endif