#include <iostream>
#include <vector>
using namespace std;

class MinHeap
{
public:
    vector<int> heap;

    MinHeap()
    {
        heap.push_back(-1); // dummy element to make indexing start from 1
    }

    // get size
    int size()
    {
        return heap.size() - 1; // ignoring dummy
    }

    // Insert new element
    void insert(int val)
    {
        heap.push_back(val);
        int index = size();

        // Heapify up
        while (index > 1 && heap[index] < heap[index / 2])
        {
            swap(heap[index], heap[index / 2]);
            index /= 2;
        }
    }

    // Heapify down for deletion
    void heapifyDown(int i)
    {
        int left = 2 * i;
        int right = 2 * i + 1;
        int smallest = i;

        if (left <= size() && heap[left] < heap[smallest])
            smallest = left;

        if (right <= size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i)
        {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    // Delete root element (min)
    void deleteRoot()
    {
        if (size() == 0)
        {
            cout << "Heap is empty.\n";
            return;
        }

        heap[1] = heap.back();
        heap.pop_back();
        heapifyDown(1);
    }

    // Return min (root)
    int getMin()
    {
        if (size() == 0)
            return -1;
        return heap[1];
    }

    void printHeap()
    {
        for (int i = 1; i <= size(); i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main()
{
    MinHeap h;
    h.insert(20);
    h.insert(15);
    h.insert(30);
    h.insert(5);
    h.insert(10);

    cout << "Heap: ";
    h.printHeap();

    cout << "Min Element: " << h.getMin() << endl;

    h.deleteRoot();
    cout << "After deleting root: ";
    h.printHeap();
}
