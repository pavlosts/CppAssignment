//still no headers


Car::Car(int dest, int pos = -1, bool r=false): destination(dest){
    position = pos;
    r = ready;
    cout << "Car created!" << endl;
}

Car::~Car(){
    cout << "Car destructed" << endl;
}
