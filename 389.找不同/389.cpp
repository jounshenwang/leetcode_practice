class Solution {
public:
    char findTheDifference(string s, string t) {
        //整体逻辑是先把两个字符串排序，然后比较每个位置的字符，如果不一样了就说明这个位置的字符就是多出来的那个字符
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s.length()==0) return t[0];
        //如果s字符串长度为0了，说明t字符串的第一个字符就是多出来的那个字符
        char word=t.back();//如果s字符串长度不为0了，说明t字符串的最后一个字符就是多出来的那个字符
        for(int i=0;i<s.length();i++){
            if(s[i]!=t[i]){
                word=t[i];//如果s字符串和t字符串在某个位置的字符不一样了，说明这个位置的字符就是多出来的那个字符
                break;//为了word的值不被后面t字符串的字符覆盖了，找到了就break掉循环，不再继续比较了
            }
        }
        return word;
    }
};