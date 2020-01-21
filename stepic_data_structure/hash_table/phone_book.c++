#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map <int, string> book;

    for (int i = 0; i < n; ++i) {
        string command;
        cin >> command;
        int num;
        cin >> num;
        if (command == "add") {
            string name;
            name.reserve(15);
            cin >> name;
            if (book.find(num) == book.end()) {
                book.insert(make_pair(num, name));
            } else {
                book[num] = name;
            }
        } else if (command == "del") {
            book.erase(num);
        } else {
            if (book.find(num) == book.end())
                cout << "not found" << endl;
            else
                cout << book[num] << endl;
        }
    }

    return 0;
}