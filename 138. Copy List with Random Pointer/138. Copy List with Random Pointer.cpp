class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)   return head;
        Node* ans = new Node(head->val), *curr = head, *curr2 = ans;
        unordered_map<Node*,Node*> m;
        m[head] = ans;
        while(curr->next){
            curr = curr->next;
            Node* n = new Node(curr->val);
            curr2->next = n;
            curr2 = n;
            m[curr] = curr2;
        }
        curr = head, curr2 = ans;
        while(curr){
            if(curr->random)
                curr2->random = m[curr->random];
            curr = curr->next, curr2 = curr2->next;
        }
        return ans;
    }
};