#include <iostream>
#include <stack>

using namespace std;

int main() {
    string s;
    cin >> s;
    stack<pair<int, int> > sk;
    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];

        if (c != '[' && c!= '(' && c!= '{' && c!= ']' && c != ')' && c != '}') {
            continue;
        }

        pair<int, int> p;
        p.second = i+1;

        if (c == '[' || c == '(' || c == '{') {
            if (c == '[') {
                p.first = 0;
                sk.push(p);
            }
            else if (c == '(') {
                p.first = 1;
                sk.push(p);
            }
            else {
                p.first = 2;
                sk.push(p);
            }
        } else if ((c == ']' || c == ')' || c == '}') && sk.empty()) {
            cout << i+1;
            return 0;
        } else {
            if ((c == ']' && sk.top().first == 0) ||
                (c == ')' && sk.top().first == 1) ||
                (c == '}' && sk.top().first == 2)) {
                sk.pop();
            } else {
                cout << i+1;
                return 0;
            }
        }

    }

    if (sk.empty())
        cout << "Success";
    else
        cout << sk.top().second;
    return 0;
}