class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* n1 = l1, *n2 = l2, *ans = new ListNode(), *last = ans;
        int v = 0;
        while(n1 || n2 || v != 0){
            if(n1 && n2)    v += n1->val + n2->val;
            else if(n1) v += n1->val;
            else if(n2) v += n2->val;

            ListNode* newN = new ListNode(v % 10);
            last->next = newN, last = newN;
            if(n1)  n1 = n1->next;
            if(n2)  n2 = n2->next;

            v /= 10;
        }
        last = ans->next;
        delete ans;
        return last;
    }
};