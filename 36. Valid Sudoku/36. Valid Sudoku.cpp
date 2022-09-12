class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool check[9] = {false};
        for(vector<char>& v: board){
            for(char& c: v){
                if(c != '.'){
                    if(check[c - '1'])  return false;
                    check[c - '1'] = true;
                }
            }
            for(int i = 0; i < 9; ++i)  check[i] = false;
        }
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[j][i] != '.'){
                    if(check[board[j][i] - '1'])  return false;
                    check[board[j][i] - '1'] = true;
                }
            }
            for(int k = 0; k < 9; ++k)  check[k] = false;
        }
        for(int i = 0; i < 9; ++i){
            int p = 3*(i/3), p2 = 3*(i%3);
            for(int j = p; j < p+3; ++j){
                for(int k = p2; k < p2+3; ++k){
                    if(board[j][k] != '.'){
                        if(check[board[j][k] - '1'])  return false;
                        check[board[j][k] - '1'] = true;
                    }
                }
            }
            for(int k = 0; k < 9; ++k)  check[k] = false;
        }
        return true;
    }
};