#include <iostream>
#include <vector>
using namespace std;

void heapDown(vector<int> &v, int n, int i) {
    int sm = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && v[l] < v[sm]) sm = l;
    if (r < n && v[r] < v[sm]) sm = r;

    if (sm != i) {
        swap(v[i], v[sm]);
        heapDown(v, n, sm);
    }
}

void buildMinHeap(vector<int> &v, int n) {
    for (int i = n / 2 - 1; i >= 0; --i) heapDown(v, n, i);
}

int extractMin(vector<int> &v, int &n) {
    if (n <= 0) return -1;
    int root = v[0];
    v[0] = v[n - 1];
    n--;
    heapDown(v, n, 0);
    return root;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    for (auto &i: v) cin >> i;

    buildMinHeap(v, n);

    vector<int> srt(n);
    int heapSize = n;
    for (int i = 0; i < n; ++i) srt[i] = extractMin(v, heapSize);

    for (int i = 0; i < n; ++i) {
        cout << srt[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
