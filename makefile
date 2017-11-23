CXX = g++
CXXFLAGS = -Wall

gardner: Garden.o Plant.o Vegetable.o Flower.o Tree.o Fruit.o driver.o
	$(CXX) $(CXXFLAGS) Garden.o Plant.o Vegetable.o Flower.o Tree.o Fruit.o driver.o -o gardner


Garden.o: Garden.cpp Garden.h Plant.cpp Plant.h Vegetable.cpp Vegetable.h Flower.cpp Flower.h Tree.cpp Tree.o Fruit.cpp Fruit.o
	$(CXX) $(CXXFLAGS) -c Garden.cpp

Plant.o: Plant.cpp Plant.h
	$(CXX) $(CXXFLAGS) -c Plant.cpp

Vegetable.o: Vegetable.cpp Vegetable.h
	$(CXX) $(CXXFLAGS) -c Vegetable.cpp

Flower.o: Flower.cpp Flower.h
	$(CXX) $(CXXFLAGS) -c Flower.cpp

Tree.o: Tree.cpp Tree.h
	$(CXX) $(CXXFLAGS) -c Tree.cpp

Fruit.o: Fruit.cpp Fruit.h
	$(CXX) $(CXXFLAGS) -c Fruit.cpp	

driver.o: driver.cpp driver.h
	$(CXX) $(CXXFLAGS) -c driver.cpp