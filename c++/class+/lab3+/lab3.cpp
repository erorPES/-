#include <iostream>
#include <math.h>
using namespace std;

class Time
{
public:
Time(int x, int y) { minutes = x; second = y; }
friend double minuses(Time &, int minus); 
void get () { 
if ((second == 0) && (minutes !=0)) 
	{
		cout << minutes << ":" << "00" << endl;
	};
if ((minutes == 0) && (second != 0)) 
	{
		cout << "00" << ":" << second << endl;
	}
if ((minutes == 0) && (second == 0))
	{
		cout << "00" << ":" << "00" << endl;
	}
if ((minutes != 0) && (second != 0))
	{
		cout << minutes << ":" << second << endl;
	}
}
const bool operator == (const Time & right){
	if (this->minutes==right.minutes)
		{ 
			if (this->second==right.second)
			{
				return 1;
			}
			else 
			{
				return 0;
			}
		}
	else return 0;
}
const bool operator != (const Time & right){
	if (this->minutes==right.minutes) 
		{
			if (this->second==right.second)
			{
				return 0;
			}
			else 
			{
				return 0;
			}
		}
		else 
			return 1;
}

private:
int minutes, second;
};

double minuses(Time &p, int minus) 
{
int x = minus/60;
int y = minus%60;
if (minus > (p.minutes*60+p.second))
{	
cout << "error, minus time > real time. Time non change" << endl;
}
if ((y>p.second) && (minus <= (p.minutes*60+p.second)))
{
	x=x+1;
	p.second = p.second+60;
}
if (minus <= (p.minutes*60+p.second)){
p.minutes = p.minutes-x;
p.second = p.second-y;
}
return 0; 
}

int main()
{
int x, y, z, p, min, min2;


cout << "Vvedite snachala minutes, potom secundi(Time 1)" << endl;
cin >> x >> y;
if (y>59) {
	while (y>59){
		cout << "second can't be more than 59" << endl;
		cout << "enter second again" << endl;
		cin >> y;
	};
};
Time t(x, y);
cout << "your time : ";
t.get();
cout << "Vvedite snachala minutes, potom secundi(Time 2)" << endl;
cin >> z >> p;
Time t2(z, p);
if (p>59) {
	while (p>59){
		cout << "second can't be more than 59" << endl;
		cout << "enter second again" << endl;
		cin >> p;
	};
};
cout << "your time : ";
t2.get();
cout << "Vvedite na skolko secund umenshit Time 1" << endl;
cin >> min;
minuses (t, min);
cout << "Vvedite na skolko secund umenshit Time 2" << endl;
cin >> min2;
minuses (t2, min2);
t.get();
t2.get();
bool e1, e2;
e1 = (t==t2);
e2 = (t!=t2);
if (e1==1)
{
	cout << "vremena ravni" << endl;
};
if (e1==0)
{
	cout << "vremena ne ravni" << endl;
};
return 0;
}