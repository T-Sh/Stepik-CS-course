#include<iostream>
#include <vector>

using namespace std;

int main() {
    int W, n;
    cin >> W >> n;
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    vector<vector<int> > table;
    table.reserve(n+1);
    for (int i = 0; i < n+1; ++i) {
        vector<int> temp;
        temp.reserve(W+1);
        for (int j = 0; j < W+1; ++j) {
            temp.push_back(0);
        }
        table.push_back(temp);
    }

    for (int i = 1; i < n+1; ++i) {
        for (int j = 1; j < W+1; ++j) {
            table[i][j] = table[i-1][j];
            if (j >= w[i-1]) {
                table[i][j] = max(table[i][j], table[i-1][j-w[i-1]] + w[i-1]);
            }
        }
    }

    for (int i = 0; i < n+1; ++i) {
        for (int j = 0; j < W+1; ++j) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    cout << table[n][W];

    return 0;
}