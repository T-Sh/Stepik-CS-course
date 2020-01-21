#include <iostream>
#include <queue>

using namespace std;

int main() {
    int size, n, count = 0, time = 0;
    cin >> size >> n;
    queue < int > cash;

    for (int i = 0; i < n; ++i) {
        int arrival, duration;
        cin >> arrival >> duration;
        if (count < size) {
            count++;
            if (cash.empty()) {
                cash.push(arrival + duration);
                cout << arrival << endl;
                time = cash.front();
            } else {
                if (arrival >= time) {
                    time += (arrival - time);
                }
                cout << time << endl;
                time += duration;
                cash.push(time);
            }
        } else {
            if (arrival >= cash.front()) {
                cash.pop();
                if (arrival >= time) {
                    time += (arrival - time);
                }
                cout << time << endl;
                time += duration;
                cash.push(time);
            } else
                cout << -1 << endl;
        }
    }

    return 0;
}