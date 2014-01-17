// Author:SatanWoo(Ziqi Wu)
// Github:satanwoo.github.io
// Weibo:@吴中生有正版

// 这题的思路类似于就是想将当前k部分中需要逆序的部分，比如1->2->3直接改变指针方向变为3->2->1，然后将
// 1作为下一个递归链接的开始即可。

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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == NULL) return NULL;
        if (k == 0 || k == 1) return head;
        
        int i = 0;
        ListNode *node = head;
        while (node != NULL)
        {
            i++;
            node = node->next;
        }
        
        if (i < k) return head;
        
        ListNode *currentNode = head;
        ListNode *postNode = currentNode->next;
        int w = 0;
        ListNode *temp = NULL;
        while (w < k - 1)
        {
            temp = postNode->next;
            postNode->next = currentNode;
            currentNode = postNode;
            postNode = temp;
            w++;
        }
        
        head->next = reverseKGroup(temp, k);
        head = currentNode;
        
        return head;
    }
};