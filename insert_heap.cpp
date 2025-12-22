#include <bits/stdc++.h>
using namespace std;


void heapifyDownMax(vector<int>& h, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && h[l] > h[largest]) largest = l;
    if (r < n && h[r] > h[largest]) largest = r;

    if (largest != i) {
        swap(h[i], h[largest]);
        heapifyDownMax(h, n, largest);
    }
}

void heapifyDownMin(vector<int>& h, int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && h[l] < h[smallest]) smallest = l;
    if (r < n && h[r] < h[smallest]) smallest = r;

    if (smallest != i) {
        swap(h[i], h[smallest]);
        heapifyDownMin(h, n, smallest);
    }
}

int main() {

    int n;
    cin >> n;

    vector<int> mx_heap(n), mn_heap(n);

    for (int i = 0; i < n; i++) {
        cin >> mx_heap[i];
        mn_heap[i] = mx_heap[i];
    }

    for (int i = n/2 - 1; i >= 0; i--) {
        heapifyDownMax(mx_heap, n, i);
    }

    for (int i = n/2 - 1; i >= 0; i--) {
        heapifyDownMin(mn_heap, n, i);
    }

    cout << "Max Heap:\n";
    for (int x : mx_heap) cout << x << " ";
    cout << "\n";

    cout << "Min Heap:\n";
    for (int x : mn_heap) cout << x << " ";
    cout << "\n";

    return 0;
}
