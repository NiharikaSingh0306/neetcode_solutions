class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int min=0;
        int fresh=0;


        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};

        while(!q.empty() && fresh>0){

            int size=q.size();
            for(int i=0;i<size;i++){
                auto [x,y]=q.front();
                q.pop();

                for(int k=0;k<4;k++){
                    int nx=x+dx[k];
                    int ny=y+dy[k];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                        continue;
                    }

                    if(grid[nx][ny]!=1){
                        continue;
                    }

                    grid[nx][ny]=2;
                    fresh--;

                    q.push({nx,ny});
                }
            }
            min++;

        }

        if(fresh>0){
            return -1;
        }
        else
        {
            return min;
        }



    }
};
