#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    unsigned int n;
    cin >> n;

    double temp = (-1.0 + sqrt(1.0 + 8.0 * ((double)n))) / 2.0;
    auto k = (unsigned int)temp;
    cout << k << endl;

    for (unsigned int i = 1; i <= k-1; ++i) {
        cout << i << " ";
    }
    cout << n - (k - 1) * k / 2;

    return 0;
}