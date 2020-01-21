#include <iostream>
#include <vector>

using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    void made_set(int i) {
        parent.push_back(i);
        rank.push_back(0);
    }

    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]);
        return parent[i];
    }

    void new_union(int i, int j) {
        int i_id = find(i), j_id = find(j);
        if (i_id == j_id)
            return;
        parent[j_id] = parent[i_id];
    }

    bool check(int p, int q) {
        return find(p) != find(q);
    }

};

int main() {
    int n, e, d;
    cin >> n >> e >> d;

    DSU dsu;
    for (int i = 0; i < n; ++i) {
        dsu.made_set(i);
    }

    for (int k = 0; k < e; ++k) {
        int i, j;
        cin >> i >> j;
        dsu.new_union(i-1, j-1);
    }

    bool check = true;

    for (int l = 0; l < d; ++l) {
        int p, q;
        cin >> p >> q;
        check = (check && dsu.check(p-1, q-1));
    }

    cout << check;

    return 0;
}