// A dynamic array that resizes as new elements are added

#include "vector2.h"

// -- Initialize a vector with capacity of 10 elements ---
//   args: capacity of the Vector

Vector::Vector()
{
        capacity   = 10;
        data       = new int[capacity];
        n_elements = 0;
}

// -- Destroys a vector ---

Vector::~Vector()
{
        delete [] data;
}

// -- Returns size of the Vector ---
//   rets: number of elements in the Vector

int Vector::getSize()
{
        return n_elements;
}

// -- Returns capacity of the Vector ---
//   rets: maximum number of elements that can be stored in the Vector

int Vector::getCapacity()
{
        return capacity;
}

// -- Returns element at the given index ---
//   args: index of the element
//   rets: element at the given index

int Vector::get(int index)
{
        return data[index];
}

// -- Adds the given element to end of the array ---
//   args: element to be added
//   rets: true if element is successfully added, false otherwise

bool Vector::add(int element)
{
}

// -- Places the given element at the given index ---
//   args: element and index
//   rets: true if element is successfully added, false otherwise

bool Vector::add(int element, int index)
{
}

// -- Checks if the vector can hold the given number of elements ---
//If the new capacity is greater than current capacity, capacity
//of the Vector should be doubled
//   args: new capacity of the Vector
//   rets: true if the Vector can hold that many elements, false otherwise

bool Vector::ensureCapacity(int newCapacity)
{
}

// -- Increases capacity of the Vector to the given value ---
//   args: new capacity of the Vector
//   rets: true if capacity is increased, false otherwise

bool Vector::increaseCapacity(int newCapacity)
{
}
