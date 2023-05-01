#include <iostream>
#include <string>
#include <set>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    string input;
    set<char> zvonkie_soglasnie{ 'б', 'в', 'г', 'д', 'ж', 'з', 'й', 'л', 'м', 'н', 'р'};
    set<char> used_zvonkie_soglasnie;


    getline(cin, input);

    for (size_t i = 0; i < input.length(); i++) {

        size_t start = i;
        //Поиск конца слова
        while (i < input.length() && input[i] != ',' && input[i] != '.') {
            i++;
        }

        string word = input.substr(start, i - start);

        // Поиск звонких согласных букв в текущем слове
        set<char> word_zvonkie_soglasnie;
        for (char c : word) {
            if (zvonkie_soglasnie.count(c)) {
                word_zvonkie_soglasnie.insert(c);
            }
        }
        used_zvonkie_soglasnie.insert(word_zvonkie_soglasnie.begin(), word_zvonkie_soglasnie.end());
    }

   
    for (char c : used_zvonkie_soglasnie) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
