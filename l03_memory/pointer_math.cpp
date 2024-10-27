//
//
// comp4300/l03_memory/
// pointer_math.cpp
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

  // -- Pointer -- //

  int x = 10;
  int y = 20;
  int *px = &x;
  int *py = &y;

  // Changes x to 11
  //*px = 11;

  // Changes x to 12
  //k*(&x) = 12;

  // Changes y to 21
  //*py = 21;

  // Changes the memory address of py minus '1' (4 bytes)
  // which is the memory address of x so x should = '22'
  *(py - 1) = 22;

  ptr_print(x);
  ptr_print(y);

  return 0;
}
