//
//
// comp4300/l03_raii
// examples.cpp
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

int main()
{

  // Primitive Example
  int a = 10;
  int b = 20;

  ptr_print(a);
  ptr_print(b);

  //  -- Array Example -- //
  // the ` =  {}` gives default vaules to the array instead of whatever
  // is the the memory address

  // Stack Array
  int arr[10] = {};

  // Heap Array
  // Technically a memory leak since this is never freed

  int *harr = new int[10];

  for (size_t i = 0; i < 10; i++)
  {
    ptr_print(arr[i]);
  }

  for (size_t i = 0; i < 10; i++)
  {
    ptr_print(harr[i]);
  }


  return 0;
}
