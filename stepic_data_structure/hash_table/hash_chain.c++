#include <utility>

#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <map>

using namespace std;

class Hash_table {
private:
    const long long p = 1000000007;
    long long x = 263;
    long long m;
    vector<long long> hash_x;
    map<long long, list<string> > table;

public:

    explicit Hash_table(int m) {
        hash_x.reserve(14);
        hash_x.push_back(x);
        for (int i = 1; i < 15; ++i) {
            x = (x % p * 263 % p) % p;
            hash_x.push_back(x);
        }
        this->m = m;
    }

    long long hash(string s) {
        long long h = s[0];
        for (int i = 1; i < s.size(); ++i) {
            h += s[i] * hash_x[i-1];
        }
        h = (h % p) % m;
        return h % m;
    }

    void add(const string& s) {
        long long h = hash(s);
        if (table.find(h) != table.end()) {
            if (table[h].empty())
                table[h].push_front(s);
            else {
                auto it = table[h].begin();
                while (it != table[h].end()) {
                    if (s == *it) {
                        return;
                    }
                    it++;
                }
                table[h].push_front(s);
            }
        } else {
            list<string> list;
            list.push_front(s);
            table.insert(make_pair(h, list));
        }
    }

    void del(const string& s) {
        long long h = hash(s);
        if (table.find(h) != table.end()) {
            auto it = table[h].begin();
            while (it != table[h].end()) {
                if (s == *it) {
                    table[h].erase(it);
                    return;
                }
                it++;
            }
        }
    }

    bool find (const string& s) {
        long long h = hash(s);
        if (table.find(h) != table.end()) {
            auto it = table[h].begin();
            while (it != table[h].end()) {
                if (s == *it) {
                    return true;
                }
                it++;
            }
        }
        return false;
    }

    void check(long long i) {
        if (table.find(i) == table.end()) {
            cout << endl;
            return;
        }

        if (table[i].empty()) {
            cout << endl;
        }

        auto it = table[i].begin();
        while (it != table[i].end()) {
            cout << *it << " ";
            it++;
        }
        cout << endl;
    }

};

int main() {
    long long m;
    int n;
    cin >> m >> n;
    Hash_table table(m);

    for (int i = 0; i < n; ++i) {
        string command;
        cin >> command;
        if (command == "add") {
            string s;
            cin >> s;
            table.add(s);
        } else if (command == "del") {
            string s;
            cin >> s;
            table.del(s);
        } else if (command == "find") {
            string s;
            cin >> s;
            cout << (table.find(s) ? "yes" : "no") << endl;
        } else {
            long long num;
            cin >> num;
            table.check(num);
        }
    }

    return 0;
}