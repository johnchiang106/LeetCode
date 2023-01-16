class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* prev = NULL, *curr = head, *forward;

        if(!possible(head, k)){
            return head;
        }

        for(int i = 0; i < k; ++i){
            forward = curr->next, curr->next = prev, prev = curr, curr = forward;
        }

        head->next = reverseKGroup(curr, k);

        return prev;
    }

    bool possible(ListNode* head, int k){
        ListNode* temp = head;

        while(temp != NULL){
            temp=temp->next;

            if(--k == 0){
                return true;
            }
        }

        return false;
    }
};