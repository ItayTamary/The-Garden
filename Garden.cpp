/*************************************
 ** File:    Garden.cpp
 ** Project: The Garden
 ** Author:  Itay Tamary
 ** Date:    4/25/2017
 ** E-mail: itay.tamary@gmail.com
 **
 ** This file contains the code to manage the garden that holds all the
 ** plants. The garden simulates the time, manages the month, adds new
 ** plants to the garden and clears the garden.
 **
 **
 **************************************/

#include "Garden.h"
#include <time.h>
#include <iostream> 
using namespace std;

// Garden
// Constructs the garden, sets the garden and time to zero and seeds 
// the random number generator
Garden::Garden() {
  m_gardenSize = 0;
  m_month = 0;
  srand(time(NULL));
}

// ~Garden
// Deconstructs the garden and deletes all the dynamically allocated
// plants objects from the garden vector
Garden::~Garden() {
  for (int i = 0; i < getSize(); i++) {
    delete m_garden[i];
    m_garden[i] = NULL;
  }	
}

// addPlant
// This function creates new plant objects and adds them to the garden
void Garden::addPlant(int type, int quantity) {
  for (int i = 0; i < quantity; i++) {
    switch (type) {
    case 1: {
			Flower* flowerObj = new Flower;
			m_garden.push_back(flowerObj);
			break;
			}
    case 2: {
			Vegetable* vegetableObj = new Vegetable;
			m_garden.push_back(vegetableObj);
			break;
			}
    case 3: {
			Tree* treeObj = new Tree;
			m_garden.push_back(treeObj);
			break; 
			}
    }
  }
}

// tick(int)
// Calls tick() for a specified amount of months
void Garden::tick(int time) { 
  for (int i = 0; i < time; i++) {
    tick();
  }
}

// tick()
// Calls tick of each individual plant in the garden, simulates a 
// a month in each plant's life, and outputs the details of the plant
// for the simulated month
void Garden::tick() {
  cout << "MONTH: " << getMonths() + 1 << endl;
  for (int i = 0; i < getSize(); i++) {
    m_garden[i]->tick();
    cout << i+1 << ": ";
    *m_garden[i] << cout << endl;
  }
  m_month = getMonths()+ 1;
}

// getSize()
// Returns the size of the garden vector
int Garden::getSize() {
  m_gardenSize = m_garden.size();
  return m_gardenSize;
}

// getMonths
// Returns the number of months that have been simulated thus far
int Garden::getMonths() {
  return m_month;
}





