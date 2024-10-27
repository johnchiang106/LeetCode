/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        char s = grid.size();
        isSame.resize(s, vector<char>(s, 1));
        check(grid, 0, 0, s);
        return helper(grid, 0, 0, s);
    }
private:
    Node* helper(vector<vector<int>>& grid, int i, int j, char& s){
        if(isSame[i][j] == s)  return new Node(grid[i][j], true);

        Node* curr = new Node(grid[i][j], false);
        char k = s/2;
        Node* n0 = helper(grid, i, j, k);
        Node* n1 = helper(grid, i+k, j, k);
        Node* n2 = helper(grid, i, j+k, k);
        Node* n3 = helper(grid, i+k, j+k, k);
        curr->topLeft = n0;
        curr->bottomLeft = n1;
        curr->topRight = n2;
        curr->bottomRight = n3;
        return curr;
    }
    void check(vector<vector<int>>& grid, int i, int j, char& s){
        if(s == 1)  return;
        char k = s/2;
        check(grid, i, j, k);
        check(grid, i+k, j, k);
        check(grid, i, j+k, k);
        check(grid, i+k, j+k, k);
        if(isSame[i][j] == k
        && grid[i][j] == grid[i][j+k] && isSame[i][j] == isSame[i][j+k]
        && grid[i][j] == grid[i+k][j] && isSame[i][j] == isSame[i+k][j]
        && grid[i][j] == grid[i+k][j+k] && isSame[i][j] == isSame[i+k][j+k])
            isSame[i][j] <<= 1;
        return;
    }
    vector<vector<char>> isSame;
};