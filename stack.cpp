#include <iostream>
#include <stack>

int main() {
    std::stack<int> myStack;

    // Pushing elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Accessing the top element
    std::cout << "Top element: " << myStack.top() << std::endl;

    // Popping elements from the stack
    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }

    return 0;
}