#ifndef ENTRANCE_H
#define ENTRANCE_H

#include <iostream>
#include <string>

class Entrance{
private:
	int segID;				//Segment's ID
	int K;
	Toll personToll[5];		//Tolls with personel
	Toll eToll[5];			//E-Tolls
public:
	Entrance(int k, int id);
	~Entrance( void );
	void operate(int max);
}

#endif