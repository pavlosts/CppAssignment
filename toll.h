#ifndef TOLL_H
#define TOLL_H

#include <iostream>
#include <string>

class Toll{
private:
	int carsInQueue;			//Number of cars waiting
	Car* carQueuePtr[100];			//Array of pointers to cars
	int curSeg;
	int carsPassed;             //Counts the number of cars passed from toll
public:
	Toll( int segID );			//segNum = current segment's ID
	~Toll();
	void addCars( void );		//Adds random number of cars in queue
	Car* removeCar( void );		//Removes a car from queue
	void set_carsPassed(int cars =0){ carsPassed = cars;};
	int get_carsPassed(){ return carsPassed;};
}

#endif
