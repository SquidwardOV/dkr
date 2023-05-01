#include <iostream>
#include <string>
#include <set>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    string input;
    set<char> soglasnie{ 'б', 'в', 'г', 'д', 'ж', 'з', 'к', 'л', 'м', 'н', 'п', 'р', 'с', 'т', 'ф', 'х', 'ц', 'ч', 'ш', 'щ' };
    set<char> used_soglasnie;


    getline(cin, input);


    for (size_t i = 0; i < input.length(); i++) {

        size_t start = i;
        // Поиск конца слова
        while (i < input.length() && input[i] != ',' && input[i] != '.') {
            i++;
        }

        string word = input.substr(start, i - start);

        // Поиск согласных букв в текущем слове
        set<char> word_soglasnie;
        for (char c : word) {
            if (soglasnie.count(c)) {
                word_soglasnie.insert(c);
            }
        }
        used_soglasnie.insert(word_soglasnie.begin(), word_soglasnie.end());
    }

    // Поиск согласных букв, которые не входят ни в одно слово
    set<char> unused_soglasnie;
    for (char c : soglasnie) {
        if (!used_soglasnie.count(c)) {
            unused_soglasnie.insert(c);
        }
    }


    for (char c : unused_soglasnie) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
