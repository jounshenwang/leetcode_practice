class MyStack {
public:
//一个队列实现栈，队列是先进先出的，栈是后进先出的，所以每次压入一个元素之后，把之前的元素都压入到这个元素的后面，这样这个元素就变成了队列的第一个元素了，也就是栈顶元素了
    queue<int> q;

    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int r = q.front();
        q.pop();
        return r;
    }
    
    /** Get the top element. */
    int top() {
        int r = q.front();
        return r;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};
