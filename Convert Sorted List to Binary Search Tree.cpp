// Author:SatanWoo(Ziqi Wu)
// Github:satanwoo.github.io
// Weibo:@吴中生有正版

// 我操我是个2b啊，我竟然二分忘记改变middle +1, middle - 1。
// 实参和形参竟然搞错了，我tmd太弱智了。题目很简单，看请题目，要高度平衡
// 所以从中间开始建树吧，当然，最好选择二分中偏大的那个建树比较好，么么哒

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) return NULL;
        
        ListNode *temp = head;
        vector<int> elements;
        
        while(temp != NULL) 
        {
            elements.push_back(temp->val);
            temp = temp->next;
        }
 
        return recursiveBuildBinaryTree(0, elements.size() - 1, elements);
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