class Solution {
public:
    void dfs(vector<vector<char>> &grid,int i,int j){
        //bc
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()){
            return;
        }
        if(grid[i][j]=='0'){
            return ;
        }
        //mark visted
        grid[i][j]='0';

        dfs(grid,i,j-1);//up
        dfs(grid,i,j+1);//down;
        dfs(grid,i+1,j);//right
        dfs(grid,i-1,j);//left

    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};
