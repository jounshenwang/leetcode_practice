class MyQueue {
//使用双栈来模拟队列先进先出
//用两个栈，元素先进入第一个栈，然后弹出，压入第二个栈，由于栈是后进先出的，于是第一个栈栈顶的元素到第二个栈就变成栈底元素了，也就是后进（1栈顶）->后出（2栈底）
private:
    stack<int>inStack,outStack;
    //要实现这个操作，很多队列的函数的构造中都要用到把第一个栈的元素传到第二个栈里这一步，所以干脆构造一个函数，之后用到的时候直接调用这个函数
    void in2out(){
        while(!inStack.empty()){//只要第一个栈不是空的就把第一个栈的元素弹出压入第二个栈，然后移除
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    MyQueue() {
        
    }
    
    //压入这个操作不需要改
    void push(int x) {
    inStack.push(x);    
    }
    
    //后进后出的弹出操作
    int pop() {
        if(outStack.empty()){
            in2out();
        }
        int x = outStack.top();
        outStack.pop();
        return x;
    }
    
    //返回队列开头的元素，也就是最先进的元素，也就是最先出的元素，也就是第二个栈的栈顶元素
    int peek() {
         if(outStack.empty()){
            in2out();
        }
        return outStack.top();
    }
    
    bool empty() {
        return inStack.empty()&&outStack.empty();
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