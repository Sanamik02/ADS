#include <iostream>
#include <queue>

int main() {
    std::queue<int> myQueue;

    // Pushing elements into the queue
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    // Accessing the front element
    std::cout << "Front element: " << myQueue.front() << std::endl;

    // Popping elements from the queue
    while (!myQueue.empty()) {
        std::cout << myQueue.front() << " ";
        myQueue.pop();
    }

    return 0;
}