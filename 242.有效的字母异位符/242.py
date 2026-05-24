class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
#python版哈希表解法，C++ 的 unordered_map 等价于 Python 的 dict
#C++ 的 unordered_set 等价于 Python 的 set
        if len(s)!=len(t)  return False
        char_map = {}
        for c in s:
            char_map[c] = char_map.get(c,0) + 1
#get(key,default),获取键的值，若键不存在则返回默认值
        for c in t:
            char_map[c] = char_map.get(c,0) - 1
            if char_map[c] < 0
                return False
    return True
#-----------------------最优----------------
        #return Counter(s)==Counter(t)
        #Python 的 Counter 是 collections 模块中的一个类，用于统计可迭代对象中元素的出现次数