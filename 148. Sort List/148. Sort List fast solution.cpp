class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* mid = findMid(head);
        if(mid == head)	return head;
        head = sortList(head);
        mid = sortList(mid);
        return mergeLists(head, mid);
    }
private:
    ListNode* findMid(ListNode* head){
        ListNode* slow = head, *fast = head->next;
        if(!fast)   return head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        return fast;
    }
    ListNode* mergeLists(ListNode* h1, ListNode* h2){
        ListNode* head = new ListNode(), *curr = head;
        while(h1 && h2){
            if(h1->val < h2->val){
                curr->next = h1;
                h1 = h1->next;
            }
            else{
                curr->next = h2;
                h2 = h2->next;
            }
            curr = curr->next;
        }
        if(h1)	curr->next = h1;
        else	curr->next = h2;
        curr = head->next;
        delete head;
        return curr;
    }
};