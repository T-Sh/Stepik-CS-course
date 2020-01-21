#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    vector<long> D(n+1);
    vector<int> pos(n);
    vector<int> prev(n);

    pos[0] = -1;
    int length = 0;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        D[i+1] = INT32_MAX;
    }
    D[0] = -1;

    for (int i = n-1; i >= 0; i--) {
        int j = int(upper_bound(D.begin(), D.end(), A[i]) - D.begin());
        if (D[j-1] <= A[i] && A[i] <= D[j]) {
            D[j] = A[i];
            pos[j] = i;
            prev[i] = pos[j - 1];
            length = max(length, j);
        }
    }
    cout << length << endl;

    vector<int> answer;
    int p = pos[length];
    while (p > -1) {
        answer.push_back(p);
        p = prev[p];
    }

    for (int i : answer) {
        cout << i+1 << " ";
    }

    return 0;
}