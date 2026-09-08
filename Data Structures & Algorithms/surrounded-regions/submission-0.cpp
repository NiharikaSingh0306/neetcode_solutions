class Solution {
public:
    int n,m;
    void dfs(vector<vector<char>>&board, int x,int y){
        if(x<0||x>=n||y<0||y>=m){
            return ;
        }
        if(board[x][y]!='O'){
            return;
        }

        board[x][y]='#';

        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};

        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];

            dfs(board,nx,ny);
        }


    }
    void solve(vector<vector<char>>& board) {
         n=board.size();
         m=board[0].size();

        // top and bottom rows
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                dfs(board,0,i);

            }
            if(board[n-1][i]=='O'){
                dfs(board,n-1,i);
            }
        }
        
        //right and left column
         for(int j=0;j<n;j++){
            if(board[j][0]=='O'){
                dfs(board,j,0);

            }
            if(board[j][m-1]=='O'){
                dfs(board,j,m-1);
            }
        }

        //capturing
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }


    }
};
