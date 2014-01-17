
// Author:SatanWoo(Ziqi Wu)
// Github:satanwoo.github.io
// Weibo:@吴中生有正版

// 这题就是把链表拆分成俩个部分即可。然后后部分倒序，然后利用归并的思想即可。


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
    void reorderList(ListNode *head) {
        if (head == NULL) return;
        if (head->next == NULL) return;
        
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        vector<ListNode *>firstPart;
        vector<ListNode *>secondPart;
        
        firstPart.push_back(head);
        while (fast->next != NULL)
        {
            fast = fast->next;
            if (fast->next != NULL) 
            {
                fast = fast->next;
                slow = slow->next;
                firstPart.push_back(slow);
            }
        }
        
        ListNode *temp = slow->next;
        while(true) 
        {
            secondPart.push_back(temp);
            if (temp == fast) break;
            temp = temp->next;
        }
        std::reverse(secondPart.begin(), secondPart.end());
        
        int indexA = 1, indexB = 1;
        head = firstPart[0];
        head->next = secondPart[0];
        
        ListNode *tempNode = head->next;
        
        while(indexA < firstPart.size() && indexB < secondPart.size())
        {
            tempNode->next = firstPart[indexA++];
            tempNode->next->next = secondPart[indexB++];
            tempNode = tempNode->next->next;
        }
        
        for (int i = indexA; i < firstPart.size(); i++) 
        {
            tempNode->next = firstPart[i];
            tempNode = tempNode->next;
        }
        
        for (int i = indexB; i < secondPart.size(); i++)
        {
            tempNode->next = secondPart[i];
            tempNode = tempNode->next;
        }
        
        tempNode->next = NULL;
    }
};