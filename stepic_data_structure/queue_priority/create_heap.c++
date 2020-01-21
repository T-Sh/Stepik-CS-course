#include <iostream>
#include <vector>

using namespace std;

vector<int> tree;
vector<pair<int, int>> pairs;

void lift_down(int pos) {
    int max_index = pos;

    int left = 2*pos+1;
    if (left < tree.size() && tree[left] < tree[max_index]) {
        max_index = left;
    }

    int right = 2*pos+2;
    if (right < tree.size() && tree[right] < tree[max_index]) {
        max_index = right;
    }

    if (pos != max_index) {
        swap(tree[pos], tree[max_index]);
        pair<int, int> pair;
        pair.first = max_index;
        pair.second = pos;
        pairs.push_back(pair);
        lift_down(max_index);
    }
}

int main() {
    int n;
    cin >> n;
    tree.reserve(n);

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        tree.push_back(temp);
    }

    for (int k = n/2; k >= 0; k--) {
        lift_down(k);
    }

    cout << pairs.size() << endl;

    for (auto & pair : pairs) {
        cout << pair.second << " " << pair.first << endl;
    }

    return 0;
}