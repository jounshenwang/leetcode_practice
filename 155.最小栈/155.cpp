// 155. 最小栈
// 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
// push(x) —— 将元素 x 推入栈中。
// pop() —— 删除栈顶的元素。    
// top() —— 获取栈顶元素。
// getMin() —— 检索栈中的最小元素。
//用两个栈，一个正常存储数据，一个存储当前最小值，每次push时比较当前值和最小值，更新最小值栈
//pop时两个栈都pop，top时返回正常栈的top，getMin时返回最小值栈的top
class MinStack {
    stack<int> x_stack;
    stack<int> min_stack;
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int value) {
        x_stack.push(value);
        min_stack.push(min(min_stack.top(),value));
    }
    
    void pop() {
        x_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return x_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
