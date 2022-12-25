#include <iostream>
#include <math.h>
using namespace std;

class Time
{
public:

Time(int x, int y) { first = x; second = y; }

double minutes() { return second = second + (first * 60); }

private:

int first, second;
};

int main()
{
int x, y;
cout << "Vvedite snachala chasu, potom minuti" << endl;
cin >> x >> y;
Time t(x, y);
cout << "your time in minutes: " << endl;
cout << t.minutes();

return 0;
}