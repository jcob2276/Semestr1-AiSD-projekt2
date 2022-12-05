#include <iostream>
using namespace std;

//	merge function	
void merge(int arr[], int l,int m, int r)
{
	int i=l; //starting index for lef
	int j=m+1; //starting index for right
	int k=l; //starting index for temporary
	
	int temp[5];
	
	while (i<=m && j<=r)
	{
		if (arr[i]<= arr[j])
		{
			temp[k]=arr[i]; // arr[i] is smaller than arr[j]
			i++;
			k++;		
		}		
		else 
		{
		temp[k]=arr[j]; // arr[j] is smaller than arr[i]
			j++;
			k++;
		}
	}
	while(i<=m)
	{
		temp[k]=arr[i]; // kopiowanie all elements  from left subbray to tempas it is
			i++;
			k++;
	}
	while(j<=r)
	{
		temp[k]=arr[j]; // kopiowanie all elements  from right subbray to tempas it is
			j++;
			k++;
	}
	for (int s=l;s<=r;s++)
	{
		arr[s]=temp[s];
	}
}
	//mergeSort function	
void mergesort(int arr[],int l, int r) {
	
	if (l<r)
	{
		int m =(l+r)/2;
		mergesort (arr,l,m);
		mergesort(arr,m+1,r);
		merge(arr,l,m,r); 
	}
	
}
		
int main()

{
cout<<"Podaj 5 elementw tablicy"<<endl;
int myarr[5];
for (int i=0;i<5;i++) 
{
	cin>>myarr[i];
}
cout <<"Before Merge Sort: "<<endl;
for (int i=0;i<5;i++) 
{	
	cout<<myarr[i]<<" ";
}
	
//merge sort function
mergesort(myarr,0,4);
		
cout <<"After Merge Sort: "<<endl;
for (int i=0;i<5;i++) 
{
	cout<<myarr[i]<<" ";
}	
	return 0;
}