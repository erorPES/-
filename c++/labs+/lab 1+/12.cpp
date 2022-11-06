#include <iostream>

using namespace std;

int main()
{
    double n;
    double m;
    cout << "vvedite n ";
    cin >> n;
    cout << "vvedite m ";
    cin >> m;
    cout << " virajenie: --m-++n = " << (--m - ++n) << endl;
    cout << " virajenie: m*n<n++ = " << (m * n < n++) << endl;
    cout << " virajenie: n-->m++ = " << (n-- > m++);
    cout << "\n";
    return 0;
}