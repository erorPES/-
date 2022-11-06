#include <iostream>
using namespace std;

int main(){
	int n, a, b, npl, kolpl, razm;
	cout << "vvedite nachalnuy razmernost massiva" <<endl;
	cin >> n;
	int *mass = new int[n];
	
	for (int i=0; i<n; i++){
		*(mass+i)=rand() % 10; 
	}
	cout << "   vvedite snachala nomer elementa, posle kotorogo udalit" <<endl;
	cout << "n elementov massiva, a potom ih chislo" <<endl;
	cin >> a >> b;
	int *mass2 = new int [n-b];
	if (a>n) {
		cout << "takogo elementa ne syshestvyet" <<endl;
		cout << "programm exit" <<endl;
	}
		else{
			for (int i=0; i<(a); i++){
					*(mass2+i)=*(mass+i);
			}
			for (int i=0; i<(n-a-1); i++){
					*(mass2+a+i)=*(mass+i+a);
			}
			for (int i=0; i<(n-b); i++){
				cout << *(mass2+i) << " ";
			}	
		}
	
	cout << "   vvedite snachala nomer elementa, posle kotorogo vstavit" <<endl;
	cout << "n elementov massiva, a potom ih chislo" <<endl;
	cin >> npl >> kolpl;
	razm = n-b+kolpl;
	int *mass3 = new int [razm];
	if (npl>(n-b)) {
		cout << "takogo elementa ne syshestvyet" <<endl;
		cout << "programm exit" <<endl;
	}
		else{
			for (int i=0; i<(npl); i++){
					*(mass3+i)=*(mass2+i);
			}	
			for (int i=npl; i<(npl+kolpl); i++){
				*(mass3+i) = 6;
			}
			for (int i=npl+kolpl; i<(npl+kolpl+razm); i++){
				*(mass3+i) = *(mass2-kolpl+i);
			}
			for (int i = 0; i<razm; i++){
				cout << *(mass3+i)<< " ";
			}
		}		
delete [] mass;	
delete [] mass2;
delete [] mass3;		
return 0;
}