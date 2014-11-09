#include <fstream>
#include <iostream>

using namespace std;

void zapisz(int wielkosc, ofstream &strumien, double *tab){
	if(strumien){
		for(int i = 0; i < wielkosc; i++){
			strumien << tab[i] <<"\n";
		}
	}
	else{
		cout <<"Blad przy otwieraniu pliku\n";
	}
}
