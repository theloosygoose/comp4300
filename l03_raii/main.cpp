//
//
// comp4300/l03_raii
// main.cpp
//
// Written by Gusti Rama Henry on 10/26/2024
// Copyright (c) 2024 Gusti Rama Henry. All Rights Reserved.
//
//

/*

-- RAII --
  Class that is responsive for the managing the lifetime of an object

  this is a dynamically allocated class
  - the data is stored on the Heap


-- C++ Smart Pointers

Smart Pointers are regular pointers wrapped in a Class

  std::shared_ptr<T>
  ---
    works for most cases and is *good enough*

    When it goes out of scope it frees the memory that the pointer points to
    from the heap

    Handles RAII for a given pointer / type 

  -- Formal Definition --
    "Reference Counted Pointer"
    
    - *Internal Counter* set to 1 in constructor
    - Everytime the shared_ptr is copied, the counter *increases* by 1
    - Everytime a shared_ptr destructs, the counter is decrased by 1
    - When count reaches 0, the resource is deallocated

*/

// -- RAII CLASS EXAMPLE -- //

class IntArray
{
  // Private Variable holds a pointer to the data
  int *array;

public:
  // the constructor aquires the resource
  IntArray(size_t size) { array = new int[size]; }
  // destructor frees the resource
  // the '~' frees the recouse
  ~IntArray() { delete[] array; }
  int &operator[](size_t i) { return array[i]; }
};

int main()
{

  IntArray arr(10); // memory allocated

  arr[5] = 21;

  return 0;
} // arr destructs, mem deallocated
