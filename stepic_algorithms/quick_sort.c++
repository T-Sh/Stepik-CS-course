#include <iostream>
#include <vector>

using namespace std;

class Point {
public:
    int left, right;
    int last = -1;
};

vector<Point*> segments;
vector<Point*> checks;

int partition_left(int l, int r) {
    int temp = segments[l]->left;
    int j = l;
    for (int i = l+1; i < r; ++i) {
        if (segments[i]->left <= temp) {
            j++;
            swap(segments[i], segments[j]);
        }
    }
    swap(segments[l], segments[j]);
    return j;
}

int partition_right(int l, int r) {
    int temp = checks[l]->right;
    int j = l;
    for (int i = l+1; i < r; ++i) {
        if (checks[i]->right <= temp) {
            j++;
            swap(checks[i], checks[j]);
        }
    }
    swap(checks[l], checks[j]);
    return j;
}

void quick_sort_left(int l, int r) {
    if (l >= r)
        return;
    int m = partition_left(l, r);
    quick_sort_left(l, m-1);
    quick_sort_left(m+1, r);
}

void quick_sort_right(int l, int r) {
    if (l >= r)
        return;
    int m = partition_right(l, r);
    quick_sort_right(l, m-1);
    quick_sort_right(m+1, r);
}

int search(int value) {
    int l = 0, r = segments.size();
    int count = 0;
    while (l <= r) {
        int middle = (l + r) / 2;
        if (segments[middle]->left > value) {
            return count;
        } else if (segments[middle]->left <= value) {
            if (segments[middle]->right >= value)
                count++;
            r = middle-1;
        } else {
            l = middle+1;
        }
    }
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    segments.reserve(n);
    checks.reserve(n);

    for (int i = 0; i < n; i++) {
        auto *point = new Point;
        cin >> point->left >> point->right;
        segments.push_back(point);
        checks.push_back(point);
    }

    quick_sort_left(0, n);
    quick_sort_right(0, n);

    for (auto segment : segments) {
        cout << segment->left << " " << segment->right << endl;
    }
    cout << endl;

    for (auto check : checks) {
        cout << check->left << " " << check->right << endl;
    }
    cout << endl;

    for (int i = 0; i < m; ++i) {
        int point;
        cin >> point;
        int j = 0;
        int count = 0;
        while (j < segments.size() && point >= segments[j]->left) {
            segments[j]->last = point;
            j++;
        }
        j = 0;
        while (j < checks.size() && point <= checks[j]->right) {
            if (checks[j]->last == point) {
                count++;
            }
            j++;
        }
        cout << count << " ";
    }

    return 0;
}