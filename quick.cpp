#include<iostream>
#include<stdlib.h> 
#include<omp.h> 
using namespace std;

int partition(int arr[],int low,int high) 
{ 
	int pi=arr[high],i=low-1,j,temp; 
	for(j=low;j<high;j++) 
	{ 
		if(arr[j]<pi) 
		{ 
			i++; 
			temp=arr[i]; 
			arr[i]=arr[j]; 
			arr[j]=temp; 
		} 
	} 
	i++; 
	temp=arr[i]; 
	arr[i]=arr[j]; 
	arr[j]=temp; 
	return i; 
}
void quicksort(int arr[],int low,int high) 
{ 
	int pi; 
	if(low<high) 
	{ 
		pi=partition(arr,low,high); 
		#pragma omp parallel section 
		{ 
			#pragma omp section 
				quicksort(arr,low,pi-1); 
			#pragma omp section 
				quicksort(arr,pi+1,high); 
		} 
	} 
} 

int main() 
{ 
	int no,i; 
	cout<<"Enter the no of elements : "; 
	cin>>no; 
	int arr[no]; 
	if(no<=10) 
	{ 
		cout<<"Enter the elements : \n"; 
		for(i=0;i<no;i++) 
			cin>>arr[i]; 
	} 
	else 
	{ 
		for(i=0;i<no;i++) 
		{ 
			arr[i]=rand() % (no*4); 
		} 
		cout<<"The array is : \n"; 
		for(i=0;i<no;i++) 
		{ 
			cout<<arr[i]<<"\n"; 
		} 
	} 

	int low=0, high=no-1; 
	quicksort(arr,low,high); 
	cout<<"\nThe sorted array is : \n"; 
	for(i=0;i<no;i++) 
		cout<<"\n"<<arr[i]; 
	return 0; 
} 


