#include <iostream>

#include "main.h"

using namespace std;

Segment::Segment(int k, int id, Segment &s):segID(id){
	gate = new Entrance(k, id);
	prevSeg = s;
	capacity = (rand() % 200) + 300;			// 0 + 300 <= capacity <= 200 + 300
	numberOfCars = rand() % capacity;
	for(int i = 0; i < numberOfCars; i++){
		int dest = rand() % (NSegs - segID + 1) + segID;
		carPtr[i] = new Car(dest);
	}
}

Segment::~Segment(){
	for(int i = 0; i < numberOfCars; i++){
		delete carPtr[i];
	}
}

void Segment::enter(Car &enteringCar){
	int numberOfNewCars;
	Car *newCars[500];				//An array for new cars
	gate.operate(newCars, capacity - numberOfCars);		//Gets the cars to enter
	for(int i = 0; i < capacity - numberOfCars; i++){	//Counts the new cars
		if(newCars != NULL){
			numberOfNewCars++;
		}else{
			break;
		}
	}
	for(int i = numberOfCars; i < numberOfCars + numberOfNewCars; i++){	//Adds the new cars
		carPtr[i] = newCars[i - numberOfNewCars];
	}
	for(int i = 0; i < numberOfNewCars; i++){					//Deletes the temp array
		delete newCars[i];
	}
}

void Segment::exit(){
	for(int i = numberOfCars - 1; i >= 0; i++ ){
		if(carPtr[i].ready == true && carPtr[i].destination == segID){
			delete carPtr[i];
		}
	}
}

void Segment::pass(){
	for(int i = numberOfCars - 1; i >= 0; i++){
		if(carPtr[i].ready == true && carPtr[i].destination > segID){
			nextSeg.enter(carPtr[i]);
		}
	}
}

int Segment::getNoOfVehicles(){
	return numberOfCars;
}

void Segment::operate(){

}
void Segment::pass(){

}

int Segment::getNoOfVehicles(){

}

void Segment::operate(){

}
