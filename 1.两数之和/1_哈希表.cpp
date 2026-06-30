class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashtable;
        for(int i = 0; i < nums.size(); i++){
            //每次遍历到新的值都判断哈希表里有没有能和这个值组成target的值
            //find方法返回对应的迭代器
            auto it = hashtable.find(target - nums[i]);
            if(it!=hashtable.end()){
                //it->second就是迭代器的值，这里就是下标
                return {it->second,i};
            }
            //储存键值对，让数组的值作为哈希表的键，下标为哈希表的值
            hashtable[nums[i]] = i;
        }
        return {};
    }
};