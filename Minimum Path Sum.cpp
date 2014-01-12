// Author:SatanWoo(Ziqi Wu)
// Github:satanwoo.github.io
// Weibo:@吴中生有正版

// 这题算简单的吧。没什么好说的，要直接递归的话肯定是挂了，大数据必然溢出啊。
// 一个很简单的动态规划。尼玛，我在vector这里出错了，对于API不熟悉给跪啊。
// 擦擦擦，vector<int> a(a).然后再push_back，说明vector含有了N+1。


class Solution {
public:
    int minPathSum(vector<vector<int> > &grid)
    {
        int height = grid.size();
        int width = grid[0].size();
        
        vector<vector<int>> result;
        for (int i = 0; i < height; i ++)
        {
            vector<int> row(width);
            result.push_back(row);
        }
    
        
        if (height == 1 && width == 0) return 0;
        else if (height == 1 && width == 1) return grid[0][0];
        
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (i == 0 && j == 0) result[i][j] = grid[i][j];
                else if (i == 0 && j != 0) // the first row
                {
                    result[i][j] = grid[i][j] + result[i][j - 1];
                }
                else if (j == 0 && i != 0) // the first column
                {
                    result[i][j] = grid[i][j] + result[i - 1][j];
                }
                else 
                {
                    result[i][j] = grid[i][j] + min(result[i - 1][j], result[i][j - 1]);
                }
                
            }
        }
        
        return result[height - 1][width - 1];
    }
};