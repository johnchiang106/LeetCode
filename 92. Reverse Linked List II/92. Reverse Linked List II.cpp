class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)   return head;
        ListNode *first = new ListNode(), *prev, *curr = first, *temp, *front;
        first->next = head;
        right -= left-1;
        while(--left > 0)
            curr = curr->next;
        front = curr;
        prev = curr;
        curr = curr->next;
        while(right-- > 0){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        front->next->next = curr;
        front->next = prev;
        temp = first->next;
        delete first;
        return temp;
    }
};