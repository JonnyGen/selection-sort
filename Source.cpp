//header files

#include <iostream>
#include <ctime>
//general purpose library
#include <cstdlib> 
#include <time.h>
#include <algorithm>


using namespace std;

//Swaps the numbers
void swap(int a[], int b, int c)
{

	int hold = a[b];
	a[b] = a[c];
	a[c] = hold;
}

// finds the smallest number
int locSmallest(int a[], int s, int e)
{
	int i = s;
	int j = i;
	while (i <= e)
	{
		if (a[i] < a[j])
		{
			j = i;
		}
		i = i + 1;

	}

	return j;
}

// selection sort function
void selSort(int a[], int n)
{
	int i = 0;
	while (i<n-1)
	{
		int j = locSmallest(a, i, n-1);
		swap(a, i, j); 
		i++;
	}
}
//display function
void display(int a[], int n)
{
	int i = 0;
	while (i < n)
	{
		cout << a[i] << ",";
		i++;
	}
	cout<<endl;
}

int main()
{
	clock_t start, end;

	int arr100[10000];
	int size = sizeof(arr100)/sizeof(int);
	display(arr100, size);
	start = clock();
	selSort(arr100, size);
	end = clock();
	display(arr100, size);
	cout << "time in ms" << (end - start) << endl;
	
	

	return 0;
}
