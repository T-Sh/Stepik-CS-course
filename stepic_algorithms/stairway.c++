#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a (n+1);
    a[0] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i+1];
    }

    for (int i = 2; i < n+1; ++i) {
        a[i] += max(a[i-1], a[i-2]);
    }

    cout << a[n];
    return 0;
}