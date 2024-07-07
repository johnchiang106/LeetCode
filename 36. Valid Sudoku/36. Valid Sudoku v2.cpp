#define ROW 0
#define COLUMN 1
#define SUB_BOX  2

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool check[3][9][9] = {false};
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                char c = board[i][j] - '1';
                int p = 3*(i/3) + j/3;
                if(c != '.' - '1'){
                    if(check[ROW][i][c] || check[COLUMN][j][c] || check[SUB_BOX][p][c])  return false;
                    check[ROW][i][c] = true;
                    check[COLUMN][j][c] = true;
                    check[SUB_BOX][p][c] = true;
                }
            }
        }
        return true;
    }
};