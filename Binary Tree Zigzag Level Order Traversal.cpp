// Author:SatanWoo(Ziqi Wu)
// Github:satanwoo.github.io
// Weibo:@吴中生有正版

// 这题感觉不是属于难题，就是类似于层次遍历，但是这边的层次遍历稍微注意下，不要用queue这种形式一次性存放
// 不然你都不知道到了第几层，然后思路就很普通，感觉是个o(n)的时间复杂度

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
	    vector<vector<int>> output;
	    if (root == NULL) return output;
	    
	    vector<TreeNode *> input;
	    input.push_back(root);
	    
	    bool isFromLeftToRight = true;
	    
	    while(input.size() != 0) {
	        vector<int> values = valueFromLayer(input, isFromLeftToRight);
	        output.push_back(values);
	        
	        input = getSubNodesForNodes(input);
	        isFromLeftToRight = !isFromLeftToRight;
	    }
	    
	    return output;
	
    vector<TreeNode *>getSubNodesForNodes(vector<TreeNode* > vec) {
       vector<TreeNode *> result;
       int size = vec.size();
       if (size != 0) {
          for (int i = 0; i < size;i++) {
              TreeNode *node = vec[i];
              if (node->left != NULL) result.push_back(node->left);
              if (node->right != NULL) result.push_back(node->right);
          }
       } 
       return result;
    }
    
    vector<int> valueFromLayer(vector<TreeNode *>nodes, bool isFromLeftToRight) {
        vector<int> result;
        int size = nodes.size();
        if (size != 0) {
            for (int i = 0; i < size;i++) {
                TreeNode* node = nodes[i];
                result.push_back(node->val);
            }
        }
        
        if (!isFromLeftToRight) std::reverse(result.begin(), result.end());
        return result;
    }
};