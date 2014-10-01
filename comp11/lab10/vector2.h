// A dynamic array that resizes as new elements are added

#ifndef VECTOR_H
#define VECTOR_H

class Vector {
private:
   //Current capacity of the Vector
   int capacity;
   //Number of elements stored in the Vector
   int n_elements;
   //Actual data stored in the Vector
   int* data;
public:
   //Constructor
   //Initializes Vector with capacity equal to 10
   Vector();
   //Destructor
   ~Vector();
   //Returns size of the Vector
   int getSize();
   //Returns capacity of the Vector
   int getCapacity();
   //Returns element at the given index
   int get(int index);
   //Adds the given element to end of the array
   bool add(int element);
   //Places the given element at the given index. The index must be less than
   //the current size of the Vector
   bool add(int element, int index);
   //Checks if the vector can hold the given number of elements. If the new
   //capacity is greater than current capacity, capacity of the Vector
   //should be doubled
   bool ensureCapacity(int newCapacity);
   //Increases capacity of the Vector to the given value
   bool increaseCapacity(int newCapacity);
};

#endif
