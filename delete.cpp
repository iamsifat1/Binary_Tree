#include <bits/stdc++.h>
using namespace std;

void heapifyUp(vector<int>& h, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (h[parent] < h[i]) {
            swap(h[parent], h[i]);
            i = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(vector<int>& h, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && h[l] > h[largest]) largest = l;
    if (r < n && h[r] > h[largest]) largest = r;

    if (largest != i) {
        swap(h[i], h[largest]);
        heapifyDown(h, n, largest);
    }
}

void insertMaxHeap(vector<int>& h, int x) {
    h.push_back(x);
    heapifyUp(h, h.size() - 1);
}


void deleteRoot(vector<int>& h) {
    int n = h.size();
    if (n == 0) {
        cout << "Heap is empty!\n";
        return;
    }

    h[0] = h[n - 1];
    h.pop_back();

    heapifyDown(h, h.size(), 0);
}

int main() {
   
    vector<int> maxHeap;
    int choice;

    cout << "1 -> Insert\n";
    cout << "2 -> Delete Root\n";
    cout << "3 -> Exit\n";

    while (true) {
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            int x;
            cout << "Enter value to insert: ";
            cin >> x;
            insertMaxHeap(maxHeap, x);
        }
        else if (choice == 2) {
            deleteRoot(maxHeap);
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }

        cout << "Current Max Heap: ";
        for (int v : maxHeap) cout << v << " ";
        cout << "\n";
    }

    return 0;
}
