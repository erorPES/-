#include <iostream>

using namespace std;

int main(){
    int sum = 0;
    int square = 0;
    const int n = 3;
    int a[n][n];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << "pazjalyista, vvedite elementi matrici a[" << i << "][" << j << "] ";
            cin >> a[i - 1][j - 1];
            cout << endl;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                if (k != i){
                    sum += a[i][j] * a[k][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            square += a[i][j] * a[i][j];
        }
    }
	
    if (sum > 0 || square != 3){
        cout << "matricsa ne ortonormirovanna" << endl;
    }
    else{
        cout << "matricsa ortonormirovanna" << endl;
    }
    return 0;
}