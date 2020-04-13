#ifndef ARRAY_STACK_
#define ARRAY_STACK_


const int MAX_STACK = 10;

template<class ItemType>
class ArrayStack
{
private:
	ItemType items[MAX_STACK]; // Array of stack items
	int      top;              // Index to top of stack

public:
	ArrayStack(); // Default constructor
	bool isFull() const;
	bool isEmpty() const;
	bool push(const ItemType);
	bool pop();
	void displayItems();
	ItemType peek() const;
	bool contains(const ItemType&);
	ItemType getItem(int num) { return items[num]; }
	int getLen() { return top + 1; }
	int getTop() { return top; }
}; // end ArrayStack

#endif