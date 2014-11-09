#include <fstream>
#include <iostream>

using namespace std;

void odczytaj(ifstream &plik, double *tab){
	double liczba;
	int i = 0;
	
	if(plik){
		while(plik >> liczba){
			tab[i] = liczba;
			i++;
		}
	}
	else{
		cout <<"Blad przy otwieraniu pliku\n";
	}
}
