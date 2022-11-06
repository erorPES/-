#include <iostream>
#include <fstream>
using namespace std;

int main() {
	// записываем данные из массива в файл
	fstream fs;
	string path = "mfile.txt";
	fs.open(path,fstream::in | fstream:: out);
	if (!fs.is_open()){
		cout << "error to open file" << endl;	
		}
	else{
		cout << "file //mfile.txt// open" << endl;
		cout << endl << "Vostanovlennui spisok: " << endl;
		string str;
		while (!fs.eof()){
			str = "";
			getline (fs, str);
			cout << str << endl;
		}
	}
	
	
	fs.close();
	
    return 0;
}