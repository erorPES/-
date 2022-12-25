#include <iostream>
#include <fstream>
#include <string>  
using namespace std; 

class Person
{
public:
	Person()
	{
	name = ""; age = 0; 
	}
	Person(string N, int A)
	{ 
	name = N; age = A;
	} 
	Person(const Person& p)
	{ 
	name = p.name; age = p.age; 
	}
	Person operator = (const Person& p)
	{ 
	if (&p == this) return *this; 
	name = p.name; 
	age = p.age; 
	return*this; 
	}
	bool operator != (string p)
	{
	
	if (name != p)
		return 1;
	else
		return 0;
	}
	int set()
	{
		return age;
	}
	string set1()
	{
		return name;
	}

friend ostream& operator <<(ostream& out, const Person& p)
{
	out << "Name:" << p.name << " Age:" << p.age << "\n";
	return out;
} 
friend istream& operator>>(istream& in, Person& p) 
{
	cout << "name?"; 
	in >> p.name;

	cout << "age?"; 
	in >> p.age; 
	return in;
}
public:
friend fstream& operator>>(fstream& fin, Person& p)
{
	fin >> p.name; 
	fin >> p.age; 
	return fin;
}
friend fstream& operator <<(fstream& fout, const Person& p)
{
	fout << p.name << "\n" << p.age << "\n";
	return fout;
}
private:
	string name; 
	int age;
};

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc); //открыть для записи 
	if(!stream)return -1;//ошибка открытия файла
	int n;
	Person p;
	cout << "N?"; 
	cin >> n; 
	for (int i = 0; i < n; i++)
	{
		cin >> p;//ввод атрибутов объекта из стандартного потока 
		stream<<p<<"\n";//запись объекта в файловый поток
	}
	stream.close();//закрыть поток
	return n;//вернуть количество записанных объектов
}

int add_file(const char* f_name, int k, Person pp)

{
	fstream temp("temp", ios::out);//открыть для записи 
	fstream stream(f_name,ios::in);//открыть для чтения 
	if(!stream)return -1;//ошибка открытия файла
	Person p; int i = 0, l = 0; while (stream >> p)
	{
		if (stream.eof())break; i++;
		if (i == k)
		{
			temp << pp;//записать в temp новую запись 
			l++;
		}
		temp << p;
	}
	stream.close(); 
	temp.close(); 
	remove(f_name); 
	rename("temp", f_name);
	return l;//количество добавленных
}

int add_end(const char* f_name, Person pp)
{
	fstream stream(f_name, ios::app);//открыть для добавления 
	if(!stream)return -1;//ошибка открытия файла
	stream << pp; //записать новую запись 
	return 1;
}

int change_file(const char* f_name, int k, Person pp)
{
	fstream temp("temp", ios::out);//открыть для записи 
	fstream stream(f_name,ios::in);//открыть для чтения 
	if(!stream)return -1;//ошибка открытия файла
	Person p; 
	int i = 0, l = 0; 
	char x; 
	while (stream >> p)
	{
		if (stream.eof())
			break; 
		i++;
		if (i == k)
		{
			cout << p << " - is changing... Continue[y/n]?\n"; 
			cin >> x;
			if (x == 'n' || x == 'N')break; 
			temp << pp;
			l++;

		}
		else temp << p;
	}
	stream.close(); 
	temp.close(); 
	remove(f_name); 
	rename("temp", f_name);
	return l;//количество измененных элементов
}

int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);//открыть для чтения 
	if(!stream)return -1;//ошибка открытия файла
	Person p; 
	int i = 0; 
	while (stream >> p)
	{
		cout << p << "\n"; 
		i++;
	}
	stream.close();
	return i;
}

int del_file(const char* f_name, int k)
{
	fstream temp("temp", ios::out);//открыть для записи 
	fstream stream(f_name,ios::in);//открыть для чтения 
	if(!stream)return -1;//ошибка открытия файла
	int i = 0; 
	Person p;
	while (stream >> p)//пока нет конца файла выполняем чтение объекта
	{
		//если прочитан признак конца файла,то выход из цикла 
		if (stream.eof())
			break;
		i++;
		//если номер объекта не равен k, то записываем его во вспомогательый файл 
		if(i!=k) 
			temp<<p;
	}
	//закрыть файлы 
	stream.close(); 
	temp.close();
	remove(f_name);//удалить старый файл 
	rename("temp", f_name);// переименовать temp 
	return i;//количество прочитанных
}


