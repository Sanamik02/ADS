#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapify(largest);
        }
    }

public:
    MaxHeap() {}
    void push(int value) {
        heap.push_back(value);
        int index = heap.size() - 1;

        while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    int pop() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }

        int maxElement = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        heapify(0);

        return maxElement;
    }
    int top() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }
        return heap[0];
    }
    bool empty() {
        return heap.empty();
    }
};

int main() {
    MaxHeap pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(50);

    while (!pq.empty()) {
        cout << pq.pop() << " ";
    }
    cout << endl;

    return 0;
}