// A dynamic array with fixed size

#ifndef VECTOR_H
#define VECTOR_H

class Vector {
private:
   //Current capacity of the Vector
   int capacity;
   //Number of elements stored in the Vector object
   int n_elements;
   //Actual data stored in the Vector
   int* data;
public:
   //Constructor
   // args: capacity of the Vector
   Vector(int capacity);
   //Destructor
   ~Vector();
   //Returns size of the Vector object
   int getSize();
   //Returns element at the given index
   int get(int index);
   //Adds the given element to end of the array
   bool add(int element);
   //Places the given element at the given index. The index must be less than
   //the current size of the Vector object
   bool add(int element, int index);
};

#endif
