class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prev, *curr = list1, *end = list2;
        b -= a-1;
        while(--a > 0)
            curr = curr->next;
        prev = curr->next;
        curr->next = list2;
        while(b-- > 0){
            curr = prev->next;
            delete prev;
            prev = curr;
        }
        while(end->next)
            end = end->next;
        end->next = curr;
        return list1;
    }
};