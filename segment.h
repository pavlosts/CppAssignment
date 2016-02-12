#ifndef SEGMENT_H
#define SEGMENT_H

#include <iostream>
#include <string>

class Segment{
private:
	Entrance gate;
	int numberOfCars;
	Car carPtr;
	int capacity;
	Segment nextSeg;
	Segment PrevSeg;
public:
	Segment();
	~Segment();
	void enter();
	void exit();
	void pass();
	int getNoOfVehicles();
	void operate();
}

#endif