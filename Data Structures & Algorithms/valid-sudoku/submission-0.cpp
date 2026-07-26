class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> grid[9];

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){

                if(board[i][j]=='.'){
                    continue;
                }

                char num=board[i][j];

                if(row[i].count(num)){
                    return false;
                }
                else{
                    row[i].insert(num);
                }

                if(col[j].count(num)){
                    return false;
                }
                else{
                    col[j].insert(num);
                }


                int gridIn=(i/3)*3 +(j/3);
                if(grid[gridIn].count(num)){
                    return false;
                }
                else{
                    grid[gridIn].insert(num);
                }
            }
        } 
        return true;
    }
};
