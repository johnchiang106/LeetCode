class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)   return nullptr;
        if(!head->next){
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
        ListNode* slow = head, *fast = head, *prev;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(prev)
            prev->next = nullptr;
        TreeNode* root = new TreeNode(slow->val);
        root->right = sortedListToBST(slow->next);
        root->left = sortedListToBST(head);
        return root;
    }
};