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
	for(int i = 0; i < 5; i++){
		delete personToll[i];
		delete eToll[i];
	}
	cout << "Entrance destroyed." << endl;
}

Car* Entrance::removeCar_toll(int spots_left, Toll& toll, int max_cars){
    if(spots_left > 0 && get_carsPassed()< max_cars){ //if there are spots and we havent reached max
                spots_left--;
				get_carsPassed()++;
				return toll.removeCar();
			}else{
				return NULL;
			}
}

/*μου φαινεται πιο λογικο να βγαινει απο την entrance και να μπαινει στο seg ενα αμαξι τη φορα,
ωστε να γλιτωσουμε το array, αλλα αμα το θελει ετσι, περι ορεξεως....*/

Entrance::operate(int max){
	for(int i = 0; i < 5; i++){
            personToll[i].set_carsPassed(); //set cars passed from toll to 0;
            eToll[i].set_carsPassed();
    	}
	int emptySpotsLeft = max_Spots;		//Empty spots left in the segment
	car* carP, carE;
	do{
	//Remove cars from Tolls
	for(int i = 0; i < 5; i++){ //remove one car from every toll
			carP = removeCar_toll(emptySpotsLeft, personToll[i], K);
			carE = removeCar_toll(emptySpotsLeft, eToll[i], 2*K);
			if(i==4){//if the last tolls
                		if(carE==NULL && carP==NULL) break; //both fail, break(=all tolls have reached max)
			}
			//!!!!!βαζουμε τα carE + carP στο entrance queue....!!!!!
		}
	}while(emptySpotsLeft > 0 )

	//Add cars to Tolls
	for(int i = 0; i < 5; i++){
		personToll[i].addCars();
		eToll[i].addCars();
	}
}
