class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)   return head;
        ListNode* ans = head->next, *prev = NULL;
        while(head && head->next){
            ListNode* node = head->next;
            head->next = node->next;
            node->next = head;
            if(prev)    prev->next = node;
            prev = head;
            head = head->next;
        }
        return ans;
    }
};