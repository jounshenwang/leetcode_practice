class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int left = 0;
        for (int x : nums)
        {
            if (x != val)
            {
                nums[left] = x;
                left++;
            }
        }
        return left;
    }
};