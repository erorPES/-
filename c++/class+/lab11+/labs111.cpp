#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	setlocale(LC_ALL, "rus");
	map<double, string> map1, map2, map3;

	double sr_b;
	string Name;

	cout << "Введите количество студентов" << endl;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "Введите фамилию и средний балл студента" << endl;
		cin >> Name >> sr_b;
		if (sr_b >= 4.5)
		{
			map1[sr_b] = Name;
		}
		if ((sr_b < 4.5) && (sr_b >= 3.0))
		{
			map2[sr_b] = Name;
		}
		if (sr_b < 3.0)
		{
			map3[sr_b] = Name;
		}
	}


	copy(map1.begin(), map1.end(), inserter(map1, map1.end()));
	copy(map2.begin(), map2.end(), inserter(map2, map2.end()));
	copy(map3.begin(), map3.end(), inserter(map3, map3.end()));

	
	cout << endl << "Отличники: " << endl;
	auto it1 = map1.begin();
	for (; it1 != map1.end(); it1++)
	{
		cout << (it1->first) << ' ' << (it1->second) << endl;
	}
	
	cout << "Хорошисты: " << endl;

	auto it2 = map2.begin();
	for (; it2 != map2.end(); it2++)
	{
		cout << (it2->first) << ' ' << (it2->second) << endl;
	}
	
	cout << "Группа риска: " << endl;

	auto it3 = map3.begin();
	for (; it3 != map3.end(); it3++)
	{
		cout << (it3->first) << ' ' << (it3->second)<<endl;
	}

	return 0;
}