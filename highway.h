#ifndef HIGHWAY_H
#define HIGHWAY_H

#include <iostream>
#include <string>

class Highway{
private:
	int percent;
	int numberOfSegs;
	Segment *segments;
	int cars;
public:
	Highway(int NSegs, int K, int P);
	~Highway();
	void operate();	
	void run_simulation(int);
};

#endif
