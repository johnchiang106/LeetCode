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
    void reorderList(ListNode* head) {
        ListNode *right = head, *left = head, *prev = nullptr, *tmp;
        while(right && right->next){
            right = right->next->next;
            left = left->next;
        }
        prev = left;
        left = left->next;
        prev->next = nullptr;
        while(left){
            tmp = left->next;
            left->next = prev;
            prev = left;
            left = tmp;
        }
        
        left = head;
        right = prev;
        while(left != right && left->next && right->next){
            tmp = right->next;
            right->next = left->next;
            left->next = right;
            left = right->next;
            right = tmp;
        }
        return;
    }
};