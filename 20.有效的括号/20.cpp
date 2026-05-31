class Solution {
public:
    bool isValid(string s) {
        //先处理边界情况，即如果输入是奇数，那么一定是不对的，返回false
        int n = s.size();
        if(n%2!=0) return false;
        //接下来判断一般情况
        //用一个哈希表定义一个包括三种括号对的字典，其中键是左括号，值是右括号
        unordered_map<char,char> pairs{
            {'}','{'},
            {')','('},
            {']','['}
        };
        stack<char> stk;  //用栈来实现这题，栈有后进先出的特性，可以用来做这种有顺序的配对问题
        for(char ch:s){   //遍历整个字符串
            //count函数会根据括号内的值是否作为键出现在哈希表中来返回0和1，这里用来判断读取到的是左括号还是右括号，是右括号则进下一个判断
            if(pairs.count(ch)){ 
                //如果栈是空的，那说明这个右括号没有对应的左括号，返回false
                //如果栈不是空的，那再判断栈顶上的值和ch这个键所对应的值是否一致，不一致就说明括号类型不一样，返回false
                if(stk.empty()||stk.top()!=pairs[ch]){
                    return false;                     
                }
                stk.pop();//读取到右括号，并且没进入上面的if则说明配对上了，把栈里配上对的左括号给弹出
            }
            else{
                stk.push(ch);//进入这里说明读取到左括号，则把左括号压入栈
            }
        }
        return stk.empty();//最后只要栈里是空的，那说明都配对了
    }
};