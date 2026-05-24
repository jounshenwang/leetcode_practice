class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int l = digits.size();
        // 如果个位不为9，则不会发生进位，那么就在个位加1就好
        if (digits[l - 1] != 9)
        {
            digits[l - 1] += 1;
            return digits;
        }
        // 没进入if就说明个位是9，会发生进位,进位的话有两种情况
        // 情况一：有若干个9，那么找到从末尾开始往前的第一个不为9的数，加一，给他之后的数全都置0
        // 情况二：全部都是9，创建一个新数组，第一位为1，其他都为0
        for (int i = l - 1; i >= 0; i--)
        {
            if (digits[i] != 9)
            {
                ++digits[i];
                for (int j = i + 1; j < l; j++)
                {
                    digits[j] = 0;
                }
                return digits;
            }
        }
        vector<int> ans(l + 1); // 创建向量变量vector<int> 变量名(长度)；
        ans[0] = 1;
        return ans;
    }
};