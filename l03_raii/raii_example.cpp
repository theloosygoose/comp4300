
//
//
// comp4300/l03_raii
// raii_example.cpp
//
// Written by Gusti Rama Henry on 10/26/2024
// Copyright (c) 2024 Gusti Rama Henry. All Rights Reserved.
//
//

#include <iostream>

void ptr_print(int &i)
{
  // Shows the address, value, and size of the vars
  std::cout << &i << " " << sizeof(i) << " " << i << '\n';
}

class IntArray
{

  size_t m_size;
  // This pointer points to the first value of the array in memory
  int *m_arr;

public:
  // Constructor aquires the resource
  // Constructor takes arg of size and makes a new int array based on size
  IntArray(size_t size) : m_size(size), m_arr(new int[size])
  {
    std::cout << "Array Contructor\n";
  }

  // Destructor (frees memory)
  ~IntArray()
  {
    delete[] m_arr;
    std::cout << "Array Destructor\n";
  }

  // const because we do not modify the class
  int get(size_t index) const { return m_arr[index]; }

  // sets the value of a an index
  void set(size_t index, int val) { m_arr[index] = val; }

  void print() const
  {
    for (size_t i = 0; i < m_size; i++)
    {
      std::cout << i << " :: " << m_arr[i] << "\n";
    }
  }
};

int main()
{
  IntArray myArray(10);

  myArray.set(4, 7);
  myArray.set(2, 143);

  myArray.print();

  return 0;
}
