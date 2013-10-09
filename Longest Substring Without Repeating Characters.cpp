
// Author:SatanWoo(Ziqi Wu)
// Github:satanwoo.github.io
// Weibo:@吴中生有正版

// 此题方法类似于求最大子序列的和,但是要注意碰到重复的字母的时候，
// 要往回判断至重复的字母的后一个字母，看看是否能加上去构成更长的子串
// 总体是O(n)的方法思路，但是实现貌似不犀利啊。

class Solution { 
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        else if (s == "\n" || s == "\0") return 0;
        
        int max = 0;
        int sum = 0;
        string temp = "";
        int startIndex = 0; // 用来回溯的指针
        int currentIndex = 0; // 用来当前遍历的指针
        while(startIndex < s.length())
        {
            if (isCharacterInString(temp, s[currentIndex])) {
                temp = "";
                startIndex++;
                currentIndex = startIndex;
                temp += s[currentIndex];
                sum = 1;
            } else {
                temp += s[currentIndex];
                sum++;
                
            }
        
            if (sum > max)
            {
                max = sum;
            }
            
            currentIndex++;
            
            if (currentIndex >= s.length()) {
                startIndex++;
                currentIndex = startIndex;
            }
        }
        return max;
        
    }
    
    bool isCharacterInString(const string& s, char c) //这个地方应该可以优化吧。
    {
        if (s.length() == 0) return 0;
        else if (s == "\n" || s == "\0") return false;
        
        for (int i = 0; i < s.length();i++)
        {
            if (s[i] == c) return true;
        }
        return false;
    }
};