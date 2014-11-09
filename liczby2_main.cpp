#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <cmath>
#include <sstream>
#include "liczby2.h"

using namespace std;

int main(){

	double *tab;
	ofstream strumien;
	ifstream plik;
	
	clock_t t1, t2;
	float ratio;
	ratio = 1./CLOCKS_PER_SEC;	
	float czas;
	
	int i, wynik, d = 100;
	ostringstream ss;
	ss << d;
	string str = ss.str();
	
	i = 1;
	if(strumien.good() && plik.good()){
		cout <<"rozmiar |\tczas_tworzenia |\tczas_pisania |\tczas_czytania |\n";
		while(i <= 5){
			wynik = pow(10, i+1);
			tab = new double[wynik];
			strumien.open(str.c_str());
			cout.precision(3);
			cout <<wynik<<"\t\t";
			
			t1 = clock();
			stworz(wynik, tab);
			t2 = clock();
			czas = ratio*(long)t2-ratio*(long)t1;
  			cout << fixed << czas << "\t\t\t";
			
			t1 = clock();
			zapisz(wynik, strumien, tab);
			t2 = clock();
			czas = ratio*(long)t2-ratio*(long)t1;
  			cout << fixed <<czas << "\t\t";
  			strumien.close();
			delete [] tab;
			
			t1 = clock();
			plik.open(str.c_str());
			tab = new double[wynik];
			odczytaj(plik, tab);
			t2 = clock();
			czas = ratio*(long)t2-ratio*(long)t1;
  			cout << fixed <<czas << "\n";
			plik.close();
			
			i++;
			str = str + "0";
			delete [] tab;
		}
	}
	else{
		cout <<"Blad przy otwieraniu pliku\n";
	}
	
	return 0;
}
