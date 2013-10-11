// Author:SatanWoo(Ziqi Wu)
// Github:satanwoo.github.io
// Weibo:@吴中生有正版

// 瞎了，我想知道哪个著名企业出的这题，请联系我，太简单了
// 就这样这题AC Rate 1412/4094 国外程序员是不是一群蠢蛋
// 本来还以为有大数据量，要二分的。
// 呵呵，就是一个插入排序啊，尼玛，思路不想多说了，上代码

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int possibleIndex = 0;
        for (int i = 0; i < n;i++)
        {
            if (target == A[i]) return i;
            else if (target > A[i]) possibleIndex++;
        }
        
        return possibleIndex;
    }
};