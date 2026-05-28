class Solution {
public:
    void reverseString(vector<char>& s) {
        int head=0;
        int rear=s.size()-1;
        int a=0;
        while(head<rear){
            a=s[rear];
            s[rear]=s[head];
            s[head]=a;
            head++;
            rear--;
        }
        return; //不需要返回值，因为函数返回是void类型的
    }
};