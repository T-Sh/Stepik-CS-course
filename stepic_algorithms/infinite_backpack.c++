#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef pair <double , double> obj;

bool comp(pair<double , double> a, pair<double , double> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main() {
    int n;
    double W, w, c;
    cin >> n >> W;

    vector<obj> objs(n);

    for (int i = 0; i < n; ++i) {
        cin >> c >> w;
        objs[i].first = c/w;
        objs[i].second = w;
    }

    sort(objs.begin(), objs.end(), comp);

    double price = 0;
    int i = 0;

    while (W > 0 && i <= n) {
        W -= objs[i].second;
        price += objs[i].first * (W >= 0 ? objs[i].second : objs[i].second + W);
        i++;
    }

    cout << fixed << setprecision(3) << price;

    return 0;
}