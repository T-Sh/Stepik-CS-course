#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> parents;
    cin >> n;

    parents.reserve(n);

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        parents.push_back(temp);
    }

    int max = 0, height;

    for (int j = 0; j < n; ++j) {
        int i = j;
        height = 1;
        while (parents[i] != -1) {
            i = parents[i];
            height++;
        }
        if (height > max)
            max = height;
    }

    cout << max;

    return 0;
}