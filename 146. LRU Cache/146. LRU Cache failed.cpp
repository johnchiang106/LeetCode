class LRUCache {
public:
    LRUCache(int capacity) : maxSize(capacity) {}
    
    int get(int key) {
        if(m.find(key) == m.end())
            return -1;
        if(back->val != key){
            ListNode* curr = head, *temp;
            while(curr->next->val != key)
                curr = curr->next;
            temp = curr->next, curr->next = temp->next;
            back->next = temp, back = temp;
        }
        return m[key];
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            if(back->val != key){
                ListNode* curr = head, *temp;
                while(curr->next->val != key)
                    curr = curr->next;
                temp = curr->next, curr->next = temp->next;
                back->next = temp, back = back->next;
            }
        }
        else{
            back->next = new ListNode(key), back = back->next;
            if(m.size() == maxSize){
                ListNode* temp = head->next;
                head->next = temp->next;
                m.erase(temp->val);
                delete temp;
            }
        }
        m[key] = value;
        // back = back->next;
    }
private:
    unordered_map<int,int> m;
    int maxSize = 0;
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    ListNode* head = new ListNode(), *back = head;
};