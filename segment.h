#ifndef SEGMENT_H
#define SEGMENT_H

#include <iostream>
#include <string>

class Segment{
private:
	Entrance gate;
	int numberOfCars;
	Car* carPtr[500];
	int capacity;
	Segment nextSeg;
	Segment PrevSeg;
	int segId;
public:
	Segment(int k, int id);
	~Segment();
	void enter(Car &enteringCar);
	void exit();
	void pass();
	int getNoOfVehicles();
	void operate();
}

#endif
