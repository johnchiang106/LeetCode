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
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        set<ListNode*> s;
        while(head->next){
            s.insert(head);
            head = head->next;
            if(s.count(head))   return true;
        }
        return false;
    }
};