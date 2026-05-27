class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> more;
        int a = 0;
        for (int x : nums)
        {
            more[x]++;
        }
        for (auto &[key, count] : more)
        {
            if (count > (nums.size() / 2))
            {
                a = key;
                break;
            }
        }
        return a;
    }
};