// Author:SatanWoo(Ziqi Wu)
// Github:satanwoo.github.io
// Weibo:@吴中生有正版

// 这题很简单，就是简单的递归，思路不啰嗦了
// 唯一卡人的地方就是那个如果两个空树算不算一致
// 这里是算一致，导致我错了一次

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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) return true;
        else if (p == NULL || q == NULL) return false;
        
        if (p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        
        return false;
    }
};