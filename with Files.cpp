#include <iostream>
#include <fstream>
using namespace std;

int* InitArray(char* fileName, int n);
void AddFile(char* fileName, int* arr, int n);
void DisplayArray(int*, int);
void EnterArray(int *, int);
void Swap(int *, int *);
void SortExchange(int*, int);
int FirstSymboFromHexadecimalSystem(int);
int EnterDimention(int);
bool Hex(int, char);
void ToDeleteTheElement(int*, int&, int);
bool TheSameElement(int*, int);
void ToMakeTheArray(int*, int&, char, int*, int&);
void ByFile(char*, int);
void ByConsole();


int main()
{
	while (true)
	{

		const int L = 30;
		char fileName[L] = "";
		char var;
		cout << "If you want to solve by files press 1, else press 2";
		cin >> var;
		if (var == 1) ByFile(fileName, L);
		if (var == 2) ByConsole();
			
		char yes;
		cout << "Would you like to countinie? Press y/Y: " << endl;
		cin >> yes;
		if (yes == 'y' || yes == 'Y')
			continue;
		break;
	}
	return 0;

}

int* InitArray(char* fileName, int n)
{
	ifstream streamIn(fileName);
	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		streamIn >> arr[i];
	streamIn.close();
	return arr;
}

void AddFile(char* fileName, int* arr, int n)
{
	ofstream streamOut(fileName, ios::app);
	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}
	streamOut << "\n\n";
	for (int i = 0; i < n; i++)
	{
		streamOut.width(5);
		streamOut << arr[i];
	}
	streamOut.close();
}

int EnterDimention(int n)
{
	int k;
	while (true)
	{
		cout << "Enter the amount of elements (n <= 100): ";
		cin >> k;
		if (k > 0 && k <= n) return k;
		cout << "Error! Try again...";
	}
	return k;
}

void EnterArray(int* a, int n)
{
	cout << "Enter array elements: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << (i + 1) << "] = ";
		cin >> a[i];
	}
}

void DisplayArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << ", ";
}

void Swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int FirstSymboFromHexadecimalSystem(int a)
{
	int symbol;
	while (a)
	{
		symbol = a % 16;
		a /= 16;
	}
	return symbol;
}

void SortExchange(int* a, int n)
{
	for (int i = 1; i <= n - 1; i++)
	{
		int max = i - 1;
		for (int j = i - 1; j <= n - 1; j++)
		if (FirstSymboFromHexadecimalSystem(a[j]) > FirstSymboFromHexadecimalSystem(a[max]))
			max = j;
		Swap(a + i - 1, a + max);
	}
}

void ToDeleteTheElement(int* a, int &n, int k)
{
	for (int i = k; i < n; i++)
		a[i] = a[i + 1];
	n--;
}

bool Hex(int a, char symbol)
{
	char b[] = "0123456789ABCDEF";

	while (a)
	{
		int k = a % 16;
		if (b[k] == symbol) return true;
		a /= 16;
	}
	return false;
}

bool TheSameElement(int* a, int k)
{
	for (int i = 0; i < k; i++)
	if (a[i] == a[k]) return true;
	return false;
}

void ToMakeTheArray(int*a, int &n, char symbol, int*b, int &j)
{
	for (int i = 0; i < n; i++)
	if (Hex(a[i], symbol))
	{
		b[j] = a[i];
		ToDeleteTheElement(a, n, i);
		i--;
		j++;
	}
}

void ByFile(char* fileName, int L)
{
	
	cout << "Enter the name of file: ";
	cin.getline(fileName, L, '\n');
	
	system("cls");

	int n = EnterDimention(258);
	int* a = new int[n];
	EnterArray(a, n);

	system("cls");
	cout << "Source array: " << endl;
	DisplayArray(a, n);

	AddFile(fileName, a, n);

	for (int i = 0; i < n; i++)
	if (TheSameElement(a, i))
	{
		ToDeleteTheElement(a, n, i);
		i--;
	}

	SortExchange(a, n);
	//cout << endl << "Sorted array: " << endl;
	AddFile(fileName, a, n);
	cout << endl;

	char symbol;
	while (true)
	{
		cout << "Enter the symbol, you want to find (A, B, C, D, E, F): " << endl;
		cin >> symbol;
		if ((symbol >= 65) && (symbol <= 70)) break;
		cout << "Error! Try again...";
	}

	int k = 0;
	int* b = new int[k];
	ToMakeTheArray(a, n, symbol, b, k);
	AddFile(fileName, b, k);
	
}

void ByConsole()
{
	int n = EnterDimention(258);
	int* a = new int[n];
	EnterArray(a, n);
	system("cls");
	cout << "Source array: " << endl;
	DisplayArray(a, n);

	for (int i = 0; i < n; i++)
	if (TheSameElement(a, i))
	{
		ToDeleteTheElement(a, n, i);
		i--;
	}

	SortExchange(a, n);
	cout << endl << "Sorted array: " << endl;
	DisplayArray(a, n);
	cout << endl;

	char symbol;
	while (true)
	{
		cout << "Enter the symbol, you want to find (A, B, C, D, E, F): " << endl;
		cin >> symbol;
		if ((symbol >= 65) && (symbol <= 70)) break;
		cout << "Error! Try again...";
	}

	int k = 0;
	int* b = new int[k];
	ToMakeTheArray(a, n, symbol, b, k);

	cout << endl << "The old array is: " << endl;
	DisplayArray(a, n);
	cout << endl << "The NEW array is: " << endl;
	DisplayArray(b, k);
	system("pause");
}
