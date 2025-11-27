#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
public:
    vector<int> heap;

    MaxHeap() {
        heap.push_back(-1);
    }

    MaxHeap(vector<int> arr) {
        heap.push_back(-1); // dummy element to maintain 1-based indexing
        for(int val : arr) heap.push_back(val);
        buildHeap();
    }

    int size() {
        return heap.size() - 1;
    }

    void insert(int val) {
        heap.push_back(val);
        int index = size();

        while(index > 1 && heap[index] > heap[index / 2]) {
            swap(heap[index], heap[index / 2]);
            index /= 2;
        }
    }



    void heapifyDown(int i, int n) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest = i;

        if(left <= n && heap[left] > heap[largest])
            largest = left;

        if(right <= n && heap[right] > heap[largest])
            largest = right;

        if(largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest, n);
        }
    }

    void deleteRoot() {
        if(size() == 0) {
            cout << "Heap is empty.\n";
            return;
        }
        heap[1] = heap.back();
        heap.pop_back();
        heapifyDown(1, size());
    }

    void heapSort() {
        int n = size();
    
        // Perform heap sort
        for(int i = n; i > 1; i--) {
            swap(heap[1], heap[i]);  // Move max to end
            heapifyDown(1, i - 1);   // Heapify reduced heap
        }
    }


    int getMax() {
        return size() == 0 ? -1 : heap[1];
    }

    void printHeap() {
        for(int i = 1; i <= size(); i++)
            cout << heap[i] << " ";
        cout << endl;
    }

    // NEW: Build heap in O(N)
    void buildHeap() {
        for(int i = size() / 2; i >= 1; i--) {
            heapifyDown(i, size());
        }
    }
};


int main() {
    MaxHeap h1;

    h1.insert(40);
    h1.insert(10);
    h1.insert(50);
    h1.insert(30);
    h1.insert(60);

    cout << "Heap Elements: ";
    h1.printHeap();

    cout << "Max Element: " << h1.getMax() << endl;

    h1.deleteRoot();
    cout << "After deleting root: ";
    h1.printHeap();

    h1.insert(100);
    cout << "After inserting 100: ";
    h1.printHeap();

    cout<< "Building heap from array using heapifyDown: \n";

    vector<int> arr = {10, 20, 5, 30, 15, 50};

    MaxHeap h(arr);

    cout << "Heap built from array: ";
    h.printHeap();

    h.heapSort();

    cout << "Sorted array using heap sort: ";
    h.printHeap();

    return 0;
}
