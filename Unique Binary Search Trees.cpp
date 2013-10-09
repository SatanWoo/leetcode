// Author:SatanWoo(Ziqi Wu)
// Github:satanwoo.github.io
// Weibo:@吴中生有正版

// 这题如果做到递归遍历的胡同里，就完蛋了，要注意找规律。
// 当然这规律不是很容易找，不是推送数学公式，而是要结合图形
// 发现对称的美，这里的对称不仅仅是形状对称，更是一种个数上的对称。

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