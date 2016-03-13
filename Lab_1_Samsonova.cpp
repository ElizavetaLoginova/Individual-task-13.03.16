#include <iostream>
using namespace std;

int main ()
{
int i;

cout << "Please enter the number of array elements: ";		// i - max значение количества элементов исходного массива
cin >> i;

int *mas= new int [i];

int kount = 0;			// max значение количества элементов нового массива с подходящими элементами

cout << "Please enter elements: ";			//к - номер позиции
for (k=0; k<i; k++)
{
cin >> mas[k];
if ((k%2 !=0) && ( mas[k]%2==0))
	{
		kount++
    }
}

int *mas1= new int [i-kount];		//создание нового массива для неподходящих элементов
int *newmas= new int [kount];

for (int p=0, m=0, n=0; p<i; p++) 
{
if ((p%2 !=0) && (a[i] mas[p]%2==0))		// распределение элементов
  {
   newmas[m]=mas[p]
   m++;
  }
else 
  {
   mas1[n]=mas[p]
   n++;
  }
}

for (int n = 0; n < i-kount - 1; n++)		 // сортировка пузырьком
{
   for (int j = 0; j < i-kount - n - 1; j++) 
	{
            if (mas1[j] < mas1[j + 1]) 
			{
                temp = mas1[j];
                mas1[j] = mas1[j + 1];
                mas1[j + 1] = temp;
            }
     }
}
  
for (int n = 0; n < i-kount; n++)		// вывод отсортированного массива на экран
{
   cout << mas1[n] << " ";
}
    cout << endl;
for (int m = 0; m < i; m++) 
{
   cout << newmas[m] << " ";
}
    cout << endl;
    
    return 0;
}
