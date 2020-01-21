#include <iostream>
#include <vector>

using namespace std;

// Сравниваем текущий узел с предыдущим, проверка c для первого элемента

// List of pair, first - value, second - list of children
vector<pair<int, vector<long>>> mas;
bool t = true;
bool c = false;
int previous = 0;

void in_order(int n) {
    if (mas[n].second[0] != -1) {
        in_order(mas[n].second[0]);
    }
    if (c) {
        t = t && previous < mas[n].first;
    }
    previous = mas[n].first;
    c = true;
    if (mas[n].second[1] != -1) {
        in_order(mas[n].second[1]);
    }
}

int main() {
    int n;
    cin >> n;
    mas.reserve(n);

    for (int i = 0; i < n; ++i) {
        int left, right;
        long key;
        cin >> key >> left >> right;
        vector<int> temp;
        temp.push_back(left);
        temp.push_back(right);
        mas.emplace_back(key, temp);
    }

    if (!mas.empty())
        in_order(0);

    cout << (t ? "CORRECT" : "INCORRECT") << endl;

    return 0;
}