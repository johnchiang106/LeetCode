class Solution {
public:
    bool exist(vector<vector<char>>& board, string& word) {
        m = board.size(), n = board[0].size();
        end = word.end();
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(board[i][j] == word.front() && 
                    dfs(board, word.begin()+1, i, j))
                    return true;
        return false;
    }
    bool dfs(vector<vector<char>>& board, string::iterator curr, int i, int j){
        if(curr == end) return true;
        checked.set(n*i+j);
        if(i > 0 && !checked[n*(i-1)+j] && board[i-1][j] == *curr && 
            dfs(board, curr+1, i-1, j))
            return true;
        if(i+1 < m && !checked[n*(i+1)+j] && board[i+1][j] == *curr && 
            dfs(board, curr+1, i+1, j))
            return true;
        if(j > 0 && !checked[n*i+j-1] && board[i][j-1] == *curr && 
            dfs(board, curr+1, i, j-1))
            return true;
        if(j+1 < n && !checked[n*i+j+1] && board[i][j+1] == *curr && 
            dfs(board, curr+1, i, j+1))
            return true;
        checked.reset(n*i+j);
        return false;
    }
private:
    int m, n;
    bitset<36> checked;
    string::iterator end;
};