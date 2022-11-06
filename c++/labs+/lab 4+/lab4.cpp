#include <iostream>
#include <stdlib.h>

using namespace std; 

int main(){
    int i;
    int mas[10];
    for (i = 0; i < 10; i++)			// заполняем и выводим начальный массив в столбик
        mas[i] = rand() % 10; 
    for (i = 0; i < 10; i++){
        cout << mas[i] << " " << endl;
	}
cout << endl;	
    for (i = 0; i < 10; i++) 			//совершаем над массивом необходивые манипуляции и выводим его в сточку  
    {
        if (mas[i] % 7 != 0)
            cout << mas[i] << " "; 
        if (mas[i] % 2 != 0)
            cout << "0 "; 
    }
return 0;
}