/*************************************
 ** File:    Plant.cpp
 ** Project: The Garden
 ** Author:  Itay Tamary
 ** Date:    4/25/2017
 ** E-mail: itay.tamary@gmail.com
 **
 ** This file contains the code to parent class Plant, that serves as the base constructor
 ** of all the subclass plants in the garden.
 ** 
 **
 **************************************/

#include "Plant.h"
using namespace std;

// Plant
// Construct the newly created plant, starts of at 0, not diseased, and alive
Plant::Plant() {
  m_size = 0;
  m_isDiseased = false;
  m_isAlive = true;	
}

// ~Plant
// Destructor (does nothing)
Plant::~Plant() {}

// GetIsDiseased
// Returns whether the plant is diseased or not
bool Plant::GetIsDiseased() {
  return m_isDiseased;
}

// GetIsAlive
// Returns whether the plant is alive or not
bool Plant::GetIsAlive() {
  return m_isAlive;
}

// GetSize
// Returns the size of the plant
int Plant::GetSize() {
  return m_size;
}

// SetSize
// Sets the size of the plant
void Plant::SetSize(int size) {
  m_size = size;	
}

// SetIsAlive
// Toggles the life of the plant, if it is dead or not
void Plant::SetIsAlive(bool isAlive) {
  m_isAlive = isAlive;	
}

// SetIsDiseased
// Toggles the disease of the plant
void Plant::SetIsDiseased(bool isDiseased) {
  m_isDiseased = isDiseased;
}

// die
// Kills the plant (does nothing)
void Plant::die() {} 

// tick
// Simulates a month in the life of the plant (does nothing)
void Plant::tick() {}








