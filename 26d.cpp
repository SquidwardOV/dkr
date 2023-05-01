#include <iostream>
#include <string>
#include <set>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    string input;
    set<char> gluxie_soglasnie{ 'к', 'п', 'с', 'т', 'ф', 'х', 'ц', 'ч', 'ш', 'щ'};
    set<char> used_soglasnie;

  
    getline(cin, input);

  
    for (size_t i = 0; i < input.length(); i++) {
    
        size_t start = i;
        // Поиск конца слова
        while (i < input.length() && input[i] != ',' && input[i] != '.') {
            i++;
        }

        string word = input.substr(start, i - start);

        // Поиск глухих согласных букв, которые входят в текущее слово
        set<char> word_soglasnie;
        for (char c : word) {
            if (gluxie_soglasnie.count(c)) {
                word_soglasnie.insert(c);
            }
        }
        used_soglasnie.insert(word_soglasnie.begin(), word_soglasnie.end());
    }

  
    for (char c : gluxie_soglasnie) {
        if (!used_soglasnie.count(c)) {
            cout << c << " ";
        }
    }
    cout << endl;

    return 0;
}
