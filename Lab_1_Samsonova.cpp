#include <iostream>
using namespace std;

int main ()
{
int i;

cout << "Please enter the number of array elements: ";		// i - max �������� ���������� ��������� ��������� �������
cin >> i;

int *mas= new int [i];

int kount = 0;			// max �������� ���������� ��������� ������ ������� � ����������� ����������

cout << "Please enter elements: ";			//� - ����� �������
for (k=0; k<i; k++)
{
cin >> mas[k];
if ((k%2 !=0) && ( mas[k]%2==0))
	{
		kount++
    }
}

int *mas1= new int [i-kount];		//�������� ������ ������� ��� ������������ ���������
int *newmas= new int [kount];

for (int p=0, m=0, n=0; p<i; p++) 
{
if ((p%2 !=0) && (a[i] mas[p]%2==0))		// ������������� ���������
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

for (int n = 0; n < i-kount - 1; n++)		 // ���������� ���������
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
  
for (int n = 0; n < i-kount; n++)		// ����� ���������������� ������� �� �����
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
