/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)    return head;
        ListNode* curr = head;
        int c = 0;
        while(curr){
            ++c;
            curr = curr->next;
        }
        
        c -= n;
        if(c == 0)  return head->next;
        
        curr = head;
        while(c > 1){
            --c;
            curr = curr->next;
        }
        // ListNode* tmp = curr->next;
        curr->next = curr->next->next;
        // delete tmp;
        
        return head;
    }
};