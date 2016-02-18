#ifndef TOLL_H
#define TOLL_H

#include <iostream>
#include <string>

class Car{
private:
    const int destination; 				//Segment to reach
	int position;					//Current segment. Default = -1 (before entering highway)
	bool ready;						//True if ready to leave segment. Default = False
public:
    Car(int, int, bool);
    ~Car();
    void setready(){ ready = true; };    //sets the car to ready
    bool is_ready(){return ready; };
    bool destination_reached(){return (position==destination)};
};

#endif