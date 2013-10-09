// Author:SatanWoo(Ziqi Wu)
// Github:satanwoo.github.io
// Weibo:@吴中生有正版

class Solution {
public:
    int numTrees(int n)
    {
        // Initial condition
        if (n <= 0) return 1;
        else if (n == 1) return 1;
        else if (n == 2) return 2;
        
        else
        {
            int result = 0;
            for (int i = 1; i <= n/2;i++)
            {
                result += 2 * numTrees(i - 1) * numTrees(n - i);// 对称
            }
            
            if (n%2 != 0)
            {
                int temp = numTrees(n/2);
                result += temp * temp; // 奇数单独考虑一个中间项,也可以先加2倍再在这里减。
            }
            
            return result;
    }
}

};