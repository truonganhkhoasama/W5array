#include <iostream>
using namespace std;
struct poligon
{
	double side;
};

//Ham kiem tra su ton tai cua da giac
bool Check(poligon arr[], int size)
{
	double sum;
	for (int i = 0; i < size;i++)
	{
		if (arr[i].side <= 0) //do dai canh khong duong
			return false;
		sum = 0;
		for (int j = 0; j < size; j++)
		{
			if (j != i)
			{
				sum += arr[j].side;
			}
		}
		if (sum <= arr[i].side)
			return false;
	}
	return true;
}

//Ham tinh chu vi da giac
double Perimeter(poligon arr[], int size)
{
	double p = 0;
	for (int i = 0; i <= size;i++)
	{
		p += arr[i].side;
	}
	return p;
}

int main()
{
	poligon A[] = { 1,6,5,3,7 };
	int size = sizeof(A) / sizeof(*A);

	if (Check(A, size) == true)
	{
		cout << "Chu vi cua da giac la: " << Perimeter(A, size)<<"\n";
	}
	else cout << "Do dai canh khong hop le, da giac khong ton tai\n";
}
