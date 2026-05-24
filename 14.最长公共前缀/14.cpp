class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        // 对于这种题型首先考虑边界情况的处理：
        //----------------------------------------------------------------------
        if (strs.empty())
            return "";
        // 边界情况一：空数组，直接可以返回空值
        if (strs.size() == 1)
            return strs[0];
        // 边界情况二：只有一个单词，返回单词本身
        if (strs[0].size() == 0)
            return "";
        // 边界情况三：数组不是空的，但是第一个输入是空的，也直接返回空值
        //--------------------------------------------------------------------
        string sharedWords = ""; // 用来记录公共前缀的变量

        // 正常情况下的逻辑，两层循环，外层遍历列，内层遍历行，即首先遍历每个单词的 第一个字母，用一个标志位确认这一位是否全部匹配，然后第二个，第三个....
        for (int j = 0; j < strs[0].size(); j++)
        {
            char base = strs[0][j]; // 以第一个单词的每一位作为评判基准
            bool allMatch = true;   // 标志位
            for (int i = 1; i < strs.size(); i++)
            {
                if (strs[i][j] != base || strs[i].size() <= j)
                {
                    allMatch = false;
                    // 如果不是每一个单词的这一位都一样或者其他单词长度小于第一个单词就结束循环
                    break;
                }
            }
            if (allMatch)
            {
                sharedWords += base;
                // 如果全都一样就记录下来这个字母
            }
            else
            {
                break;
            }
        }
        return sharedWords;
    }
};