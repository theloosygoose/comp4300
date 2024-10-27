//
//
// comp4300/l02_memory
// main.cpp
//
// Written by Gusti Rama Henry on 10/26/2024
// Copyright (c) 2024 Gusti Rama Henry. All Rights Reserved.
//
//

#include <iostream>

// C++ Pointers
//
// Same as pointers in C
// A pointer stores a memory address
// Modifying the pointer variable modifies the address it 'points' to
// To modify the value of the data in memory that it points to

int main()
{

  int i = 6; // local int variable
  std::cout << "i has the value " << i << '\n';

  // All this says it that we will create a pointer to an 'int' type
  // the value is 'undefined' or what random bytes live at the memory address
  // doing this is bad practice and you should always define in line
  // for pointers
  int *p; // pointer to int

  // 'p' will be assigned the adress of 'i'
  p = &i; // & = 'address of'
  std::cout << "the pointer p = " << p << '\n';

  // the '*' says "get me to the data of the adress 'p'"
  // now i = 7
  *p = 7;

  std::cout << "i has the value " << i << '\n';

  //
  // C++ Arrays and Pointers //
  //

  // this states: give me the memory adress for the first value of this array
  // which is can contain 4 items
  // the items are stores on the heap BUT this memory address is stored
  // on the stack
  int *v_arr = new int[3];

  v_arr[0] = 5;
  v_arr[1] = 10;

  // this is basically adding '2' to the address of the memory on the heap
  // and make that spot in memory = 20
  // this is = to doing:
  // v_arr[2] = 20
  *(v_arr + 2) = 20;

  //
  // C++ References //
  //

  /*
    C++ References are basically 'safe pointers'
    instead of using *, use &

    the reason why they are called 'safe'
    is because they *MUST* point to *existing* data
    can never point to nothing

    use references over pointers most of the time
  */
  return 0;
}
