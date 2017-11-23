/*************************************
 ** File:    Tree.cpp
 ** Project: The Garden
 ** Author:  Itay Tamary
 ** Date:    4/25/2017
 ** E-mail: itay.tamary@gmail.com
 **
 ** This file contains the code to manage the Trees of the garden.
 ** This code can harvest fruit, kill, grow, and disease the tree, and
 ** outputs the information to the garden.
 **
 **************************************/

#include "Tree.h"
using namespace std;

// Tree
// Constructs the tree (a tree that has no fruit)
Tree::Tree() {
  m_fruit.resize(0);
}

// ~Tree
// Deconstructor deletes and clears dynamically allocated memory
// by calling ClearFruit()
Tree::~Tree() {
  ClearFruit();
}

// die
// Kills the tree
void Tree::die() {
  SetIsAlive(false);
}

// ClearFruit
// Deletes all dynamically allocated memory of fruit on the tree
void Tree::ClearFruit() {
  for (unsigned int i = 0; i < m_fruit.size(); i++) {
    delete m_fruit[i]; 
    m_fruit[i] = NULL; //sets to NULL
  }
}

// tick
// Simulates a month in the life of the tree, grows and diseases the tree
void Tree::tick() { 
  SetIsDiseased(false);
  bool isFruiting;
  if (GetIsAlive()) {
    isFruiting = false;
  }
  if (GetSize() == 120) { //calls for death of tree
    SetIsAlive(false);
  }
  int randomDisease = rand() % 5; //randomly generates disease
  if (randomDisease == 0) {
    SetIsDiseased(true); 
  }
  if (!GetIsDiseased() || GetSize() > 119) { 
    if (GetSize() > 36) {
      isFruiting = true;
      Fruit* objFruit = new Fruit(); //creates dynamically allocated fruit
      m_fruit.push_back(objFruit);
    }
    int newSize = GetSize() + 1;
    SetSize(newSize);
  }
}

// operator<<
// Outputs the information of the tree to the garden
ostream& Tree::operator<<(ostream& os) { 
  int tempSize = GetSize() - 1; //takes into account the offset of months
  if (tempSize < 12) {          
    tempSize = 1;
  }
  if (tempSize > 11 && tempSize < 24) {
    tempSize = 2;
  }
  if (tempSize > 23 && tempSize < 36) {
    tempSize = 3;
  }
  if (tempSize > 35) {
    tempSize = 4;
  }
  string stringStatus;
  switch (tempSize) {
  case 1:
    stringStatus = "Seedling";
    break;
  case 2:
    stringStatus = "Sapling";
    break;
  case 3:
    stringStatus = "Pole";
    break;
  case 4:
    stringStatus = "Mature";
    break;
  }
  string stringIsFruiting = "Not Fruiting";
  if (!GetIsDiseased()&& GetSize() > 37) {
    stringIsFruiting = "Fruiting";
  }
  string stringIsAlive = "Alive";
  if (!GetIsAlive()) {
    stringIsAlive = "Dead";
  }
  string stringIsDiseased = "Not Diseased";
  if (GetIsDiseased()) {
    stringIsDiseased = "Diseased";
  } 
  if (!GetIsAlive() && GetSize() == 121) { //when tree dies
    os << "The tree has died" << "\nTree (" << stringStatus << ": " << stringIsAlive << " : " << stringIsFruiting << " : " << stringIsDiseased << ")";
  }
  else if (GetSize() != 121) {
    os << "Tree (" << stringStatus << ": " << stringIsAlive << " : " << stringIsFruiting << " : " << stringIsDiseased << ")";
  }
  return os;
}


