#include <iostream>
using namespace std;

template <typename T>
class Plenty
{
private:
	int size; // размер множества
	T* data; // указатель на массив значений множества
public:
	Plenty(int s, T k = 0)
	{
		size = s;
		data = new T[size];
		for (int i = 0; i < size; i++)
			data[i] = k;
	}
	Plenty(const Plenty<T>& a)
	{
		size = a.size;
		data = new T[size];
		for(int i = 0; i < size; i++)
			data[i] = a.data[i];
	}
	~Plenty()
	{
		delete [] data;
	}
	Plenty& operator=(const Plenty<T>& a)
	{
		data = new T[size];
		for(int i = 0; i < size; i++)
			data[i] = a.data[i];
		return *this;
	}
	int& operator[](int index)
	{
		return data[index];
	}
	Plenty& operator-(const Plenty<T>&a)
	{
		if (size != a.size)
		{
			cout << "Error, sizes don't match" << endl;
			return *this;
		}
		else
		{
			for (int i = 0; i < size; i++)
				data[i] = data[i] - a.data[i];
			return *this;
		}
	}
	template <typename Type>
	friend ostream& operator<<(ostream& out, const Plenty<Type>&a);
	template <typename Type>
	friend istream& operator>>(istream& in, Plenty<Type>& a);
};
template <typename Type>
ostream& operator<<(ostream& out, const Plenty<Type>&a)
{
	for (int i = 0; i < a.size;i++)
		out << a.data[i] << " ";
	return out;
}
template <typename Type>
istream& operator>>(istream& in, Plenty<Type>& a)
{
	cout << "Input size: ";
	cin >> a.size;
	for (int i = 0; i < a.size; i++)
	{
		cout << "Input elem: ";
		in >> a.data[i];
	}
	return in;
}

class Money
{
private:
	long rub;
	int kop;
public:
	Money() : rub(0), kop(0) {};
	Money(long r, int k) : rub(r), kop(k) {};
	Money (const Money& t) : rub(t.rub), kop(t.kop) {};
	~Money(){};
	Money& operator = (const Money& t)
	{
		rub = t.rub;
		kop = t.kop;
		return *this;
	}
	Money& operator-(const Money& a)
	{
		long t3 = abs(a.rub * 100 + a.kop - (rub * 100 + kop));
		rub = t3 / 100;
		kop = t3 % 100;
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Money& a);
	friend istream& operator>>(istream& in, Money& a);

};
ostream& operator<<(ostream& out, const Money& a)
{
	out << a.rub << "," << a.kop << endl;
	return out;
}
istream& operator>>(istream& in, Money& a)
{
	cout << "rub = "; in >> a.rub;
	cout << "kop = "; in >> a.kop;
	return in;
}

int main()
{
	Plenty<double> a(10);
	cout << "Plenty a" << endl;
	cin >> a;
	Plenty<double> a1(5, 7);
	cout << "Plenty a1 : " << a1 << endl;
	Plenty<double> c = a1-a;
	cout << "a1 - a = " << c << endl;
	Money t1; cout << "t1..." << endl; cin >> t1;
	Money t2; cout << "t2..." << endl; cin >> t2;
	Money t3 = t2 - t1;
	cout << "Difference between t2 and t1 = " << t2;
	Money t;
	cin >> t;
	cout << t;
	Plenty<Money>A(5, t);
	cin >> A;
	cout << A << endl;
	Plenty<Money>B(5, t);
	cout << B << endl;
	Plenty<Money>C(5, t);
	C = B - A;
	cout << "B - A:" << endl;
	cout << C;
	return 0;
}