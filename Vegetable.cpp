/*************************************
 ** File:    Vegetable.cpp
 ** Project: CMSC 202 Project 4, Spring 2017
 ** Author:  Itay Tamary
 ** Date:    4/25/2017
 ** Section: 22
 ** E-mail: itay1@umbc.edu
 **
 ** This file contains the code to manage the Vegetables of the garden.
 ** This code can harvest, kill, grow, and disease the vegetable, and
 ** outputs the information to the garden.
 **
 **************************************/

#include "Vegetable.h"
#include <iostream>
using namespace std;

// Vegetable
// Constructs a newly created vegetable plant to be put in the garden
Vegetable::Vegetable() {
}

// Vegetable (string color)
// Overloadeded constructor the would construct if given a vegetable color
Vegetable::Vegetable(string color) {
  m_color = color; 
}

// die
// Kills the vegetable in the garden
void Vegetable::die() {
  SetIsAlive(false);
}

// harvest
// harvests the vegetable when it reaches a certain size and calls die()
void Vegetable::harvest() {
  die();
}

// tick
// Simulates a month of the Vegetable's life, diseases & grows the vegetable
void Vegetable::tick() {
  SetIsDiseased(false); //every month vegetable is healthy
  int randomDisease = rand() % 5; //generates either: 0, 1, 2 , 3 
  if (randomDisease == 0) { 
    SetIsDiseased(true);
  }
  if (GetSize() == 6) {
    harvest();
  }
  if (GetIsDiseased() == false || GetSize() > 4) { //once it is harvested
    int newSize = GetSize() + 1;                   //it keeps on "growing"
    SetSize(newSize);
  }	
}

// operator<<
// outputs the information of the vegetable to the garden	
ostream& Vegetable::operator<<(ostream& os) {
  string stringHarvest = "Not Harvestable";
  if (GetSize() == 5) {
    stringHarvest = "Harvestable"; 
  }
  string stringDiseased = "Not Diseased";
  if (GetIsDiseased() == true) {
    stringDiseased = "Diseased";
  }
  if (GetSize() < 6) {	//Just following the sample output
    os << "Vegetable (Alive : " << stringHarvest << " : " << stringDiseased << ")";
  }
  if (GetSize() == 6) {
    os << "The vegetable has been harvested." << "\nVegetable: Harvested";
  }
  if (GetSize() > 6) {
    os << "Vegetable: Harvested";
  }
  return os;
}	
