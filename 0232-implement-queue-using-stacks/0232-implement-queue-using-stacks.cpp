class MyQueue {
private:
    stack<int> stk1;
    stack<int> stk2;
public:
    MyQueue() {

    }

    void push(int x) {
        stk1.push(x);
    }

    int pop() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                int t = stk1.top();
                stk1.pop();
                stk2.push(t);
            }
        }
        int t = stk2.top();
        stk2.pop();
        return t;
    }

    int peek() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                int t = stk1.top();
                stk1.pop();
                stk2.push(t);
            }
        }
        return stk2.top();
    }

    bool empty() {
        return stk1.empty() && stk2.empty();
    }
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */