#include <iostream>
#include <fstream>

using namespace std;

void Merge(int tab[], int l,int m, int r) // dane pobierane z tabeli z czesci main
{
	int i=l; // pierwszy element lewej tablicy
	int j=m+1; //pierwszy element prawej tablicy
	int k=l; //początkowy element tablicy tymczasowej
	
	int tym[9]; // wielkosc tab = mytab
		
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
cout<<"Podaj 10 elementow tablicy"<<endl;
int mytab[9];
for (int i=0;i<9;i++) 
{
	cin>>mytab[i];
}
cout <<"Przed sortowaniem przez scalanie: "<<endl;
for (int i=0;i<9;i++) 
{	
	cout<<mytab[i]<<" "; // wypisz tablice podaną przez użytkownika
}
	
//wykonaj funkcje mergesort - dzielenia tablicy
fstream output; // rozpocznij zapis do pliku
output.open("sort.txt",ios::out);
mergesort(mytab,0,8);
		
cout <<"Po sortowaniu przez scalanie: "<<endl;
for (int i=0;i<9;i++) 
{
	cout<<mytab[i]<<" ";  // wypisz posortowaną tablice
}	
output.close(); // zamkij zapis do pliku
	return 0;
}