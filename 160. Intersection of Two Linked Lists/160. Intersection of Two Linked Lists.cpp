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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while(b){
            if(a == b)  return a;
            if(a->next) a = a->next;
            else{
                a = headA;
                b = b->next;
            }
        }
        return nullptr;
    }
};