// Author:SatanWoo(Ziqi Wu)
// Github:satanwoo.github.io
// Weibo:@吴中生有正版

// 这题思路上就是前后接环结点，思路不难，就是注意节点变换后要随时注意更新头结点保证顺序不会错乱
// 就可以了。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL) return NULL;
        head = swapList(head);
        return head;
    }
    
    ListNode *swapList(ListNode *root) {
        ListNode *node = root;
        if (root == NULL) return NULL;
        
        ListNode *fastNode = root->next;
        if (fastNode == NULL) return node;
        
        ListNode *temp = fastNode->next;
        fastNode->next = node;
        node->next = temp;
    
        node->next = swapList(node->next);
        
        return fastNode;
    }
};