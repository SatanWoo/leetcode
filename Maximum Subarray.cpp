// Author:SatanWoo(Ziqi Wu)
// Github:satanwoo.github.io
// Weibo:@吴中生有正版

// 很水的一题，不说了，注意先比大小再化成0，因为可能出现只有负数-1这样的用例。

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n <= 0) return 0;    
        int sum = 0;
        int max = A[0]; //初始值要注意一下
       
        for (int i = 0; i < n;i ++) {
            sum += A[i];
            
            if (sum > max) {
                max = sum;
            }
            
            if (sum < 0) sum = 0;
        }
       
        return max;
    }
};