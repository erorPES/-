#include <iostream>
#include <cmath>

using namespace std;
int main()
{

    short a = 1000;
    float b = 0.0001, c, d, e, f, g;
    c = pow((a - b), 3);
    d = pow(a, 3);
    e = pow(a, 2);
    f = pow(b, 3);
    g = pow(b, 2);
    cout << (c - (d - 3 * e * b)) / (f - 3 * a * g) << endl;
    return 0;
}
