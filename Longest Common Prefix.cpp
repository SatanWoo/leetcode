// Author:SatanWoo(Ziqi Wu)
// Github:satanwoo.github.io
// Weibo:@吴中生有正版

// 这题很简单吧，就是一个for 循环遍历啦。 几个分支条件逻辑分析好就没什么难题了。

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int size = strs.size();
        if (size == 0) return "";
        else if (size == 1) return strs[0];
        
        string candidate = strs[0];
        int longest = candidate.length(); 
        
        for (int i = 1; i < size; i++)
        {
            string s = strs[i];
            int threshold = longest > s.length() ? longest : s.length();
            for (int j = 0; j < threshold; j++)
            {
                if (j >= s.length()) 
                {
                     candidate = s;
                     longest = candidate.length();
                     break;
                }
                
                if (s[j] == candidate[j]) continue;
                
                candidate = s.substr(0, j);
                longest = candidate.length();
               
                break;
            }
        }
        
        return candidate;
    }
};