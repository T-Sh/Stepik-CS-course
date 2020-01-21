#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> S;
    std::vector<std::vector<int>> path(n + 1, std::vector<int>());
    S.push_back(0);
    S.push_back(0);
    path[1].push_back(1);
    for (int i = 2; i <= n; ++i) {
        int x3 = INT32_MAX;
        if ((i % 3) == 0)
            x3 = S[i / 3] + 1;
        int x2 = INT32_MAX;
        if ((i % 2) == 0)
            x2 = S[i / 2] + 1;
        int minim = min({ x3, x2, S[i - 1] + 1 });
        S.push_back(minim);
        if (minim == x3) {
            path[i] = path[i / 3];
            path[i].push_back(i);
        }
        if (minim == x2) {
            path[i] = path[i / 2];
            path[i].push_back(i);
        }
        if (minim == S[i - 1] + 1) {
            path[i] = path[i - 1];
            path[i].push_back(i);
        }
    }
    cout << S[n] << endl;
    for (auto elem : path[n])
        cout << elem << " ";
    cout << endl;
    return 0;
}