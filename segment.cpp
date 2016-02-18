#include <iostream>

#include "main.h"

using namespace std;

Segment::Segment(int k, int id):segID(id){
	gate = new Entrance(k, id);
	prevSegPtr = NULL;
	nextSegPtr = NULL;
	capacity = (rand() % 200) + 300;			// 0 + 300 <= capacity <= 200 + 300
	numberOfCars = rand() % capacity;
	for(int i = 0; i < numberOfCars; i++){
		int dest = rand() % (NSegs - segID + 1) + segID;
		cars_in_seg[i] = new Car(dest, id);  //the current position of the car is the id of this segment
	}
	for(int i=numberOfCars; i<capacity; i++){ //the rest of the spots are empty
        cars_in_seg[i] = NULL;
	}
}


void Segment::Insert_seg_behind(Segment* s){
    prevSegPtr = s;
    s->nextSegPtr = this;
}

Segment::~Segment(){
	for(int i = 0; i < numberOfCars; i++){
		delete cars_in_seg[i];
	}
	delete gate;
	cout>> "Segment deleted!">>endl;
}

void Segment::enter(int empty_spots){
	int numberOfNewCars=0;
	Car* newCars[empty_spots];				//An array for new cars as big as the empty spots we have
	gate.operate(empty_spots, newCars[]);		//Gets the cars from tolls
	for(int i = (empty_spots-1); i >= 0; i--){	//Counts the new cars from BACK to front of array
		if(newCars != NULL){
			numberOfNewCars++;
			/*η επαναληψη σου δεν δουλευε, οποτε το εβαλα εδω*/
			cars_in_seg[numberOfCars] = newCars[i];  //add the new car in the segment
			numberOfCars++;         //number of cars is now greater
		}else{
			break;
		}
	}
	/*ΠΡΟΣΟΧΗ! Αν το κανουμε αυτο, σβηνουμε τα αυτοκινητα που χρειαζομαστε!!
	for(int i = 0; i < numberOfNewCars; i++){					//Deletes the temp array
		delete newCars[i];
	}*/
}

void Segment::exit(){
	for(int i = numberOfCars - 1; i >= 0; i-- ){
		if((cars_in_seg[i]->is_ready()) && (cars_in_seg[i]->destination_reached())){
			delete cars_in_seg[i];
			cout<< "A car has exited the highway" << endl;
			cars_in_seg[i] = NULL;
			numberOfCars--;
		}
	}
}

void Segment::pass(){
	for(int i = numberOfCars - 1; i >= 0; i++){
		if((cars_in_seg[i]->is_ready()) && !(cars_in_seg[i]->destination_reached())){
			 //car enters next segment
			/*nextSeg.enter(carPtr[i]); εκτος και αν κανεις override τη συναρτηση, η εντολη αυτη οδηγει στην καταστροφη :Ρ*/
		}
	}
}



void Segment::operate(){

}
void Segment::pass(){

}

int Segment::getNoOfVehicles(){

}

void Segment::operate(){

}
