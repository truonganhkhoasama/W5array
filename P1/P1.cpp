#include <iostream>
using namespace std;

struct phanso {
	int tu;
	int mau;
};

//Ham rut gon phan so
void Rutgon(int& t, int& m)
{
	int ucln = 0;
	if (m > 0)
	{
		for (int i = 1;i <= m;i++)               //tim uoc chung lon nhat cua tu va mau
		{
			if (t % i == 0 && m % i == 0)
			{
				ucln = i;
			}
		}
		t /= ucln;
		m /= ucln;
	}
	else
	{
		for (int i = -1;i >= m;i--)               //tim uoc chung lon nhat cua tu va mau
		{
			if (t % i == 0 && m % i == 0)
			{
				ucln = i;
			}
		}
		t /= ucln;                                //rut gon
		m /= ucln;                                //
	}
}

//Ham cong phan so
void Plus(phanso A, phanso& B)                    
{
	int t = A.tu * B.mau + B.tu * A.mau;
	int m = A.mau * B.mau;
	Rutgon(t, m);
	B = { t,m };
}

//Ham tinh tong day phan so
void Sum(phanso A[], phanso& Tong, int size)
{
	Tong = { 0,1 };
	for (int i = 0;i < size;i++)
	{
		Plus(A[i], Tong);
	}
}

//Ham hoan doi 2 phan so
void Swap(phanso& a, phanso& b)
{
	phanso temp = a;
	a = b;
	b = temp;
}

//Ham in phan so
void Print(phanso arr[], int size)
{
	for (int i = 0;i < size;i++)
	{
		cout << arr[i].tu << "/" << arr[i].mau << "  ";
	}
	cout << "\n";
}

//Ham sap xep day phan so
void Rearrange(phanso arr[], int size)
{
	for (int i = 0;i < size;i++)
	{
		for (int j = i + 1;j < size;j++)
		{
			if ((double)arr[j].tu / arr[j].mau < (double)arr[i].tu / arr[i].mau)
			{
				Swap(arr[j], arr[i]);
			}
		}
	}
	Print(arr, size);
}

int main()
{
	phanso A[] = { {1,2},{-1,2},{1,3},{2,-5},{3,-4},{1,4} };
	int size = sizeof(A) / sizeof(*A);
	cout << "Day phan so: "; Print(A, size); cout << "\n";

	phanso Tong;
	Sum(A, Tong, size);
	cout << "Tong cua day phan so la: ";
	if ((double)Tong.tu / Tong.mau != 0)
	{
		cout << Tong.tu << "/" << Tong.mau;
	}
	else cout << 0;

	cout << "\n\nDay phan so sau khi sap xep: "; Rearrange(A, size);

	return 0;
}
