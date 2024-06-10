#include <iostream>
#include <deque>

int main() {
    std::deque<int> myDeque;

    // Pushing elements into the deque from both ends
    myDeque.push_back(10);
    myDeque.push_front(20);
    myDeque.push_back(30);

    // Accessing elements
    std::cout << "Front element: " << myDeque.front() << std::endl;
    std::cout << "Back element: " << myDeque.back() << std::endl;

    // Popping elements from the deque
    while (!myDeque.empty()) {
        std::cout << myDeque.front() << " ";
        myDeque.pop_front();
    }

    return 0;
}