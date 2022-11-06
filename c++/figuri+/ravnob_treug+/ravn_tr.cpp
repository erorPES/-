#include <iostream>
using namespace std;

int main()
{
	int n, p, z;
	cout << "Vvedite razmer osnovania: ";
	cin >> n;
	p = n;
	z = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= p; j++)
			cout << " ";
		for (int j = 1; j <= z; j++)
			cout << "*";
		z = z+2; 
		p = p-1;
		cout << endl;
	}
	return 0;
}