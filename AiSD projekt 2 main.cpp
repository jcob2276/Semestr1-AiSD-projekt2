#include <iostream>
#include <fstream>

using namespace std;

void merge()

void mergesort()


int main()

{
cout<<"Podaj 10 elementow tablicy"<<endl;
int mytab[10];
for (int i=0;i<10;i++) 
{
	cin>>mytab[i];
}
cout <<"Przed sortowaniem przez scalanie: "<<endl;
for (int i=0;i<10;i++) 
{	
	cout<<mytab[i]<<" "; // wypisz tablice podaną przez użytkownika
}
	
//wykonaj funkcje mergesort - dzielenia tablicy
fstream output; // rozpocznij zapis do pliku
output.open("roznica.txt",ios::out);
mergesort(mytab,0,9);
		
cout <<"Po sortowaniu przez scalanie: "<<endl;
for (int i=0;i<10;i++) 
{
	cout<<mytab[i]<<" ";  // wypisz posortowaną tablice
}	
output.close(); // zamkij zapis do pliku
	return 0;
}