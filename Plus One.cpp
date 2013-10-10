// Author:SatanWoo(Ziqi Wu)
// Github:satanwoo.github.io
// Weibo:@吴中生有正版

// 这题太简单了，不赘述思路了。

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int>result;
        
        int size = digits.size();
        int carrier = 1;
        
        for (int i = size - 1;i >= 0;i --) {
            int origin = digits[i];
            origin += carrier;
            
            carrier = origin > 9 ? 1:0;
            origin = origin > 9 ? origin - 10 : origin;
            result.push_back(origin);
        }
        
        if (carrier == 1) {
            result.push_back(1);
        }
        
        std::reverse(result.begin(), result.end());
        
        return result;
    }
};