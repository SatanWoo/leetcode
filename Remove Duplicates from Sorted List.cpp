// Author:SatanWoo(Ziqi Wu)
// Github:satanwoo.github.io
// Weibo:@吴中生有正版

// 这题唯一的难点，就是在于什么时候更新需要链接的点，由于我们是要动态删除，所以必须维护一个之前的节点
// currentInListNode和一个用来遍历的节点temp。那么我们什么时候更新这个currentInListNode节点呢？
// 那就是判断是否这个temp遍历的当前点是需要保留的。其实这里利用了一个逆向思维，就是更新保留点，而不是更新删除点。


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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;
        
        set<int>uniques;
        uniques.insert(head->val);
        
        ListNode *temp = head->next;
        ListNode *currentInListNode = head;
        while(temp != NULL)
        {
             if (uniques.find(temp->val) != uniques.end()) 
             {
                 currentInListNode->next = temp->next;
             }
             else 
             {
                uniques.insert(temp->val);
                currentInListNode = temp;
             }
             
             temp = temp->next;
        }
        
        return head;
    }
};