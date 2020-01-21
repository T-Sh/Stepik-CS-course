#include <iostream>
#include <stack>

using namespace std;

int main() {
    string command;
    stack < pair<int, int> > stack;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> command;
        if (command == "push") {
            pair <int, int> pair;
            cin >> pair.first;
            if (!stack.empty()) {
                if (stack.top().second > pair.first) {
                    pair.second = stack.top().second;
                } else {
                    pair.second = pair.first;
                }
            } else {
                pair.second = pair.first;
            }
            stack.push(pair);
        } else if (command == "pop") {
            stack.pop();
        } else if (command == "max") {
            cout << stack.top().second << endl;
        }
    }
    return 0;
}