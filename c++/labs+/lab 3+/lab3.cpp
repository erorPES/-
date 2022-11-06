#include <iostream>
#include <cmath>
#include <iomanip>
#define exp 2.718
using namespace std;

int fact(int a){
	if (a !=1){
		a = a*fact(a-1); 
	}
	else{
		a = 1;
	}
return (a);
}
int main(){

    double Sn = 0;     	// значение суммы для заданного	n
    double Se = 0;		// значе-ние суммы для заданной точности
    double e = 0.0001; 	//заданная точность
    double y;          	// точное значение функции
	double x;		   	// значение параметра
    int n = 15;		   	// кол-во повторений для вычисления фунцкии n-ым числом эл. ряда
    double h = 0.1;		//значение шага для обоих методов
    float i1, i2; 		// переменные
    double xe;   	 	// накапливаемый элемент для суммирования
	
	for (x=1; x<=2.1; x+=h){				//цикл для вычисления суммы ряда при  n заданных членов
		y=pow(exp, x);
		for (int i=1;i<=n;i++){
			Sn += pow(x, i)/fact(i);
		}	
		cout << "y=" << y << "\tx=" << x << "\tsumm n chlenov=" << Sn << endl;
		Sn=0; 									// обнуление переменной для записи суммы ряда
		for (int i=1;i!=10;i++){
			Se += pow(x, i)/fact(i);
		}	
		cout << "  " << "\t  " << "\t\t\tsumm chlenov pri eps=0.0001 =" << fixed << setprecision(4) << Se << endl;
		Se=0; 								// обнуление переменной для записи суммы ряда
	}
    return 0;
}