#include <iostream>
using namespace std;

class PriorityQueue {
    int *heap;
    int capacity;
    int size;

public:
    PriorityQueue(int cap) {
        capacity = cap;
        heap = new int[cap];
        size = 0;
    }
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    void insert(int key) {
        if (size == capacity) {
            cout << "Overflow: Cannot insert!\n";
            return;
        }
        int i = size;
        heap[i] = key;
        size++;
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < size && heap[l] > heap[largest])
            largest = l;
        if (r < size && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }
    int getMax() {
        if (size <= 0) return -1;
        return heap[0];
    }
    int extractMax() {
        if (size <= 0) return -1;
        if (size == 1) {
            size--;
            return heap[0];
        }

        int root = heap[0];
        heap[0] = heap[size - 1];
        size--;

        heapify(0);

        return root;
    }
    void increaseKey(int i, int newVal) {
        heap[i] = newVal;
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    void display() {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq(20);
    pq.insert(30);
    pq.insert(10);
    pq.insert(50);
    pq.insert(40);
    pq.insert(5);
    cout << "Priority Queue (Max-Heap): ";
    pq.display();
    cout << "Maximum Element: " << pq.getMax() << endl;
    cout << "Extracted Max: " << pq.extractMax() << endl;
    cout << "After extraction: ";
    pq.display();
    return 0;
}
