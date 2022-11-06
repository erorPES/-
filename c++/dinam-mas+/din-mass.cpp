#include <iostream>
using namespace std;

int main(){
	int n, a, b;
	cout << "vvedite nachalnuy razmernost massiva" <<endl;
	cin >> n;
	int *mass = new int[n];
	int *mass2 = new int [n+b];
	for (int i=0; i<n; i++){
		*(mass+i)=rand() % 10; 
	}
	cout << "   vvedite snachala nomer elementa, posle kotorogo vstavit" <<endl;
	cout << "n elementov massiva, a potom ih chislo" <<endl;
	cin >> a >> b;
	if (a>n) {
		cout << "takogo elementa ne syshestvyet" <<endl;
		cout << "programm exit" <<endl;
	}
		else{
			for (int i=0; i<(a); i++){
					*(mass2+i)=*(mass+i);
			}	
			for (int i=0; i<b; i++){
					*(mass2+a+i)= 6;
			}
			for (int i=0; i<(n-a); i++){
					*(mass2+a+b+i)=*(mass+i+a);
			}
			for (int i=0; i<(n+b); i++){
				cout << *(mass2+i) << " ";
			}	
		}
		
delete [] mass;	
delete [] mass2;	
return 0;
}