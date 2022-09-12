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
    bool isPalindrome(ListNode* head) {
        ListNode* ori = head;
        stack<int> s;
        int listSize = 1;
        while(head->next){
            listSize++;
            head = head->next;
        }
        head = ori;
        int i = 0;
        while(i < listSize/2){
            s.push(head->val);
            head = head->next;
            ++i;
        }
        if(listSize % 2 == 1){
            head = head->next;
            ++i;
        }
        while(i < listSize){
            if(s.top() != head->val)    return false;
            s.pop();
            head = head->next;
            ++i;
        }
        return true;
    }
};