#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
	int n = 1, b, c=0;
	double a=1;	
	while (n!=100)
		{
			a += pow(-1, n - 1) / pow(n, n);
			n++; 
		}
	cout << "symma ruada s tochnosty do 4 znaka zapyatoy ravna" <<endl;
	cout << fixed << setprecision(4) << a;
return 0;
}