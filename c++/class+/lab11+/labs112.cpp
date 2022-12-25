#include <set>
#include <fstream>

using namespace std;

set<int> Myset;

// Объявляем функцию переноса данных из файла
void LoadFromFile(const string& filename)
{
    std::ifstream input(filename);
    int element;
    while (input >> element)
        Myset.insert(element);
}

// Объявляем функцию переноса четных элементов в файл
void SaveEvenElements(const string& filename)
{
    std::ofstream output(filename);
    for (const auto& element : Myset)
        if (element % 2 == 0)
            output << element << ' ';
}

int main()
{
    LoadFromFile("F1.txt");
    SaveEvenElements("F2.txt");

    return 0;
}