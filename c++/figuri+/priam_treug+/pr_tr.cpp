#include <iostream>
using namespace std;

int main()
{
	int n, p, z;
	cout << "Vvedite razmer kateta: ";
	cin >> n;
	p = n - 1;
	z = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= p; j++)
			cout << "  ";
		for (int j = 1; j <= z; j++)
			cout << " *";
		z++; p--;
		cout << endl;
	}
	return 0;
}