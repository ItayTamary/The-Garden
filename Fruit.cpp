/*************************************
 ** File:    Fruit.cpp
 ** Project: The Garden
 ** Author:  Itay Tamary
 ** Date:    4/25/2017
 ** E-mail: itay.tamary@gmail.com
 **
 ** This file contains the code to construct a fruit growing on a tree
 **
 **
 **************************************/

#include "Fruit.h"
using namespace std;

// Fruit
// Constructs a fruit to be dynamically allocated to the tree with a color
Fruit::Fruit() {
  m_color = "Grey";
}

// GetColor
// Returns the color of the fruit on the tree
string Fruit::GetColor() {
  return m_color;
}
