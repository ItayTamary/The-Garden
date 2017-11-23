/*************************************
 ** File:    Flower.cpp
 ** Project: The Garden
 ** Author:  Itay Tamary
 ** Date:    4/25/2017
 ** E-mail: itay.tamary@gmail.com
 **
 ** This file contains the code to manage the Flowers of the garden.
 ** This code can flower, kill, grow, and disease the flower, and
 ** outputs the information to the garden.
 **
 **************************************/

#include "Flower.h"
using namespace std;

// Flower
// Constructs the newly added flower (not flowering)
Flower::Flower() {
  m_isFlowering = false;
}

// Flower (numPetals, color)
// Overloaded constructor that creates a flower with a color and petals
Flower::Flower(int numPetals, string color) {
  m_numPetals = numPetals;
  m_color = color;
}

// die
// Kills off the flowers and removes all the petals from the flower
void Flower::die() {
  SetIsAlive(false);
  m_numPetals = 0;
}

// tick
// Simulates a month in the flowers life, grows, diseases and flowers
void Flower::tick() {
  SetIsDiseased(false);
  m_isFlowering = false;
  int randomDisease = rand() % 5;
  if (randomDisease == 0) {
    SetIsDiseased(true);
  }
  if (!GetIsDiseased()) {
    if (GetSize() > 2) { //flowering
      m_isFlowering = true;
    }
    if (GetSize() == 5) {
      die();
    }
    int newSize = GetSize() + 1;
    SetSize(newSize);
  }
}

// operator<<
// outputs the flowers information to the garden
ostream& Flower::operator<<(ostream& os) {
  int intSize = GetSize();
  string stringSize;
  if (intSize < 1) { //if m_size is 0 (diseased in the first month)
    intSize = 1;
  }
  if (intSize > 3) {
    intSize = 3;
  }
  switch (intSize) {
  case 1:
    stringSize = "Seedling";
    break;
  case 2:
    stringSize = "Medium-Sized";
    break;
  case 3:
    stringSize = "Fully Mature";
    break;
  }	
  if (m_isFlowering && GetSize() == 5) { //drops its petals
    cout << "The flower drops its petals." << endl;
  }
  if (GetSize() == 6) {
    cout << "The flower dies." << endl;
  }
  if (!GetIsAlive()) { //if flower is dead only returns this
    os << "Flower(Dead)";
  }
  if (GetIsAlive()) {
    string isFlowering = "Not Flowering";
    if (m_isFlowering) {
      isFlowering = "Flowering";
    }
    string stringDiseased = "Not Diseased";
    if (GetIsDiseased()) {
      stringDiseased = "Diseased";
    }
    os << "Flower (" << stringSize << ": Alive : " << isFlowering << " : " << stringDiseased << ")";
  }
  return os;
}
