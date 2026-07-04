#include <stack>
using namespace std;

class MinStack {
    stack<int> s;
    stack<int> minStack;

public:
    MinStack() {

    }

    void push(int value) {
        s.push(value);

        if (minStack.empty() || value <= minStack.top())
            minStack.push(value);
    }

    void pop() {
        if (s.empty())
            return;

        if (s.top() == minStack.top())
            minStack.pop();

        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minStack.top();
    }
};