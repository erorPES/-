#include <iostream>
using namespace std;
const int MAX_SIZE = 30;
class Plenty
{
	int size;
	int* data;
public:
	Plenty(int s, int k = 0)
	{
		if (s > MAX_SIZE) throw 1;
		size = s;
		data = new int[size];
		for (int i = 0; i < size; i++)
			data[i] = k;
	}
	Plenty(const Plenty& a)
	{
		size = a.size;
		data = new int[size];
		for(int i = 0; i < size; i++)
			data[i] = a.data[i];
	}
	~Plenty()
	{
		delete [] data;
	}
	Plenty& operator=(const Plenty& a)
	{
		data = new int[size];
		for(int i = 0; i < size; i++)
			data[i] = a.data[i];
		return *this;
	}
	int& operator[](int i)
	{
		if (i < 0) throw 2;
		if (i >= size) throw 3;
		return data[i];
	}
	Plenty& operator-(const Plenty&a)
	{
		if (size != a.size)
		{
			return *this;
		}
		else
		{
			for (int i = 0; i < size; i++)
				data[i] = data[i] - a.data[i];
			return *this;
		}
	}
	friend ostream& operator<<(ostream& out, const Plenty&a);
	friend istream& operator>>(istream& in, Plenty& a);
};
ostream& operator<<(ostream& out, const Plenty&a)
{
	for (int i = 0; i < a.size;i++)
		out << a.data[i] << " ";
	return out;
}
istream& operator>>(istream& in, Plenty& a)
{
	cout << "Input size: ";
	cin >> a.size;
	for (int i = 0; i< a.size; i++)
	{
		cout << "Input elem: ";
		in >> a.data[i];
	}
	return in;
}

int main()
{
	try
	{
		Plenty a(2);
		cout << "Plenty a" << endl;
		cin >> a;
		int index;
		cout << "Input index: "; cin >> index;
		cout << "a[" << index << "] = " << a[index];
	}
	catch (int)
	{
		cout << "Error!" << endl;
	}
	return 0;
}