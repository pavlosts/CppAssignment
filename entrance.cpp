#include <iostream>

#include "main.h"

using namespace std;

Entrance::Entrance(int k, int id):
K(k), segID(id){
	for(int i = 0; i < 5; i++){
		personToll = new Toll(segID);
		eToll = new Toll(segID);
	}
}

Entrance::~Entrance( void ){
	cout << "Entrance destroyed." << endl;
}
/*Έχω μια ιδέα για βελτίωση της κατανομής αλλά θα το δω
όταν τελειώσουμε τα υπόλοιπα. Επίσης επειδή έχω κάνει κάτι
περίεργα, αν δεν καταλάβεις πες μου να σου εξηγήσω.*/
Entrance::operate(int max){
	int carsPassed;								//Counts the number of cars passed from each toll
	int emptySpotsLeft = max;					//Empty spots left in the segment
	bool personMax, eMax;

	//Remove cars from personTolls
	for(int i = 0; i < 5; i++){
		carsPassed = 0;
		for(int j = 0; j < K; j++){
			if(emptySpotsLeft > 0){
				personToll[i].removeCar();
				emptySpotsLeft--;
				carsPassed++;
			}else{
				break;
			}
		}
		if(carsPassed == K){
			personMax = true;
		}else{
			personMax = false;
		}
	}
	//Remove cars from eTolls
	for(int i = 0; i < 5; i++){
		carsPassed = 0;
		for(int j = 0; j < 5; j++){
			if(emptySpotsLeft > 0){
				eToll[i].removeCar();
				emptySpotsLeft--;
				carsPassed++;
			}else{
				break;
			}
		}
		if(carsPassed == 2*K){
			eMax = true;
		}else{
			eMax = false;
		}
	}

	if(eMax == true && personMax == true){
		K++;
	}else{
		K--;
	}

	//Add cars to personTolls
	for(int i = 0; i < 5; i++){
		personToll[i].addCars();
	}

	//Add cars to eTolls
	for(int i = 0; i < 5; i++){
		eToll[i].addCars();
	}
}