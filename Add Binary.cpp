// Author:SatanWoo(Ziqi Wu)
// Github:satanwoo.github.io
// Weibo:@吴中生有正版

// 这题思路上没什么难度，类似于两个数加法，就是注意判断进位之类的就可以了
class Solution {
public:
    string addBinary(string a, string b) {
        int aLength = a.length();
        int bLength = b.length();
        int smallLength = aLength > bLength ? bLength : aLength;
        string result;
        
        int carrier = 0;
        int aIndex = aLength - 1;
        int bIndex = bLength - 1;
        
        for (int i = 0; i < smallLength;i++) {
            int value = a[aIndex--] - '0' + b[bIndex--] - '0' + carrier;
            if (value > 1) {
                carrier = 1;
                value -= 2;
            } else {
                carrier = 0;
            }
            result += value + '0';
        }
        
        while(aIndex >= 0) {
            int value = a[aIndex--] - '0' + carrier;
            if (value > 1) {
                carrier = 1;
                value -= 2;
            } else {
                carrier = 0;
            }
            result += value + '0';
        }
        
        while(bIndex >= 0) {
            int value = b[bIndex--] - '0' + carrier;
            if (value > 1) {
                carrier = 1;
                value -= 2;
            } else {
                carrier = 0;
            }
            result += value + '0';
        }
        
        if (carrier > 0) result += 1 + '0';
        
        std::reverse(result.begin(), result.end());
        return result;
    }
};
