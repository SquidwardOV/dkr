#include <iostream>
#include <string>
#include <set>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    string input;
    set<char> glasnie{ 'а', 'е', 'ё', 'и', 'о', 'у', 'ы', 'э', 'ю', 'я' };

    getline(cin, input);


    for (size_t i = 0; i < input.length(); i++) {

        size_t start = i;
        // Поиск конца слова
        while (i < input.length() && input[i] != ',' && input[i] != '.') {
            i++;
        }
        string word = input.substr(start, i - start);

        // Поиск пересечения множества гласных с гласными буквами в текущем слове
        set<char> word_glasnie;
        for (char c : word) {
            if (glasnie.count(c)) {
                word_glasnie.insert(c);
            }
        }
        glasnie = word_glasnie;
    }

    // Печатаем гласные в алфавитном порядке
    for (char c : glasnie) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
