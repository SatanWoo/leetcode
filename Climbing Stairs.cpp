// Author:SatanWoo(Ziqi Wu)
// Github:satanwoo.github.io
// Weibo:@吴中生有正版

// 这题算简单的，不过我草我竟然了失误了。

// 两点注意：
// (1)如果纯递归的话，要注意时间复杂度，重复计算太可耻，所以要动态规划保存咯。
// (2)我竟然一开始用了2*result[i-2],我为啥这么想呢，因为从n-2到n可以走两次一步，
//    也可以走一次两步,我就觉得应该用2这个系数了，后面一想，不对啊，走两次一步不就
//    回到result[i-1]上去了嘛，哎，悲剧啊。

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0) return 1; 
        else if (n == 1) return 1;
        else if (n == 2) return 2;
        else 
        {
            vector<int>result;
            result.push_back(1);
            result.push_back(1);
            result.push_back(2);
            
            for (int i = 3;i <= n;i++)
            {
                result.push_back(result[i - 1] + result[i - 2]);
            }
            return result[n];
        }
    }
};