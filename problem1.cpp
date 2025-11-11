#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i: v) cin >> i;

    int i;
    cin >> i;
    int p = i;

    while (true) {
        int l = p * 2 + 1;
        int r = p * 2 + 2;
        int sm = p;

        if (l < n && v[l] < v[sm]) sm = l;
        if (r < n && v[r] < v[sm]) sm = r;
        else if (l < n && r < n && v[l] == v[r] && v[l] < v[p]) sm = l;

        if (sm == p) break;
        swap(v[sm], v[p]);
        p = sm;
    }

    for (int j = 0; j < n; ++j) {
        cout << v[j];
        if (j < n - 1) cout << " ";
    }
    return 0;
}
