#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Входные данные
    string pattern, text;
    cin >> pattern >> text;

    // Хеш pattern
    long long hp = 0;
    for (int i = 0; i < pattern.size(); ++i) {
        hp += pattern[i];
    }

    // Хеши text
    vector<long long> pos;
    pos.reserve(text.size() - pattern.size() + 1);

    for (int i = 0; i < text.size() - pattern.size() + 1; ++i) {
        long long temp = 0;
        if (i) {
            temp = pos.back() - text[i-1] + text[i + pattern.size() - 1];
        } else {
            int j = i;
            while (j < i + pattern.size()) {
                temp += text[j];
                j++;
            }
        }
        pos.push_back(temp);
    }

    // Проверка
    for (int i = 0; i < pos.size(); ++i) {
        if (pos[i] == hp) {
            int j = i;
            int k = 0;
            while (j < i + pattern.size() && text[j] == pattern[k]) {
                j++;
                k++;
            }
            if (k == pattern.size()) {
                cout << i << " ";
            }
        }
    }

    return 0;
}