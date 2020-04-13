#include <iostream>
#include "Garage.cpp"
#include "Garage.h"
void data(Garage<cars>&);
//void display(Garage<cars>&, ArrayStack<cars>&);
int main() {
	Garage<cars> parm;
	data(parm); //read in from file

	parm.display(); //display all items
	system("PAUSE");
	return 0;
}
void data(Garage<cars>& parm)
{
	ifstream inData;
	char code;
	inData.open("dataFile.txt"); //open file
	string platNum;
	while (!inData.eof()) {
		inData >> code >> platNum; //read in code and plate number
		cars CAR(platNum);
		if (code == 'A') { //using the code, call arrival or departure
			parm.arrival(CAR);
		}
		else if (code == 'D') {
			parm.departure(CAR);
		}
	}	
}
