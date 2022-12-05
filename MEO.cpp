#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;


void Merge(int tab[], int l,int m, int r) // dane pobierane z tabeli z czesci main
{
	
	
	int i=l; // pierwszy element lewej tablicy
	int j=m+1; //pierwszy element prawej tablicy
	int k=l; //początkowy element tablicy tymczasowej
	
	int tym[11]; // wielkosc tab = mytab
		
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
		fstream plik;
		plik.open("sort.txt", ios::in | ios::out | ios::binary); //zapisywanie z pliku
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
//for (int i=0;i<Alen;i++) 
//{
//	cin>>mytab[i];
//}
cout <<"Przed sortowaniem przez scalanie: "<<endl;
plik << "Przed sortowaniem przez scalanie: "<< endl;
for (int i=0;i<Alen;i++) 
{	
	plik<<mytab[i]<<" ";
	cout<<mytab[i]<<" "; // wypisz tablice podaną przez użytkownika
}
	
//wykonaj funkcje mergesort - dzielenia tablicy
mergesort(mytab,0,Alen-1);
		
cout <<"Po sortowaniu przez scalanie: "<<endl;
plik << "Twoje liczby po sortowaniu"<< endl;
for (int i=0;i<Alen;i++) 
{
	plik<<mytab[i]<<" ";
	cout<<mytab[i]<<" ";  // wypisz posortowaną tablice
}	
plik.close(); // zamkij zapis do pliku
	return 0;
}


