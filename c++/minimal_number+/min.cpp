#include <iostream>
using namespace std;

int min(int a){
	int min = a;
	while (a != 0)
            {
                cout << "vvedite sledushie chislo" << endl;
                cin >> a;
                if (a != 0 && a < min)

                    min = a;
            }
return min;	
}

int main(){
	int n, i = 0, k;
	int ssn = 3;
    cout << "vvedite pervoe chislo" << endl;
	cin >> n;
	if (n == 0)
	{
		while (i<ssn && n==0)
		{
			cout << "pervoe chislo ne mozhet bit null" << endl;
			cin >> n;
			i++;
		}
	}
	if (i!=(ssn+1)){
		k = min(n);
		cout << "minimalnoe chislo =" << k << endl;
	}		
		
    return 0;
}