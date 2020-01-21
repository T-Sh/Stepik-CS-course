#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
    vector<int> heap;

    // Просеять вверх (при добавлении)
    void sift_up(int pos) {
        if (pos == 0)
            return;
        int parent = (pos - 1) / 2;
        if (heap[pos] > heap[parent]) {
            swap(heap[pos], heap[parent]);
            sift_up(parent);
        }
    }

    // Просеять вниз (при удалении максимума)
    void sift_down(int pos) {
        int max_index = pos;

        int left = 2*pos+1;
        if (left < heap.size() && heap[left] > heap[max_index]) {
            max_index = left;
        }

        int right = 2*pos+2;
        if (right < heap.size() && heap[right] > heap[max_index]) {
            max_index = right;
        }

        if (pos != max_index) {
            swap(heap[pos], heap[max_index]);
            sift_down(max_index);
        }
    }

public:
    void insert(int num) {
        heap.push_back(num);
        sift_up(heap.size() - 1);
    }

    int extract_max() {
        int max = heap.front();
        swap(heap.front(), heap.back());
        heap.pop_back();
        sift_down(0);
        return max;
    }
};

int main() {
    int n;
    cin >> n;
    Heap heap;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s == "Insert") {
            int num;
            cin >> num;
            heap.insert(num);
        } else {
            cout << heap.extract_max() << endl;
        }
    }

    return 0;
}