#include <iostream>
#include "Event.h"
using namespace std; 

class Object
{
public:
	Object() {};
	virtual void Show() = 0;
	virtual void Input() = 0;
	~Object() {};
	virtual string GetName() = 0;
};

class Print : public Object
{
protected:
	string name;
	string author;
public:
	Print() : name("-"), author("-") {};
	Print(string n, string a) : name(n), author(a){};
	Print (const Print& p)
	{
		name = p.name;
		author = p.author;
	}
	void SetName(string n)
	{
		name = n;
	}
	void SetAuthor(string a)
	{
		author = a;
	}
	string GetName(){return name;}
	string GetAuthor(){return author;}
	Print& operator=(const Print&p)
	{
		name = p.name;
		author = p.author;
		return *this;
	}
	void Show()
	{
		cout << "NAME: " << name << endl;
		cout << "AUTHOR: " << author << endl;
	}
	void Input()
	{
		cout << "Name = "; cin >> name;
		cout << "Author = "; cin >> author;
	}
};

class Magazine : public Print
{
protected:
	int pages;
public:
	Magazine() : Print()
	{
		pages = 0;
	}
	Magazine(string n, string a, int p) : Print(n, a)
	{
		pages = p;
	}
	Magazine(const Magazine& m)
	{
		name = m.name;
		author = m.author;
		pages = m.pages;
	}
	void SetPages(int p)
	{
		pages = p;
	}
	string GetName(){return name;}
	string GetAuthor(){return author;}
	Magazine& operator=(const Magazine& m)
	{
		name = m.name;
		author = m.author;
		pages = m.pages;
		return *this;
	}
	void Show()
	{
		cout << "NAME: " << name << endl;
		cout << "AUTHOR: " << author << endl;
		cout << "PAGES: " << pages << endl;
	}
	void Input()
	{
		cout << "Name = "; cin >> name;
		cout << "Author = "; cin >> author;
		cout << "Pages = "; cin >> pages;
	}
	~Magazine(){};
};

class List
{
protected:
	Object** beg;
	int size;
	int cur;
public:
	List()
	{
		beg = 0;
		size = 0;
		cur = 0;
	}
	List(int n)
	{
		beg = new Object*[n];
		cur = 0;
		size = n;
	}
	List (const List& l)
	{
		cur = 0; size = l.size;
		for (int i = 0; i < size; i++)
			beg[i] = l.beg[i];
	}
	~List()
	{
		delete [] beg;
	}
	void GetName()
	{
		Object** p = beg;
		for(int i = 0; i < cur; i++)
		{
			(*p)->GetName();
			p++;
		}
	}
	void Add()
	{
		Object* p;
		cout << "1. Print\n2. Magazine" << endl;
		int y; cin >> y;
		if (y == 1)
		{
			Print* a = new Print;
			a->Input();
			p = a;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else
			if (y == 2)
			{
				Magazine* b = new Magazine;
				b->Input();
				p = b;
				if (cur < size)
				{
					beg[cur] = p;
					cur++;
				}
			}
	}
	void Show()
	{
		if (cur == 0) cout << "Empty" << endl;
		Object**p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->Show();
			p++;
		}
		cout << endl;
	}
	int operator() ()
	{
		return cur;
	}
	void Del()
	{
		if (cur == 0) return;
		cur--;
	}
};

class Dialog : public List
{
protected:
	int EndState;
public:
	Dialog(void);
	~Dialog(){};
	void GetEvent (TEvent &event);
	void Execute();
	void HandleEvent(TEvent& event);
	void ClearEvent (TEvent& event);
	bool Valid();
	void EndExec();
};
Dialog::Dialog(void) : List()
{
	EndState = 0;
}
void Dialog::GetEvent (TEvent &event)
{
	string OpInt = "m+-szq";
	string s;
	char code;
	cout << '>';
	cin >> s; code = s[0];
	if (OpInt.find(code) >= 0)
	{
		event.what = evMessage;
		switch (code)
		{
			case 'm': event.command = cmMake; break;
			case '+': event.command = cmAdd; break;
			case '-': event.command = cmDel; break;
			case 's': event.command = cmShow; break;
			case 'z': event.command = cmGet; break;
			case 'q': event.command = cmQuit; break;
		}
	}
	else event.what = evNothing;
}
void Dialog::Execute()
{
	TEvent event;
	do
	{
		EndState = 0;
		GetEvent(event);
		HandleEvent(event);
	} while (Valid());
}
void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch(event.command)
		{
			case cmMake: 
				cout << "Input size: ";
				cin >> size;
				beg = new Object*[size];
				cur = 0;
				ClearEvent(event); break;
			case cmAdd: Add();
				ClearEvent(event); break;
			case cmDel:Del();
				ClearEvent(event); break;
			case cmShow:Show();
				ClearEvent(event); break;
			case cmQuit: EndExec();
				ClearEvent(event); break;
			case cmGet: GetName();
				ClearEvent(event); break;
		};
	};
}
void Dialog::ClearEvent (TEvent& event)
{
	event.what = evNothing;
}
bool Dialog::Valid()
{
	return EndState == 0;
}
void Dialog::EndExec()
{
	EndState = 1;
}

int main()
{
	setlocale(0, "");
	cout << "m: make group\n+: Add elem\n-: Delete elem\ns: info\nq: bb" << endl;
	Dialog D;
	D.Execute();
	return 0;
}