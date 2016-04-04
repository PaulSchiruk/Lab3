#include <iostream>

//#define WINDOW_WIDTH  640
//#define WINDOW_HEIGHT 480

using namespace std;

void EnterArray(int**, int);
void EnterArrayMax(int**, int**, int n);
void DisplayArray(int**, int);
int **MemoryFill(int);
void MemoryFree(int**, int);
int Algorithm(int**, int, int, int);


int main()
{
	int n = 10;
	//cin >> n;
	int** a = MemoryFill(n);
	int** b = MemoryFill(n);

	EnterArray(a, n);
	EnterArrayMax(a, b, n);
	DisplayArray(a, n);
	cout << endl;
	DisplayArray(b, n);
	cout << endl;
	MemoryFree(a, n);
	MemoryFree(b, n);
	system("pause");
	return 0;
}


int Algorithm(int** a, int k, int l, int n)
{
	int max = a[k][l];
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		
		if (i <= k)
		{
			t = abs(k + l - i);
		}
		else
		{
			t = (k + l - i) + (i - k) * 2;
		}
		if (t >= n) t = n - 1;

		for (int j = 0; j <= t; j++)
		{
			if (a[i][j] > max)
				max = a[i][j];
		}
	}
	return max;
}

int** MemoryFill(int n)
{
	int** a = new int*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}
	return a;
}

void EnterArray(int** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 200 - 100; //n*i + j + 1;
		}
	}
}

void EnterArrayMax(int** a, int** b, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] = Algorithm(a, i, j, n);
		}
	}
}

void DisplayArray(int** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(4);
			cout << a[i][j];
		}
		cout << endl;
	}
}


void MemoryFree(int** a, int n)
{

	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete a;
}

