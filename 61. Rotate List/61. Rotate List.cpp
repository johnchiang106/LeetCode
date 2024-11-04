class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || !head)  return head;
        ListNode* right = head, *left = head;
        int j = k;
        while(right && k-- > 0)
            right = right->next;
        j %= j-k;
        if(j == 0 && !right)  return head;
        if(!right){
            right = head;
            while(right && j-- > 0)
                right = right->next;
        }
        while(right->next){
            right = right->next;
            left = left->next;
        }
        right->next = head;
        right = left->next;
        left->next = NULL;
        return right;
    }
};