/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *left = head, *right = head, *temp;
        while(left->next && left->next->next){
            left = left->next->next;
            right = right->next;
        }
        temp = right;
        right = right->next;
        temp->next = NULL;
        
        head = sortList(head);
        right = sortList(right);
        //1 2 7    -1 0 3 5 6
        //-1 0 3 5 6    1 2 7
        //-1 0 1 2 7    3 5 6
        //-1 0 1 2 3 5 6    7
        
        if(head->val < right->val)   left = head;
        else    left = right, right = head, head = left;
        
        while(left && right){
            while(left->val < right->val && left->next
                  && left->next->val < right->val){
                left = left->next;
            }
            temp = left->next;
            left->next = right;
            left = right;
            right = temp;
        }
        return head;
    }
};