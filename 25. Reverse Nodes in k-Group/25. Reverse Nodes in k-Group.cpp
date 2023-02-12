class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int& k) {
        if(!head)   return head;

        ListNode* prev = NULL, *curr = head, *temp = head;
        for(int i = 0; i < k; ++i){
            if(!temp)
                return head;
            temp = temp->next;
        }

        for(int i = 0; i < k; ++i){
            temp = curr->next, curr->next = prev, prev = curr, curr = temp;
        }

        head->next = reverseKGroup(curr, k);
        return prev;
    }
};