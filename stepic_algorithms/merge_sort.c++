#include <iostream>
#include <vector>

using namespace std;
unsigned long long merges = 0;

vector<long> merge(vector<long> left, vector<long> right) {
    vector<long> final;
    cout << "left ";
    for (int i = 0; i < left.size(); ++i) {
        cout << left[i] << " ";
    }
    cout << endl << "right ";
    for (int i = 0; i < right.size(); ++i) {
        cout << right[i] << " ";
    }
    int l = 0, r = 0;
    while (l < left.size() || r < right.size()) {
        if (r == right.size()) {
            final.push_back(left[l]);
            l++;
        } else if (l < left.size() && left[l] <= right[r]) {
            final.push_back(left[l]);
            l++;
        } else if (l < left.size() && right[r] < left[l]) {
            final.push_back(right[r]);
            r++;
            merges += left.size() - l;
        } else {
            final.push_back(right[r]);
            r++;
        }
    }
    cout << " m = " << merges << endl;
    return final;
}

vector<long> mergeSort(vector<long> mas) {
    if (mas.size() == 1)
        return mas;
    vector<long> left;
    for (int i = 0; i < mas.size()/2; ++i) {
        left.push_back(mas[i]);
    }
    vector<long> right;
    for (int i = mas.size()/2; i < mas.size(); ++i) {
        right.push_back(mas[i]);
    }
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
}

int main() {
    int n;
    cin >> n;
    vector<long> mas;

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        mas.push_back(temp);
    }

    mas = mergeSort(mas);

    for (int i = 0; i < n; ++i) {
        cout << mas[i] << " ";
    }

    cout << endl << merges;

    return 0;
}