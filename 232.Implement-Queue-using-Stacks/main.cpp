#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> sta;
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> buffer;
        int len = sta.size();
        for(int i=0;i<len;i++){
            int s = sta.top();
            sta.pop();
            buffer.push(s);
        }
        buffer.push(x);
        for (int i=0;i<len+1;i++){

            sta.push(buffer.top());
            buffer.pop();

        }

    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int s =  sta.top();
        sta.pop();
        return s;
    }

    /** Get the front element. */
    int peek() {
        return sta.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return sta.empty();
    }
};


int main() {

    MyQueue queue_ = MyQueue();

    queue_.push(1);
    queue_.push(2);
    int s1 = queue_.peek();  // returns 1
    int s2 = queue_.pop();   // returns 1
    queue_.empty(); // returns false

    printf("%d %d",s1,s2);

    return 0;
}