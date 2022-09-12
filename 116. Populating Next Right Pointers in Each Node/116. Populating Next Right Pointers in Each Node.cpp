/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)   return root;
        
        queue<Node*> q1;
        Node *temp;
        int d = 1, count = 2;
        
        q1.push(root);
        while(!q1.empty()){
            temp = q1.front();
            if(temp->left){
                q1.push(temp->left);
                q1.push(temp->right);
            }
            q1.pop();
            if(count++ != pow(2,d))   temp->next = q1.front();
            else    d++;
        }
        
        return root;
    }
};