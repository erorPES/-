#include <iostream>
using namespace std;

class uravnenie 
{
	public:
	uravnenie ()
	{
		A=0;
		B=0;
		C=0;
	}
	~uravnenie (){
		cout << "Hi, I desructor object: " << this << endl;
	}
	uravnenie (int x, int y, int z)
	{
		A=x;
		B=y;
		C=z;
	}
	uravnenie(uravnenie &p){
	A = p.A;
	B = p.B;
	C = p.C;
	}
	
	void get () { cout << A << " " << B << " " << C << endl;}
	private:
	double A;
	double B;
	double C;
};

int main(){
	uravnenie u1;
	uravnenie u2(2,3,4);
	uravnenie u3=u2;
	u1.get();
	u2.get();
	u3.get();
return 0; 
}