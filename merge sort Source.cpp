//header files
#include <iostream>
#include<time.h>
using namespace std;

//combine function
void combine(int a[], int s, int mid, int e)
{
	int* buffer = new int[e + 1];
	int k = s;
	while (k <= e)
	{
		buffer[k] = a[k];
		k = k + 1;

	}
	int i = s;
	int j = mid + 1;
		k = s;
		while (i <= mid && j <= e)
		{
			if (buffer[i] <= buffer[j])
			{
				a[k] = buffer[i];
				i = i + 1;
			}
			else
			{
				a[k] = buffer[j];
					j = j + 1;
			}
			k = k + 1;
		}
		while (i <= mid)
		{
			a[k] = buffer[i];
			i = i + 1;
			k = k + 1;
		}
		while (j <= e)
		{
			a[k] = buffer[j];
			j = j + 1;
			k = k + 1;
		}
		delete[] buffer;

}


//auxiliary function
void merSort(int a[], int s, int e)
{
	if (s >= e)
	{
		return;
	}
	int mid = (s + e) / 2;
	merSort(a, s, mid);
	merSort(a, mid + 1, e);
	combine(a, s, mid, e);
}


void merSort(int a[], int n)
{
	merSort(a, 0, n-1);
}

void display(int a[], int n)
{

	int i = 0;
	while (i < n)
	{
		cout << a[i] << ",";
		i++;
	}
	cout << endl;
}


int main()

{
	int arr100[10000];
int size = sizeof(arr100) / sizeof(int);

display(arr100, size);
clock_t start, end;
start = clock();
merSort(arr100, size);
end = clock();

display(arr100, size);
cout << "time in ms" << (end - start) << endl;


	return 0;
}