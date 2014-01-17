// Author:SatanWoo(Ziqi Wu)
// Github:satanwoo.github.io
// Weibo:@吴中生有正版

// 这题的思路有点类似于Candy这题。利用左到右，右到左两次遍历，确定每一个当前位置可能存在的最大水。
// 然后把A[i]看成阻碍，不能存水即可。

class Solution {
public:
    int trap(int A[], int n) {
        if (n == 0) return 0;
        
        int sum = 0;
        
        vector<int>leftHighestBound(n);
        vector<int>rightHighestBound(n);
        
        int max = 0;
        for (int i = 1; i < n;i++)
        {
            max = max > A[i-1] ? max : A[i-1];
            leftHighestBound[i] = max;
        }
        
        max = 0;
        for (int i = n - 2;i >=0 ;i--)
        {
            max = max > A[i+1] ? max : A[i+1];
            rightHighestBound[i] = max;
        }
        
        for (int i = 0; i < n; i++)
        {
            int threshold = min(leftHighestBound[i], rightHighestBound[i]);
            int candidate = threshold - A[i] > 0 ? threshold - A[i] : 0;
            sum += candidate;
        }
        
        return sum;
    
    }
};