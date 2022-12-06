#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <chrono>
using namespace std;
const int N = 100000; // Liczebność zbioru
clock_t start,stop;
double czas;


void GnomeSort(int tab[],int r) {
	int i = 0;
	
	while (i<r){
		if (i==0) i++;
		if(tab[i] >= tab[i-1]) i++;
	else {
		const int j = tab[i];
		tab[i] = tab[i-1];
		tab[i-1] = j;
		i--; 
	}	
	}
}

void Merge(int tab[], int l,int m, int r) // dane pobierane z tabeli z czesci main
{
	int i=l; // pierwszy element lewej tablicy
	int j=m+1; //pierwszy element prawej tablicy
	int k=l; //początkowy element tablicy tymczasowej
	int tym[N]; // wielkosc tab = mytab
		
	while (i<=m && j<=r) // petla wykonuje sie dopoki pierwsze el.
	// 2 tablic dojda do do końca swojego rozmiaru
	{
		if (tab[i]<= tab[j]) 
		{
			tym[k]=tab[i]; // tab[i] jest mniejsze od tab[j]
			i++;
			k++;		
		}		
		else 
		{
		tym[k]=tab[j]; // tab[j] jest mniejsze od tab[i]
			j++;
			k++;
		}
	}
	while(i<=m) // wykonuj dopóki pierwszy el. jest równy m 
	{
		tym[k]=tab[i]; // przepisywanie el. z lewej tablicy
		// do tymczasowej tablicy
			i++;
			k++;
	}
	while(j<=r) // wykonuj dopóki pierwszy el. 2. tablicy jest równy r 
	{
		tym[k]=tab[j]; // przepisywanie el. z prawej tablicy
		// do tymczasowej tablicy
			j++;
			k++;
	}
	for (int s=l;s<=r;s++) // zmienna s; przepisujemy 
	//posortowane liczby do tabeli wejściowej
	{
		tab[s]=tym[s];
	}
}

	//funkcja mergesort	
void mergesort(int tab[],int l, int r) {
	
	if (l<r)   // jeśli pierwszy element jest tablicy jest mniejszy
	// niż ostatni wykonuj: 
	{
		int m =(l+r)/2;  // ustal jak jest srodek tablicy 
		mergesort (tab,l,m);
		//wywołanie funkcji dla obu przedziałów
		mergesort(tab,m+1,r);
		Merge(tab,l,m,r); //scal obie tablice
	}
	
}

int main()

{
	cout <<"Wczytywanie z pliku (1)" << endl;
	cout <<"Losowe generowanie (2)" << endl;
	srand(time(NULL));
		int wybor;
	cout <<"Wybierz metode" << endl;
	cin >> wybor;

	switch (wybor) { // wybór metody wprowadzania
	
	case 1: { //metoda pierwsza
		
		fstream plik;
		plik.open("sort.txt", ios::out | ios::in); //zapisywanie z pliku
		//plik1.open ("sort2.txt",ios::out); // otwiera zapis do pliku
		int Alen=0;
		string linia;  //dlugosc tablicy wyliczona 
		while(getline(plik, linia)){Alen++;} //poprzez zliczenie linijek wierszy
		plik.clear();  // czyści flagi na otwarciu pliku
		plik.seekg(0,plik.beg); // wstawianie kursora na początek pliku
		int mytab[Alen]	= {0}; // tworzy tabele o nazwie z o długości Alen
		int numery = 0;
		while (getline(plik,linia)) { //dzięki funkcji getline czytamy pokolei wiersze w pliku
		mytab[numery++] = atoi(linia.c_str()); //zmienia string na int	
		}
cout<<"Pobieram " << Alen << " liczb"<<endl;
mytab[Alen];
cout <<"Liczby przed sortowaniem: "<<endl;
plik << "Liczby przed sortowaniems: "<< endl;
for (int i=0;i<Alen;i++) 
{	
	plik<<mytab[i]<<" ";
	cout<<mytab[i]<<" "; // wypisz tablice podaną przez użytkownika
}
cout << "\n";

//wykonaj funkcje mergesort - dzielenia tablicy
mergesort(mytab,0,Alen-1);

cout <<"Po sortowaniu przez scalanie: "<<endl;
plik << "Twoje liczby po sortowaniu"<< endl;

for (int i=0;i<Alen;i++) 
{
	cout<<mytab[i]<<" ";  // wypisz posortowaną tablice
	plik<<mytab[i]<<" ";
}	

plik.close(); // zamkij zapis do pliku	
		break;
	}
		case 2:{ // metoda druga
			fstream plik; // tworzy plik
	plik.open ("sort2.txt",ios::out); // otwiera zapis do pliku
	int mytab[N];
	int mytab2[N];
			
		for(int i = 0; i < N; i++) mytab[i] = rand() % 10000;
		for (int i=0; i< N; i++) mytab2[i]= mytab[i];
				//losowanie liczb 
		cout<<"Pobieram " << N << " liczb"<<endl;
//		cout <<"Przed sortowaniem przez scalanie: "<<endl;
//		plik << "Przed sortowaniem przez scalanie: "<< endl;
//	for (int i=0;i<N;i++) 
//{	
//	plik<<mytab[i]<<" ";
//	cout<<mytab[i]<<" "; // wypisz tablice podaną przez użytkownika
//}
cout << "\n";

	start = clock(); //start mierzenia czasu

//wykonaj funkcje mergesort - dzielenia tablicy
mergesort(mytab,0,N-1);
				
	stop = clock();
	czas = (double) (stop - start) / CLOCKS_PER_SEC; //cykle czasu
		
//cout <<"Po sortowaniu przez scalanie: "<<endl;
//plik << "Twoje liczby po sortowaniu"<< endl;
//
//
//for (int i=0;i<N;i++) 
//{
//	cout<<mytab[i]<<" ";  // wypisz posortowaną tablice
//	plik<<mytab[i]<<" ";
//}

cout << endl<<"Czas sortowania przez scalanie: "<<czas<<" s"<<endl;

cout << "\n";

	start = clock(); //start mierzenia czasu

GnomeSort(mytab2,N);

	stop = clock();
	czas = (double) (stop - start) / CLOCKS_PER_SEC; //cykle czasu
	
//cout <<"Po sortowaniu Gnoma: "<<endl;
//plik << "Twoje liczby po sortowaniu"<< endl;
//
//for (int i=0;i<N;i++) 
//{
//	cout<<mytab2[i]<<" ";  // wypisz posortowaną tablice
//	plik<<mytab2[i]<<" ";
//}	
	cout << endl<<"Czas sortowania metoda Gnoma: "<<czas<<" s"<<endl;
	
plik.close(); // zamkij zapis do pliku		
			break;
		}	
}
	return 0;
}