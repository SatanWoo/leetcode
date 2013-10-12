// Author:SatanWoo(Ziqi Wu)
// Github:satanwoo.github.io
// Weibo:@吴中生有正版

// 这题难度更低了，什么公司出这题，请联系我
// 不想多说了，不会的去看Convert Sorted List to Binary Search Tree

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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size() == 0) return NULL;
        return recursiveBuildBinaryTree(0, num.size() - 1, num);
    }
    
    TreeNode* recursiveBuildBinaryTree(int start, int end, const vector<int>& vec)
    {
        if (start > end || start < 0 || end >= vec.size()) return NULL;
        
        int middle = (end + start)/2;
        
        TreeNode *node = new TreeNode(vec[middle]);
        node->left = recursiveBuildBinaryTree(start, middle - 1, vec);
        node->right = recursiveBuildBinaryTree(middle + 1 , end, vec);
        
        return node;
    }
};