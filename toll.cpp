#include <iostream>

#include "main.h"

using namespace std;

Toll::Toll(int segID):curSeg(segID){
	carsInQueue = rand() % 50;										//Number of new cars entering
	for(int i = 0; i < carsInQueue; i++){
		int dest = rand() % (NSegs - segID + 1) + segID;		//Calculates a random number in current_segment < destination <= NSegs
		carQueuePtr[i] = new Car(dest);						//Adds a new car in queue
	}
	for(int i = carsInQueue; i < 50; i++){
		carQueuePtr[i] = NULL;											//Initilizes the rest of the queue
	}
}

Toll::~Toll(){
	for(int i = 0; i < carsInQueue; i++){
       		delete carQueuePtr[i];		//Deletes cars in queue
	}
	cout << "Toll destructed." << endl;
}

void Toll::addCars( void ){
	cout<< "This toll queue had " << carsInQueue << " cars." << endl;
	if(carsInQueue < 100){
		int newCars = rand() % (100 - carsInQueue);						//Number of new cars entering in carsInQueue < newCars < 50
		for(int i = carsInQueue; i < carsInQueue + newCars; i++){
			int destination = rand() % (NSegs - curSeg + 1) + curSeg;		//Calculates a random number in current_segment < destination <= NSegs
			carQueuePtr[i] = new Car(destination);						//Adds a new car in queue
		}
	}
	cout<< "It now has " << carsInQueue << " cars." <<endl;
}


Car* Toll::removeCar( void ){
	Car* removed_car = carQueuePtr[carsInQueue - 1]; //points to removed car
	carQueuePtr[carsInQueue - 1] = NULL;			//pointer in carqueue set to null
	carsInQueue--;
	return removed_car;
}
