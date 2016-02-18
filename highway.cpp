#include <iostream>

#include "main.h"

using namespace std;

Highway::Highway(int NSegs, int K, int P):
numberOfSegs(NSegs),
percent(P){
	cars = 0;
	segments = new Segment[numberOfSegs];			//Dynamicly allocates an array of segs
	for(int i = 0; i < numberOfSegs; i++){
		segments[i] = new Segment(K,i);				//Initializes array
	}
	cout << "Αυτοκινητόδρομος σε λειτουργία" << endl;
}

Highway::~Highway(){
	for(int i = 0; i < numberOfSegs; i++){
		delete segments[i];
	}
	delete segments;
	cout << "Highway destroyed" << endl;			//poor highway :(
}

void Highway::operate(){
	cars = 0;
	for(int i = numberOfSegs - 1; i <= 0; i--){
		cars += segments[i].operate(percent);		//Sums the cars from each segment
	}
	cout << "Cars in highway: " << cars << endl;
}