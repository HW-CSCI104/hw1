/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
int main(int argc, char* argv[])
{
  Node* n = new Node(3, nullptr);
  Node* temp = n;
  n->next = new Node(5, nullptr);
  n->next->next = new Node(4, nullptr);
  n->next->next->next = new Node(2, nullptr);
  Node* evens = nullptr;
  Node* odds = nullptr;
  split(n, odds, evens);
  std::cout << "\n";
  std::cout << odds->value<< " " << odds->next << " " << odds->next->value << std::endl;
  std::cout << evens->value<< " " << evens->next << " " << evens->next->value << std::endl;
  delete temp;
}
