#include <iostream>
using namespace std;
 
int main()
{
    int razm;
 
    cout << "vvedite razmer storon kvadrata: ";
    cin >> razm;
    cout << endl;
 
    for(int i = 0; i < razm; i++)
    {
        for(int j = 0; j < razm; j++)
        {
            if(i==0 || j==0 || i==razm-1 || j==razm-1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
    return 0;
}