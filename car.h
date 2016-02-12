//i havent divided mine to different files, so no includes for you haha


class Car{
private:
    const int destination; 				//Segment to reach
	int position;					//Current segment. Default = -1 (before entering highway)
	bool ready;						//True if ready to leave segment. Default = False
public:
    Car(int, int, bool);
    ~Car();
    void setready(){ ready = true; };    //sets the car to ready
};
