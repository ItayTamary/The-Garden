/*************************************
 ** File:    driver.cpp
 ** Project: CMSC 202 Project 5, Spring 2017
 ** Author:  Itay Tamary
 ** Date:    5/11/2017
 ** Section: 22
 ** E-mail: itay1@umbc.edu
 **
 ** This file runs or "drives" the entire program. It prompts the menus,
 ** validates the inputs creates the garden, simulates the time,
 ** and calls the program functions
 **
 **************************************/

#include "driver.h"
using namespace std;

// menu
// Prints out available functions of the program
void menu() {
  cout << "1. Plant Single Item" << endl;
  cout << "2. Plant Many of the Same Item" << endl;
  cout << "3. Plant a Full Garden" << endl;
  cout << "4. Exit" << endl;
  cout << "Enter 1-4:" << endl;	
}

// manageMenu
// Calls the menu(), validates user input, and runs the functions
void manageMenu(Garden& garden) {
  cout << "Welcome to the Garden" << endl;
  int choice = 0;
  while (choice != 4) {
    while (choice < 1 || choice > 4) {
      menu();
      cin >> choice;
    }
    switch(choice) {
    case 1:
      singleGarden(garden);
      break;
    case 2:
      singleGarden(garden, 2);
      break;
    case 3:
      manyGarden(garden);
      break;
    case 4:
      break;
    }
    choice = 4; //exits out of the while loop
  }
}

// singleGarden
// Adds only one type of plants to the garden with a desired quantity
void singleGarden(Garden& garden, int quantity) {
  if (quantity < 2) {
    int choice = 0;
    while (choice < 1 || choice > 3) {
      plantMenu();
      cin >> choice;
    }
    garden.addPlant(choice, quantity);
    simulateTime(garden); 
  }
  if (quantity > 1) {
    int choice = 0;
    while (choice < 1 || choice > 3) {
      plantMenu();
      cin >> choice;
    }
    cout << "How many would you like to plant?" << endl;
    cin >> quantity;
    garden.addPlant(choice, quantity);
    simulateTime(garden);
  }  
}

// manyGarden
// Can add all three types of plants to the garden with a desired quantity
void manyGarden(Garden& garden) {
  int numFlowers, numVegetables, numTrees;
  cout << "How many flowers would you like to plant?" << endl;
  cin >> numFlowers;
  garden.addPlant(1, numFlowers);
  cout << "How many vegetables would you like to plant?" << endl;
  cin >> numVegetables;
  garden.addPlant(2, numVegetables);
  cout << "How many trees would you like to plant?" << endl;
  cin >> numTrees;
  garden.addPlant(3, numTrees);
  simulateTime(garden);
}

// plantMenu
// Prompts the user with the types of available plants to plant
void plantMenu() {
  cout << "What would you like to plant?" << endl;
  cout << "1. Flower" << endl;
  cout << "2. Vegetable" << endl;
  cout << "3. Tree" << endl;
  cout << "Please enter 1-3:" << endl;
}

// simulateTime
// Prompts user with desired amount of months to suimulates and calls
// tick accordingly
void simulateTime(Garden& garden) {
  cout << "How many months would you like to simulate?:" << endl;
  int months;
  cin >> months;
  garden.tick(months);
}
		
int main () {
  Garden gardenObj;
  cout << "Welcome to the Garden\nCoded by Itay Tamary\n" << endl;
  manageMenu(gardenObj);
  return 0;
}
			
			
			
		
