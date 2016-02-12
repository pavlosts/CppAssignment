#ifndef TOLL_H
#define TOLL_H

#include <iostream>
#include <string>

class Toll{
private:
	int carsInQueue;			//Number of cars waiting
	Car carQueue[100];			//Array of cars
	int curSeg;
public:
	Toll( int segID );			//segNum = current segment's ID
	~Toll();
	void addCars( void );		//Adds random number of cars in queue
	void removeCar( void );		//Removes a car from queue
}

#endif