#include <iostream>
#include <vector>

using namespace std;

// List of pair, first - value, second - list of children
vector<pair<int, vector<int>>> tree;

void pre_order(int n) {
    cout << tree[n].first << " ";
    if (tree[n].second[0] != -1)
        pre_order(tree[n].second[0]);
    if (tree[n].second[1] != -1)
        pre_order(tree[n].second[1]);
}

void in_order(int n) {
    if (tree[n].second[0] != -1) {
        in_order(tree[n].second[0]);
    }
    cout << tree[n].first << " ";
    if (tree[n].second[1] != -1) {
        in_order(tree[n].second[1]);
    }
}

void post_order(int n) {
    if (tree[n].second[0] != -1)
        post_order(tree[n].second[0]);
    if (tree[n].second[1] != -1)
        post_order(tree[n].second[1]);
    cout << tree[n].first << " ";
}

int main() {
    int n;
    cin >> n;
    tree.reserve(n);

    for (int i = 0; i < n; ++i) {
        int key, left, right;
        cin >> key >> left >> right;
        vector<int> temp;
        temp.push_back(left);
        temp.push_back(right);
        tree.emplace_back(key, temp);
    }

    in_order(0);
    cout << endl;

    pre_order(0);
    cout << endl;

    post_order(0);
    cout << endl;

    return 0;
}