int del(const char* f_name, string k)
{
	fstream temp("temp", ios::out);//открыть для записи 
	fstream stream(f_name, ios::in);//открыть для чтения 
	if (!stream)return -1;//ошибка открытия файла
	int i = 0; Person p;
	while (stream >> p)//пока нет конца файла выполняем чтение объекта
	{
		//если прочитан признак конца файла,то выход из цикла 
		if (stream.eof())
			break;
		i++;
		//если номер объекта не равен k, то записываем его во вспомогательый файл 
		if (p != k)
			temp << p;
	}
	//закрыть файлы 
	stream.close();
	temp.close();
	remove(f_name);//удалить старый файл 
	rename("temp", f_name);// переименовать temp 
	return i;//количество прочитанных
}

int sort(const char* f_name)
{
	fstream temp("temp", ios::out);//открыть для записи 
	fstream stream(f_name, ios::in);//открыть для чтения 
	if (!stream)return -1;//ошибка открытия файла
	Person p;
	int i = 0;
	int* pm = new int;
	string* qm = new string;
	while (stream >> p)
	{
		pm[i] = p.set();
		qm[i] = p.set1();
		i++;
	}
	for (int j = 0;i;j++)
		for (int y = 0; i - 1; y++)
		{
			if (pm[j] > pm[j + 1])
			{
				int q = pm[i];
				string q1 = qm[i];
				pm[i] = pm[i + 1];
				qm[i] = qm[i + 1];
				pm[i + 1] = q;
				qm[i + 1] = q1;
			}
		}
	for (int j = 0; i; j++)
	{
		cout << qm[i] << ' ' << pm[i];
	}
	delete(pm);
	delete(qm);
	stream.close();
	temp.close();
	remove(f_name);//удалить старый файл 
	rename("temp", f_name);// переименовать temp
	return i;
}

int main()
{
	Person p, p1, p2; int k, c;
	char file_name[30]; 
	do
	{	//Μενώ
		cout << "\n1. Make file";
		cout << "\n2. Print file";
		cout << "\n3. Delete record by number from file"; 
		cout << "\n4. Add record to file"; 
		cout << "\n5. Change record in file";
		cout << "\n6. Delet record by key from file";
		cout << "\n7. Sort";
		cout << "\n0. Exit\n";
		cin >> c;
		string y;
		switch (c)
		{
		case 1: 
			cout << "file name?"; 
			cin >> file_name; 
			k = make_file(file_name);
			if (k < 0)cout << "Can't make file";
			break;
		case 2: cout << "file name?";
			cin >> file_name; 
			k = print_file(file_name); 
			if (k == 0)
				cout << "Empty file\n"; 
			if (k < 0)
				cout << "Can't read file\n";

			break;
		case 3: 
			cout << "file name?"; 
			cin >> file_name; 
			int nom; 
			cout << "nom?"; 
			cin >> nom; 
			k = del_file(file_name, nom); 
			if (k < 0)cout << "Can't read file"; 
			break;
		case 4: 
			cout << "file name?"; 
			cin >> file_name; 
			cout << "nom?"; 
			cin >> nom; 
			cout << "New person:";
			//Person p1; 
			cin>>p1;
			k = add_file(file_name, nom, p1); 
			if (k < 0) 
				cout << "Can't read file"; 
			if (k == 0) 
				k = add_end(file_name, p1); 
			break;
		case 5: 
			cout << "file name?"; 
			cin >> file_name; 
			cout << "nom?"; 
			cin >> nom; 
			cout << "New person:";
			//Person p2; 
			cin>>p2;
			k = change_file(file_name, nom, p2); 
			if (k < 0) 
				cout << "\nCan't read file"; 
			if (k == 0) 
				cout << "\nNot such record"; 
			break;
		case 6:
			cout << "file name?";
			cin >> file_name;
			cout << "name?";
			cin >> y;
			k = del(file_name, y);
			if (k < 0)cout << "Can't read file";
			break;
		case 7:
			cout << "file name?";
			cin >> file_name;
			k = sort(file_name);
			if (k < 0)
				cout << "\nCan't read file";
			if (k == 0)
				cout << "\nNot such record";
			break;
		}
	} while (c != 0);
return 0;
}