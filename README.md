# The-Garden
Simulating a garden with different plants (flowers, vegetables, trees) in monthly cycles. Simulation includes, flowering, maturing, harvesting, and death.

April 2017

Grade: A+ 100% (80/80)

To run:
  
  Compile using makefile: "make"
  
  Executing: "./gardner"
  
  
Rules:

Application that can simulate a garden complete with flowers, vegetables, and fruit trees. Each of these have a common parent – plant. 
Emphasizing inheritance, polymorphism, and overloaded operators. 

Plant (Parent):

•	The plant is an abstract class that is a common parent class to Vegetable, Flower, and Trees. 

•	Plants have getters and setters for each private member variable.

•	Plants also have pure virtual functions for tick, die, and the overloaded operator.

Vegetables (Child of Plant):

•	Vegetables are harvested when they have a size of 5

•	Vegetables are “seedlings” until size 3, then “medium sized” @4, then “fully mature” @5

•	Vegetables grow every tick that they aren't diseased

•	Vegetables have a 20% chance of being diseased each month

•	Vegetables are "un" diseased at the beginning of each month

Flowers (Child of Plant):

•	Flowers will start very small and eventually grow up so that they can flower.

•	If a flower is not diseased (20% of being diseased each month) then they:

  o	Will grow every month until size 3

  o	At size 3 they will check to see if they have petals – if they have petals and they are size 3, they will flower

  o	If they are flowering, the next month they will drop their petals.
  
  o	The month after they drop their petals, they will die.

• If a flower is diseased, they will not grow. At the beginning of each month, they will not be diseased (although they can be diseased again that month)
  
  •	Size 1 = Seedling
  
  •	Size 2 = Medium-sized
  
  •	Size 3 = Fully Mature

Trees (Child of Plant):

•	These are fruit trees and they will produce fruit once they become mature.

•	Trees are considered “Seedling” until month 12

•	Trees are considered “Sapling” until month 24

•	Trees are considered “Pole” until month 36

•	Trees are considered “Mature” after 36.

•	Once a tree is mature, a single dynamically allocated “Fruit” object is added to the Tree m_fruit vector (don’t forget to write a destructor!)

•	A tree has a 20% of being diseased each month. If a tree is diseased, it does not die. It just does not grow or fruit. The next month it is no longer diseased (although it can become diseased again, that month!)

Fruit (Not a Child):

•	Only has a getter for the single member function – color

•	Fruit does not do anything else except grow on trees

Garden:

•	At its core, a garden is just a container (vector) that holds plants (pointers)

•	The garden can do two things:

o	AddPlants (takes in type of plant and the quantity)

o	Tick (which fires the tick function for each object in the garden and manages which month it is)

•	As each of the plants is dynamically allocated, don’t forget to write a destructor when you are finished with the garden.






