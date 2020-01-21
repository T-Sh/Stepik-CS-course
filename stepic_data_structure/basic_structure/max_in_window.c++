#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> vector;
    vector.reserve(n);

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        vector.push_back(num);
    }

    cin >> m;

    if (m == 1) {
        for (int i = 0; i < n; ++i) {
            cout << vector[i] << " ";
        }
        return 0;
    }

    stack<pair<int, int> > stack_l, stack_r;

    for (int i = 0; i < m; ++i) {
        pair<int, int> pair;
        pair.first = vector[i];
        if (stack_l.empty())
            pair.second = vector[i];
        else
            pair.second = max(vector[i], stack_l.top().second);
        stack_l.push(pair);
    }

    cout << stack_l.top().second << " ";

    for (int j = m; j < n; ++j) {

        if (stack_r.empty()) {
            while (!stack_l.empty()) {
                pair<int, int> pair;
                pair.first = stack_l.top().first;
                if (stack_r.empty())
                    pair.second = stack_l.top().first;
                else
                    pair.second = max(stack_r.top().second, stack_l.top().first);
                stack_r.push(pair);
                stack_l.pop();
            }
        }
        pair<int, int> pair;
        pair.first = vector[j];
        if (stack_l.empty())
            pair.second = vector[j];
        else
            pair.second = max(vector[j], stack_l.top().second);
        stack_l.push(pair);
        stack_r.pop();

        if (stack_l.empty() || stack_r.empty()) {
            cout << (stack_l.empty() ? stack_r.top().second : stack_l.top().second) << " ";
        } else {
            cout << max(stack_l.top().second, stack_r.top().second) << " ";
        }

    }

    return 0;
}