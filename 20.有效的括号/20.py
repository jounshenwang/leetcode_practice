class Solution:
    def isValid(self, s: str) -> bool:
        if len(s)%2 != 0:
            return False
        #python的哈希表是字典
        pairs={
            ")":"(",
            "]":"[",
            "}":"{"
        }
        #用列表来模拟栈
        stack=list()
        for ch in s:
            if ch in pairs:  #如果读取到的括号是右括号，则进入这个if
                 #python中任何非空的列表都为真，加一个not就相反，所以如果栈是空的或者栈顶元素
                 #不等于当前右括号对应的左括号，则说明不匹配，返回False
                if not stack or stack[-1]!=pairs[ch]: 
                    return False
                stack.pop()
            else:
                    stack.append(ch)#python中列表的append方法相当于栈的push方法
        return not stack
        