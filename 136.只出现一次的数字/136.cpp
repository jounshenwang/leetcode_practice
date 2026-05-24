class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> findNum;
        // 第二种哈希表容器 unordered_map<Key, Value>
        // 储存内容为键值对，适用于需要关联数据，如统计次数
        // unordered_set<Key>只存key，适用于只需要判断是否存在
        for (auto &e : nums)
        {
            // for(auto& x:输入变量)
            // 相当于for (int i = 0; i < nums.size(); ++i) {
            //          int e = nums[i];
            //          ...
            //          }
            findNum[e]++;
        }
        int n = 0;
        for (auto &[num, count] : findNum)
        {
            //    for (auto& [key, value] : 哈希变量) {
            //     num 等价于 pair.first (键)
            //     count 等价于 pair.second (值)
            //    }
            if (count == 1)
            {
                n = num;
            }
        }
        return n;
    }
};