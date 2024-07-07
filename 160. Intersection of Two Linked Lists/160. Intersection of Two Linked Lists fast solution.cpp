class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1 = headA, *t2 = headB;
        int l1 = 1, l2 = 1;
        while (t1->next){
            ++l1;
            t1 = t1->next;
        }
        while (t2->next){
            ++l2;
            t2 = t2->next;
        }
        if(t1 != t2)    return NULL;
        
        if(l2 > l1)
            for(int i = 0; i < l2-l1; ++i)  headB = headB->next;
        else
            for(int i = 0; i < l1-l2; ++i)  headA = headA->next;
        
        while (headA != headB){
            headB = headB->next;
            headA = headA->next;
        }
        return headA;
    }
};