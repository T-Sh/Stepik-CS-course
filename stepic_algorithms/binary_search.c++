#include <iostream>
#include <vector>

using namespace std;

vector<int> mas;

int search(int value) {
    int l = 0, r = mas.size();
    while (l <= r) {
        int middle = (l + r) / 2;
        if (mas[middle] == value) {
            return middle + 1;
        } else if (mas[middle] > value) {
            r = middle-1;
        } else {
            l = middle+1;
        }
    }
    return -1;
}

int main() {
    int n, k;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        mas.push_back(temp);
    }

    cin >> k;
    for (int i = 0; i < k; ++i) {
        int temp;
        cin >> temp;
        cout << search(temp) << " ";
    }

    return 0;
}