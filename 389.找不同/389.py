class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        ret=0
        for ch in s:
            ret^=ord(ch)
            #ord函数可以把字符转换成对应的ASCII码值，^是异或运算符，异或运算符的特点是相同的数异或结果为0，
            # 不同的数异或结果为1，所以我们先把s字符串中的每个字符都异或一遍，最后再把t字符串中的每个字符都异或一遍，
            # 最后ret中就只剩下了多出来的那个字符的ASCII码值了
        for ch in t:
            ret^=ord(ch)
        return chr(ret)
        