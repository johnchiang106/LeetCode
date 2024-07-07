class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)   return NULL;
        Node* ptr = head;
        while (ptr) {
            Node* newNode = new Node(ptr->val);
            newNode->next = ptr->next;
            ptr->next = newNode;
            ptr = newNode->next;
        }
        ptr = head;
        
        while (ptr) {
            if (ptr->random)
                ptr->next->random = ptr->random->next;
            ptr = ptr->next->next;
        }
        
        ptr = head;
        Node* newPtr = head->next, *oldHead = newPtr;
        
        while (ptr) {
            ptr->next = ptr->next->next;
            if (newPtr->next)
                newPtr->next = newPtr->next->next;
            ptr = ptr->next;
            newPtr = newPtr->next;
        }
        
        return oldHead;
    }
};