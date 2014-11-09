#include <cstdlib>
#include <iostream>

using namespace std;

void stworz(int wielkosc, double *tab){
	for(int i = 0; i < wielkosc; i++){
		tab[i] = ((double) rand() / (RAND_MAX));
	}
}
