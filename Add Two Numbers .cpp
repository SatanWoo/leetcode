// Author:SatanWoo(Ziqi Wu)
// Github:satanwoo.github.io
// Weibo:@吴中生有正版

// 这题有reverse吗?我感觉题目描述错了，不信你们试试，我reverse不能ac
// 反之就ac了，没难度的一题

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL || l2 == NULL) return NULL;
    
        vector<int> result;
        int carrier = 0;
        while(l1 && l2) {
            int value = 0;
            value += l1->val;
            value += l2->val;
            value += carrier;
            
            if (value >= 10) {
                value -= 10;
                carrier = 1;
            } else {
                carrier = 0;
            }
            result.push_back(value);
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1) {
            int value = 0;
            value += l1->val;
            value += carrier;
            if (value >= 10) {
                value -= 10;
                carrier = 1;
            } else {
                carrier = 0;
            }
            result.push_back(value);
            l1 = l1->next;
        }
        
        while(l2) {
            int value = 0;
            value += l2->val;
            value += carrier;
            if (value >= 10) {
                value -= 10;
                carrier = 1;
            } else {
                carrier = 0;
            }
            result.push_back(value);
            l2 = l2->next;
        }
        
        if (carrier == 1) {
            result.push_back(1);
        }
        
        return buildListFromVector(result);
    }
    
    ListNode* buildListFromVector(vector<int> vec) {
        if (vec.size() == 0) return NULL;
        
        int size = vec.size();
        
        ListNode *root = new ListNode(vec[0]);
        ListNode *previous = root;
        
        for (int i = 1; i < size;i++) {
            ListNode *nextNode = new ListNode(vec[i]);
            previous->next = nextNode;
            previous = previous->next;
        }
        
        return root;
    }
};