//
//
// comp4300/l02
// main.cpp
//
// Written by Gusti Rama Henry on 10/25/2024
// Copyright (c) 2024 Gusti Rama Henry. All Rights Reserved.
//
//

#include <fstream>
#include <iostream>
#include <vector>

class Student
{

  std::string m_first = "First";
  std::string m_last = "Last";
  int m_id = 0;
  float m_avg = 0;

public:
  Student() {}

  Student(std::string first, std::string last, int id, float avg)

      : m_first(first), m_last(last), m_id(id), m_avg(avg)
  {
  }

  // Getters
  int getAverage() const { return m_avg; }

  int getID() const { return m_id; }

  std::string getFirst() const { return m_first; }

  std::string getLast() const { return m_last; }

  // the const keyword basically says that this function will not change the
  // function
  void print() const
  {
    std::cout << m_first << " " << m_last << " :: ";
    std::cout << m_id << " " << m_avg << "\n\n";
  }

  // becuase this changes something within the class there is no 'const' keyword
  // within the function
  int changeName(std::string new_name)
  {
    m_first = new_name;

    return 0;
  }
};

class Course
{
  std::string m_name = "Course";
  std::vector<Student> m_students;

public:
  Course() {}

  Course(const std::string &name) : m_name(name) {}

  void addStudent(const Student &s) { m_students.push_back(s); }

  //
  // the 'const' at the beginning means that whatever we are returning cannot be
  // changed
  //
  // the 'const' at the end of the function declaration means that the function
  // will not change the class
  //
  const std::vector<Student> &getStudents() const { return m_students; }

  void loadFromFile(const std::string &filename)
  {
    std::ifstream fin(filename);
    std::string first, last;
    int id;
    float avg;

    // Here fin sends the next token to temp with the >> pipe
    // token :: anything that is the '\n' or whitespace
    while (fin >> first)
    {
      fin >> last >> id >> avg;

      addStudent(Student(first, last, id, avg));
    }
  }

  void print() const
  {
    std::cout << m_name << '\n';

    for (const auto &s : m_students)
    {
      s.print();
    }
  }
};

int main(int argc, char *argv[])
{
  // Working with classes in c++
  Student s1;
  Student s2("Dave", "Henry", 1, 3.14);
  Student s3("Gusti", "Henry", 2, 4.0);

  const Student s4("Jane", "Doe", 3, 5.0);

  // so here because s4 is a const
  // this variable is still able to call this function
  s4.print();

  s3.print();
  s2.print();
  s2.changeName("changedDaved");
  s2.print();

  // Course Class Stuff

  Course comp4300("COMP 4300");
  comp4300.addStudent(s1);
  comp4300.addStudent(s2);
  comp4300.addStudent(s3);

  comp4300.print();

  comp4300.loadFromFile("students.txt");
  comp4300.print();

  // Basic Vector Stuff
  std::vector<int> vec;
  vec.push_back(42);
  vec.push_back(10);
  vec.push_back(20);

  for (size_t i = 0; i < vec.size(); i++)
  {
    std::cout << vec[i] << '\n';
  }

  for (int a : vec)
  {
    std::cout << a << "\n";
  }

  return 0;
}
