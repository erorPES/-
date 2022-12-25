#include <iostream>
using namespace std;

class error
{
protected:
	string message;
public:
	void what() {cout << message;}
};

class error_index_min: public error
{
public:
	error_index_min()
	{
		message = "Index fewer than 0";
	}
};

class error_index_max: public error
{
public:
	error_index_max()
	{
		message = "Index greater than max index";
	}
};

class error_size : public error
{
public:
	error_size()
	{
		message = "Error, sizes don't match";
	}
};

class Plenty
{
private:
	int size;
	int* data;
public:
	Plenty(int s, int k = 0)
	{
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
	int& operator[](int index)
	{
		if (index < 0) throw error_index_min();
		if (index >= size) throw error_index_max();
		return data[index];
	}
	Plenty& operator-(const Plenty&a)
	{
		if (size != a.size)
		{
			throw error_size();
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
		Plenty a1(5, 7);
		cout << "Plenty a1 : " << a1 << endl;
		Plenty c = a1-a;
		cout << "a1 - a = " << c << endl;
		int index;

		cout << "Input index: "; cin >> index;
		cout << "a[" << index << "] = " << a[index];
	}
	catch (error& a)
	{
		a.what();
	}
	return 0;
}