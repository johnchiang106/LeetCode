class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)   return head;
        ListNode *h = nullptr, *last, *prev = head, *curr;
        while(prev && prev->next){
            curr = prev->next;
            if(prev->val == curr->val){
                while(curr && prev->val == curr->val){
                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                }
                delete prev;
            }
            else if(!h){
                h = prev;
                last = prev;
            }
            else{
                last->next = prev;
                last = prev;
            }
            prev = curr;
        }
        if(prev) {
            if(!h)  h = prev;
            else    last->next = prev;
        }
        else if(h)
            last->next = nullptr;
        return h;
    }
};