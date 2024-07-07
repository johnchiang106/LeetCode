class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        ListNode* iter = head;
        while (iter != NULL) {
            res <<= 1;
            res |= iter->val;
            iter = iter->next;
        }
        return res;
    }
};