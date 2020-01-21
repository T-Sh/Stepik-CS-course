#include <iostream>
#include <vector>

using namespace std;

// List of pair, first - value, second - list of children
vector<pair<int, vector<int>>> mas;
bool check = true;

void in_order(int n, long long min, long long max) {

    check = check && (mas[n].first >= min && mas[n].first < max);
//    cout << min << " " << mas[n].first << " " << max << endl;
    if (!check)
        return;

    if (mas[n].second[0] != -1) {
        in_order(mas[n].second[0], min, mas[n].first);
    }

    if (mas[n].second[1] != -1) {
        in_order(mas[n].second[1], mas[n].first, max);
    }
}

int main() {
    int n;
    cin >> n;
    mas.reserve(n);

    for (int i = 0; i < n; ++i) {
        int key, left, right;
        cin >> key >> left >> right;
        vector<int> temp;
        temp.push_back(left);
        temp.push_back(right);
        mas.emplace_back(key, temp);
    }

    long long min = (long long) (INT32_MIN) - 1;
    long long max = (long long) (INT32_MAX) + 1;

    if (!mas.empty())
        in_order(0, min, max);

    cout << (check ? "CORRECT" : "INCORRECT") << endl;

    return 0;
}