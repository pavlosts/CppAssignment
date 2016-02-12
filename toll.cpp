#include <iostream>

#include "main.h"

using namespace std;

Toll::Toll(int segID):
curSeg(segID){
	carsInQueue = rand() % 50;										//Number of new cars entering
	for(int i = 0; i < carsInQueue; i++){
		int destination = rand() % (NSegs - segID + 1) + segID		//Calculates a random number in current_segment < destination <= NSegs
		carQueue[i] = {destination, -1, false};						//Adds a new car in queue
	}
	for(int i = carsInQueue; i < 50; i++){
		carQueue[i] = NULL;											//Initilizes the rest of the queue
	}
}

Toll::~Toll(){
	cout << "Toll destructed." << endl;
}

Toll::addCars( void ){
	int newCars = rand() % (50 - carsInQueue);						//Number of new cars entering in carsInQueue < newCars < 50
	for(int i = carsInQueue; i < carsInQueue + newCars; i++){
		int destination = rand() % (NSegs - segID + 1) + segID		//Calculates a random number in current_segment < destination <= NSegs
		carQueue[i] = {destination, -1, false}; 					//Adds a new car in queue
	}
}

/*Δεν είμαι σίγουρος αν είναι σωστή.
	1) Δεν ξέρω αν ο τρόπος με το NULL είναι σωστός.
	2) Αφαιρεί το τελευταίο αυτοκίνητο από την ουρα. Θεωρητικά
		δεν είναι σωστό αλλά δεν νομίζω οτι μας ενοχλεί σε κάτι*/
Toll::removeCar( void ){
	carQueue[carsInQueue] = NULL;									//Removes the last car in queue
	carsInQueue--;
}