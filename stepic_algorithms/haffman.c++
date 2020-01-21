#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

class Node {
private:
    Node *left;
    Node *right;
    int freq = 0;
    char symbol;
    string code = "";

public:
    explicit Node(int freq) {
        this->freq = freq;
        left = right = nullptr;
    }

    void set_children(Node *l, Node *r) {
        left = l;
        right = r;
    }

    void set_freq() {
        this->freq++;
    }

    int getFreq() const {
        return freq;
    }

    void setCode(string c) {
        code += c;
    }

    void setSymbol(char s) {
        this->symbol = s;
    }

    char getSymbol() {
        return symbol;
    }

    string getCode() {
        return code;
    }

    Node *getLeft() const {
        return left;
    }

    Node *getRight() const {
        return right;
    }

};

class Heap {
private:
    vector<Node*> heap;

    // Просеять вверх (при добавлении)
    void sift_up(int pos) {
        if (pos == 0)
            return;
        int parent = (pos - 1) / 2;
        if (heap[pos]->getFreq() < heap[parent]->getFreq()) {
            swap(heap[pos], heap[parent]);
            sift_up(parent);
        }
    }

    // Просеять вниз (при удалении максимума)
    void sift_down(int pos) {
        int max_index = pos;

        int left = 2*pos+1;
        if (left < heap.size() && heap[left]->getFreq() < heap[max_index]->getFreq()) {
            max_index = left;
        }

        int right = 2*pos+2;
        if (right < heap.size() && heap[right]->getFreq() < heap[max_index]->getFreq()) {
            max_index = right;
        }

        if (pos != max_index) {
            swap(heap[pos], heap[max_index]);
            sift_down(max_index);
        }
    }

public:
    void insert(Node *node) {
        heap.push_back(node);
        sift_up(heap.size() - 1);
    }

    Node* extract_min() {
        Node *min = heap.front();
        swap(heap.front(), heap.back());
        heap.pop_back();
        sift_down(0);
        return min;
    }

    void setCode(Node *node, const string& code) {
        node->setCode(code);
        if (node->getLeft()) {
            setCode(node->getLeft(), code + "0");
        }
        if (node->getRight()) {
            setCode(node->getRight(), code + "1");
        }
    }
    
    Node* getRoot() {
        return heap.front();
    }

    void show(Node *node) {
        if (node->getSymbol())
            cout << node->getSymbol() << ": " << node->getCode() << endl;
        if (node->getLeft())
            show(node->getLeft());
        if (node->getRight())
            show(node->getRight());
    }

};

int main() {

    string stroke;
    cin >> stroke;

    // Выделение частот, создание узлов
    map<char, Node*> frequency;
    for (char & i : stroke) {
        auto temp = frequency.find(i);
        if (temp == frequency.end()) {
            Node *node = new Node(1);
            node->setSymbol(i);
            frequency.insert({i, node});
        } else {
            temp->second->set_freq();
        }
    }

    if (frequency.size() == 1) {
        cout << "1" << " " << stroke.size() << endl;
        cout << frequency.at(stroke[0])->getSymbol() << ": " << "0" << endl;
        for (int i = 0; i < stroke.size(); ++i) {
            cout << "0";
        }
        return 0;
    }

    Heap heap;
    for (auto elem : frequency) {
        heap.insert(elem.second);
    }

    for (int i = 0; i < frequency.size()-1; ++i) {
        Node *left = heap.extract_min();
        Node *right = heap.extract_min();
        Node *node = nullptr;
        if (left && !right)
            node = new Node(left->getFreq());
        else if (!left && right)
            node = new Node(right->getFreq());
        else if (left && right)
            node = new Node(left->getFreq() + right->getFreq());
        if (node) {
            node->set_children(left, right);
            heap.insert(node);
        }
    }

    heap.setCode(heap.getRoot(), "");

    string result;
    for (auto s : stroke) {
        result += frequency[s]->getCode();
    }

    cout << frequency.size() << " " << result.size() << endl;
    heap.show(heap.getRoot());
    cout << result;

    return 0;
}