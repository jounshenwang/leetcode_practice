class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        // 优先处理边界情况，就是两个字符串长度不相等时
        unordered_map<char, int> charMap;
        for (char c : s)
        {
            charMap[c]++; //[]在哈希表使用时，会创建键值对，记录每个元素及对应的出现次数，值初始为0，++遇到一次就会加1，
        }
        for (char c : t)
        {
            charMap[c]--; //--则是减1
        }
        for (auto &[words, count] : charMap)
        {
            if (count != 0)
            {
                return false;
            }
        }
        return true;
    }
};