#include <iostream>
#include <map>

using namespace std;

int main() {
    int k, l;
    cin >> k >> l;
    map<string, char> frequency;
    for (int i = 0; i < k; ++i) {
        char symbol;
        char b;
        string code;
        cin >> symbol >> b >> code;
        frequency.insert({code, symbol});
    }

    string result;
    cin >> result;
    string code;

    for (char i : result) {
        if (frequency.find(code) == frequency.end()) {
            code += i;
        } else {
            cout << frequency[code];
            code = i;
        }
    }
    cout << frequency[code];

    return 0;
}