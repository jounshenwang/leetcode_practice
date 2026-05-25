class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //整体逻辑是通过两个哈希集合，第一个集合遍历第一个数组，然后遍历第二个数组的时候
    //如果存在一样的值，则把这个值加入到第二个集合中，最后把这个集合转换成向量输出
        unordered_set<int> num1Key;
        unordered_set<int> isSame;
        for(int x:nums1){
        num1Key.insert(x);
        }
        for(int x:nums2){
        auto i=num1Key.find(x);
        //哈希表find函数返回值,找到了返回这个元素的位置(不等同于地址)，没找到回
        //end()，于是可以用i!=num1Key.end()来判断有没有找到
        //由于find()既有可能返回位置也有可能返回end(),所以记录这个结果的变量
        //需要是auto自动判断类型
        if(i!=num1Key.end()){
        isSame.insert(x);
        }
        }
        vector<int> n(isSame.begin(),isSame.end());
        //使用迭代器行驶把哈希集合转换成向量数组
        return n;

        //因为题目要求返回向量，所以得把集合转换成向量形式
        }
};