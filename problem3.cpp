#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MaxPriorityQueue {
    vector<int> A;

public:
    void insert(int x) {
        A.push_back(x);
    }

    void get_max() {
        if (A.empty()) {
            cout << "EMPTY" << endl;
            return;
        }

        int mx = A[0];
        for (int v: A)
            if (v > mx) mx = v;
        cout << mx << endl;
    }

    void extract_max() {
        if (A.empty()) {
            cout << "EMPTY" << endl;
            return;
        }

        int mx = A[0];
        int idx = 0;
        for (int i = 1; i < (int) A.size(); i++) {
            if (A[i] > mx) {
                mx = A[i];
                idx = i;
            }
        }

        cout << mx << endl;
        A.erase(A.begin() + idx);
    }

    void size() {
        cout << A.size() << endl;
    }
};

int main() {
    int q;
    cin >> q;
    MaxPriorityQueue pq;

    while (q--) {
        string cmd;
        cin >> cmd;

        if (cmd == "insert") {
            int x;
            cin >> x;
            pq.insert(x);
        } else if (cmd == "get_max") {
            pq.get_max();
        } else if (cmd == "extract_max") {
            pq.extract_max();
        } else if (cmd == "size") {
            pq.size();
        }
    }

    return 0;
}
