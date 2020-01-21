#include <iostream>
#include <vector>

using namespace std;

bool diff(char a, char b) {
    return a != b;
}

int find_edit_dist(const string& A, const string& B) {
    int m = A.size();
    int n = B.size();

    m++;
    n++;
    vector<int> current(n);
    vector<int> prev(n);
    for (int i = 0; i < n; ++i) {
        prev[i] = i;
//        cout << prev[i] << " ";
    }
//    cout << endl;

    for (int i = 1; i < m; ++i) {
        current[0] = i;
        for (int j = 1; j < n; ++j) {
            current[j] = min(current[j-1] + 1,
                    min(prev[j] + 1, prev[j-1] + diff(A[i-1], B[j-1])));
        }

        /*for (int k = 0; k < n; ++k) {
            cout << current[k] << " ";
        }
        cout << endl;*/

        prev = current;
    }

    return current.back();
}

int dist(const string& A, const string& B) {
    int n = A.size();
    int m = B.size();

    m++;
    n++;
    vector<vector<int> > D;
    for (int i = 0; i < n; ++i) {
        vector<int> temp;
        temp.reserve(m);
        for (int j = 0; j < m; ++j) {
            temp.push_back(i == 0 ? j : 0);
        }
        temp[0] = i;
        D.push_back(temp);
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            D[i][j] = min(D[i-1][j] + 1,
                    min(D[i][j-1] + 1, D[i-1][j-1] + diff(A[i-1], B[j-1])));
        }
    }

    /*cout << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << D[i][j] << " ";
        }
        cout << endl;
    }*/

    return D[n-1][m-1];

}

int main() {
    string A, B;
    cin >> A >> B;
    cout << find_edit_dist(A, B);
//    cout << dist(A, B);

    return 0;
}