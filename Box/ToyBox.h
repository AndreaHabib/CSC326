//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2016 __Pearson Education__. All rights reserved.

/** Listing C1-5.
 @file ToyBox.h */

#ifndef TOY_BOX_
#define TOY_BOX_
#include "PlainBox.h"

enum Color {BLACK, RED, BLUE, GREEN, YELLOW, WHITE};

template<class ItemType>
class ToyBox : public PlainBox<ItemType>
{
private:
   Color boxColor;
public:
   ToyBox();
   ToyBox(const Color& theColor);
   ToyBox(const ItemType& theItem, const Color& theColor);
   Color getColor() const;
}; // end ToyBox
#include "ToyBox.cpp"
#endif