class Solution {
public:
    int totalNQueens(int n) {
        for(int x = 0; x < n; x++){
            board.insert({x,0});
            placeQueen(n);
            board.erase({x,0});
        }
        return sols.size();
    }
private:
    set<set<pair<int,int>>> sols;
    set<pair<int,int>> board;
    
    void placeQueen(int& n){
        int y = board.size();
        for(int x = 0; x < n; x++){
            if(!conflict({x,y})){
                board.insert({x,y});
                placeQueen(n);
                board.erase({x,y});
            }
        }

        if(n == board.size())   sols.insert(board);

        return;
    }
    
    bool conflict(pair<int,int> newQ){
        for(auto& q: board){
            if(q.first == newQ.first || 
               q.second == newQ.second || 
               q.first + q.second == newQ.first + newQ.second || 
               q.first - q.second == newQ.first - newQ.second)
                return true;
        }
        return false;
    }
};