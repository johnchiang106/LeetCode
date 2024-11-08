class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = new ListNode(), *right = new ListNode();
        ListNode* curr = head, *l2 = left, *r2 = right;
        while(curr){
            if(curr->val < x){
                left->next = curr;
                left = curr;
            }
            else{
                right->next = curr;
                right = curr;
            }
            curr = curr->next;
        }
        if(r2->next){
            left->next = r2->next;
            right->next = nullptr;
        }
        curr = l2->next;
        delete l2;
        delete r2;
        return curr;
    }
};