#include <iostream>
#include <vector>

using namespace std;

vector<pair<long , int>> processors;

void lift_down(int pos) {
    int max_index = pos;

    int left = 2*pos+1;
    if (left < processors.size() && processors[left].first <= processors[max_index].first) {
        if (processors[left].first == processors[max_index].first) {
            if (processors[left].second < processors[max_index].second) {
                max_index = left;
            }
        } else {
            max_index = left;
        }
    }

    int right = 2*pos+2;
    if (right < processors.size() && processors[right].first <= processors[max_index].first) {
        if (processors[right].first == processors[max_index].first) {
            if (processors[right].second < processors[max_index].second) {
                max_index = right;
            }
        } else {
            max_index = right;
        }
    }

    if (pos != max_index) {
        swap(processors[pos], processors[max_index]);
        lift_down(max_index);
    }
}

void change_priority(int pos, long new_p) {
    processors[pos].first += new_p;
    lift_down(pos);
}

int main() {
    int n, m;
    cin >> n >> m;

    processors.reserve(n);

    for (int i = 0; i < n; ++i) {
        pair<long, int> pair;
        // first - time
        // second - number of processor
        pair.first = 0;
        pair.second = i;
        processors.push_back(pair);
    }

    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        cout << processors[0].second << " " << processors[0].first << endl;
        change_priority(0, t);
    }

    return 0;
}