#include <iostream>
using namespace std;

class pairy
{
private:
	int  first, second;
public:
//
virtual void virt();
//
	pairy (int x, int y) 
	{first = x; second = y;}
	pairy () 
	{first = 1; second = 1;}
	pairy(pairy &p)
	{first = p.first; second = p.second;}
	~pairy ()
	{cout << "Hi, I desructor object: " << this << endl;}
	void get() {
		cout << "first = " << first << " second = "<< second << endl;
	}
	void set() {
		cout << "Vvedite znachenie polei first and second" << endl;
		cout << "first = "; cin >> first;
		cout << "second = "; cin >> second;
	}
	//перегрузка оператора =//
	void operator = (const pairy & right) { 	
		this->first = right.first;
		this->second = right.second;
	}
	//перегрузка оператора =//
	//Перегрузка операторов << и >>//
	friend ostream& operator << (ostream& os, const pairy& p) {
	os << p.first << " " << p.second << endl;
	return os;
	}
	friend istream& operator >> (istream& is, pairy& p) {
	is >> p.first >> p.second;
	return is;
	}
	//Перегрузка операторов << и >>//
	//Перегрузка оператора + для чисел//
	void operator + (const pairy & right) { 	
		this->first = this->first + right.first;
		this->second = this->second + right.second;
	}
//Перегрузка оператора + для чисел//
};

class money : public pairy 
{
public:
void virt(){cout << "vizvana virtualnaya f" << endl;}	
	money (int x, int y) 
	{rub = x; cop = y;}
	money () 
	{rub = 1; cop = 30;}
	void operator - (const money & right) { 	
		this->rub = this->rub - right.rub;
		this->cop = this->cop - right.cop;
	}
	int operator / (const money & right) { 	
		int itog;
		itog = ((this->rub)*100 + this->cop)/((right.rub)*100 + right.cop);
		return itog;
	}
	void get() {
		cout << "rub = " << rub << " cop = "<< cop << endl;
	}
	void set() {
		cout << "Vvedite znachenie polei rub and cop" << endl;
		cout << "rub = "; cin >> rub;
		cout << "rub = "; cin >> rub;
		cout << "cop = "; cin >> cop;
	}
private:
	int rub, cop;
};

int main() {
	int x,y,k,z,s;
	pairy p1;
	cout << "Vvedite snachala pervoe chislo, potom vtoroe chislo" << endl;
	cin >> x >> y;
	pairy p2(x, y);
	pairy p3=p2;
	cout << "znacheniya tretiei pari chisel:" << endl;
	p3.get();
	cout << "pereustanovire znacheniya tretiei pari chisel:" << endl;
	p3.set();
	cout << "znacheniya tretiei pari chisel:" << endl;
	p3.get();
	cout << "priravnivaem 3 paru k pervoi, sozdanoi constructorom bez parametrov" << endl;
	p3 = p1;
	cout << "znacheniya tretiei pari chisel:" << endl;
	p3.get();
	cout << "izmenim znacheniya dlua 2 pari. Vvedite ih." << endl;
	cin >> p2 ;
	cout << "znacheniya 2 pari:" << p2 << endl;
	cout << "pribavim k 1 pare 2" << endl;
	p1 + p2;
	cout << "znacheniya pervoi pari chisel:" << endl;
	p1.get();
	cout << "  " << endl;
	money m1;
	cout << "Vvedite snachala rub, potom cop" << endl;
	cin >> k >> z;
	money m2(k, z);
	m2 - m1;
	m2.get();
	s = (m2 / m1);
	cout << "othoshenie summ: " << s << endl;
	m1.virt();
return 0;
}