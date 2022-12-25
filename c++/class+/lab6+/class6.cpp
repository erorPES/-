#include <iostream>
using namespace std; 
class Iterator
{
	friend class Plenty;
	private:
		int *elem;
	public:
		Iterator(): elem(0){};
		Iterator(const Iterator& it):elem(it.elem){};
		bool operator==(const Iterator&it)
		{
			return elem == it.elem;
		}
		bool operator!=(const Iterator& it)
		{
			return elem != it.elem;
		}
		void operator++(){++elem;}
		void operator--(){--elem;}
		int& operator*() const {return *elem;}
};

class Plenty
{
private:
	int size; // размер множества
	int* data; // указатель на динамический массив значений множества
	Iterator beg;
	Iterator end;
public:
	Plenty(int s, int k = 0)
	{
		size = s;
		data = new int[size];
		for (int i = 0; i < size; i++)
			data[i] = k;
		beg.elem = &data[0];
		end.elem = &data[size];
	}
	Plenty(const Plenty& a)
	{
		size = a.size;
		data = new int[size];
		for(int i = 0; i < size; i++)
			data[i] = a.data[i];
		beg = a.beg;
		end = a.end;
	}
	~Plenty()
	{
		delete [] data;
	}
	Plenty& operator=(const Plenty& a)
	{
		data = new int[size];
		beg = a.beg;
		end = a.end;
		for(int i = 0; i < size; i++)
			data[i] = a.data[i];
		return *this;
	}
	int& operator[](int index)
	{
		return data[index];
	}
	Plenty& operator-(const Plenty&a)
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
	Iterator first(){return beg;}
	Iterator las(){return end;}
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
	Plenty a(2);
	cout << "Plenty a" << endl;
	cin >> a;
	Plenty a1(5, 7);
	cout << "Plenty a1 : " << a1 << endl;
	int b = a[4];
	Plenty c = a1-a;
	cout << "a1 - a = " << c << endl;
	cout << "Iterator var = " << *(a.first()) << endl;
	Iterator i = a.first();
	++i;
	cout << "++i = " << *i << endl;
	--i;
	cout << "--i = " << *i << endl;
	return 0;
}