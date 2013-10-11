// Author:SatanWoo(Ziqi Wu)
// Github:satanwoo.github.io
// Weibo:@吴中生有正版

// 这题还行吧，第二次见这种题，想了一会,智商捉急啊
// 总体思路就是螺旋形遍历，用一个变量Layer代表当前遍历当第几层了
// 我主要卡在循环终止条件那了，我本来想用个数除以2当做最大可能遍历的层数的。
// 后面想想不对啊，不一定是方阵。还有可能是2行3列那种奇葩。
// 算了，偷懒用结果vector里面的个数是否等于需要遍历的个数来终止吧。
// 当然奇行奇列的情况下，要注意点就是比如3x3的，最中心的那个，是同时满足的，不要重复添加了
// 所以我添加了一下位置信息判断。

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix)
	{
	    vector<int>result;
	    
	    int verticalSize = matrix.size();
	    if (verticalSize == 0) {
	        return result;
	    }
	    int horizontalSize = matrix[0].size();
	    
	    int count = 0;
	    int layer = 0; // Recursive From Outest Layer
	    
	    int max = verticalSize * horizontalSize;
	    
	    while(count < max) {
	        // Top Left
	        result.push_back(matrix[0 + layer][0 + layer]);
	        count++;
	        for (int i = 0 + layer + 1; i < horizontalSize - 1 - layer; i++)
	        {
	            result.push_back(matrix[0+layer][i]);
	            count++;
	        }
	        if (count >= max) break;
	        
	        // Top Right
	        if (horizontalSize - 1 - layer != 0 + layer) // 以防万一 3x3 矩阵中心点重复添加
	        {
	            // The same one
	            result.push_back(matrix[0 + layer][horizontalSize - 1 - layer]);
	            count++;
	        }
	        for (int j = 0 + layer + 1;j < verticalSize - 1 - layer;j++)
	        {
	            result.push_back(matrix[j][horizontalSize - 1 - layer]);
	            count++;
	        }
	        if (count >= max) break;
	        
	        // Bottom Right
	        if (verticalSize - 1 - layer != 0 + layer) {
	            result.push_back(matrix[verticalSize - 1 - layer][horizontalSize - 1 - layer]);
	            count++;
	        }
	        for (int i = horizontalSize - 2 - layer; i > 0 + layer;i--)
	        {
	            result.push_back(matrix[verticalSize - 1 - layer][i]);
	            count++;
	        }
	        if (count >= max) break;
	        
	        // BottomLeft
	        if (horizontalSize - 1 - layer != 0 + layer) {
	            result.push_back(matrix[verticalSize - 1 - layer][0+layer]);
	            count++;
	        }
	        for (int j = verticalSize - 2 - layer; j > 0 + layer; j--)
	        {
	            result.push_back(matrix[j][0+layer]);
	            count++;
	        }
	        
	        layer++;
	    }   
	    return result;
	}  
};