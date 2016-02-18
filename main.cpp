#include <iostream>
#include <cstdlib>
#include <ctime>

#include "main.h"

using namespace std;

int main(int argc, char* argv[]){
	if(argc < 4){
		cout << "Λίγα ορίσματα..." << endl;
		return 1;
	}else{
		srand( time( NULL ) );

		int N = argv[1];
		int NSegs = argv[2];
		int K = argv[3];
		int Percent = argv[4];

		Highway hw(NSegs, K, P);

		for(int i = 0; i < N; i++){
			hw.operate();
		}
	}

	return 0;
}