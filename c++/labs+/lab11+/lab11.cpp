#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    int val;
    Node* next;
	Node(int _val) : val(_val), next(nullptr) {}
};

struct list {
    Node* first;
    Node* last;

    list() : first(nullptr), last(nullptr) {}

    bool is_empty() {
        return first == nullptr;
    }

    void push_back(int _val) {
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void print() {
        if (is_empty()) return;
        Node* p = first;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
	
	Node* operator[] (const int index) {
    if (is_empty()) return nullptr;
    Node* p = first;
    for (int i = 0; i < index; i++) {
        p = p->next;
        if (!p) return nullptr;
    }
    return p;
	}
	
	void remove_first() {
        if (is_empty()) return;
        Node* p = first;
        first = p->next;
        delete p;
    }

    void remove_last() {
        if (is_empty()) return;
        if (first == last) {
            remove_first();
            return;
        }
        Node* p = first;
        while (p->next != last) p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
    }
	
	void remove(int _val) {
    if (is_empty()) return;
    if (first->val == _val) {
        remove_first();
        return;
    }
    else if (last->val == _val) {
    		remove_last();
        return;
    }
    Node* slow = first;
    Node* fast = first->next;
    while (fast && fast->val != _val) {
        fast = fast->next;
        slow = slow->next;
    }
    if (!fast) {
        cout << "This element does not exist" << endl;
        return;
    }
    slow->next = fast->next;
    delete fast;
}
};

int main() {
	list l;
	int ndel;
	int koldel;
	cout << "vvedite kollichestvo elementov spiska" <<endl;
	int qq;
	cin >> qq;
	cout << "vvedite posledovatelno elementi spiska" <<endl;
	int err;
	for (int i=0;i<qq;i++){
		cin >> err;
		l.push_back(err);
	}
	
	cout <<"vash spisok: "<< endl;
    l.print();
	cout << "vvedite nomer elementa s kotorogo udalit elementi" <<endl;
	cin >> ndel;
	cout << "vvedite kollichestvo elementov dlya udaleniua" <<endl;
	cin >> koldel;
	for (int i=0; i<koldel; i++){
		l.remove(ndel+i);
	};
	cout <<"vash spisok: "<< endl;
	l.print();
	int mass [qq-koldel];
	for (int i=0; i<(qq-koldel); i++){
		mass[i]=(l[i]->val);
	}
	// записываем данные из массива в файл
	fstream fs;
	string path = "mfile.txt";
	fs.open(path,fstream::in | fstream:: out);
	if (!fs.is_open()){
		cout << "error to open file" << endl;	
		}
	else{
		cout << "file //mfile.txt// open" << endl;
		cout << "idet zapis v file" << endl;
		for (int i=0; i<(qq-koldel); i++){
		fs << mass[i] << " ";
		fs.flush();	
		}
	}
	fs.close();
	fs.open(path,fstream::in | fstream:: out);
	if (!fs.is_open()){
		cout << "error to open file" << endl;	
		}
	else{
		cout << "file //mfile.txt// open" << endl;
		cout << "chtenie is fila" << endl;
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