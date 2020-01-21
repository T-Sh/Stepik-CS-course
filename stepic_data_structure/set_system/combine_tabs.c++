#include <iostream>
#include <vector>

using namespace std;

class DSU
{
private:
    vector<pair<int, int>> parent;
    vector<int> rank;
    int max = 0;

public:
    void make_set(int num, int mean) {
        pair<int, int> pair;
        pair.first = num;
        pair.second = mean;
        parent.push_back(pair);
        rank.push_back(0);
        if (mean > max)
            max = mean;
    }

    int find(int i) {
        if (parent[i].first != i)
            parent[i].first = find(parent[i].first);
        return parent[i].first;
    }

    void Union(int i, int j) {
        int i_id = find(i);
        int j_id = find(j);
        if (i_id == j_id)
            return;
        if (rank[i_id] > rank[j_id]) {
            parent[j_id].first = i_id;
        } else {
            parent[i_id].first = j_id;
            if (rank[i_id] == rank[j_id]) {
                rank[j_id] += 1;
            }
        }
    }

    void new_union(int d, int s) {
        if (d == s)
            return;
        int d_id = find(d), s_id = find(s);
        if (d_id == s_id)
            return;
        parent[d_id].second += parent[s_id].second;
        parent[s_id].second = 0;
        parent[s_id].first = d_id;
        if (parent[d_id].second > max)
            max = parent[d_id].second;

    }

    int find_max() {
        return max;
    }
};


int main() {
    int n, m;
    cin >> n >> m;

    DSU dsu;

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        dsu.make_set(i, temp);
    }

    for (int i = 0; i < m; ++i) {
        int destination, source;
        cin >> destination >> source;
        dsu.new_union(destination - 1, source - 1);
        cout << dsu.find_max() << endl;
    }

    return 0;
}