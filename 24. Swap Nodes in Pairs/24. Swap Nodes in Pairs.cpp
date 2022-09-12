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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)   return head;
        ListNode* ans = head->next;
        ListNode* preN = new ListNode();
        while(head && head->next){
            preN->next = head->next;
            head->next = preN->next->next;
            preN->next->next = head;
            preN = head;
            head = head->next;
        }
        return ans;
    }
};