#include <iostream>
using namespace std;
struct poligon
{
	double side;
};

bool Check(poligon arr[], int size)
{
	double sum;
	for (int i = 0; i < size;i++)
	{
		if (arr[i].side <= 0)
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
	poligon A[] = { 1,6,2,3 };
	int size = sizeof(A) / sizeof(*A);

	if (Check(A, size) == true)
	{
		cout << "Chu vi cua da giac la: " << Perimeter(A, size);
	}
	else cout << "Do dai canh khong hop le";
}
