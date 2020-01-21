#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> B;
    B.reserve(n);
    for (int i = 0; i < 10; ++i) {
        B.push_back(0);
    }

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        B[temp-1]++;
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < B[i]; ++j) {
            cout << i+1 << " ";
        }
    }

    return 0;
}