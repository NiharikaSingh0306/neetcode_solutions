class Solution {
public:
    int n, m;

    void dfs(vector<vector<int>> &heights,
             vector<vector<int>> &ocean,
             int x, int y) {

        ocean[x][y] = 1;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for(int k = 0; k < 4; k++) {

            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }

            if(ocean[nx][ny] == 1) {
                continue;
            }

            if(heights[nx][ny] < heights[x][y]) {
                continue;
            }

            dfs(heights, ocean, nx, ny);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        n = heights.size();
        m = heights[0].size();

        vector<vector<int>> pac(n, vector<int>(m, 0));
        vector<vector<int>> atl(n, vector<int>(m, 0));

        // Pacific

        // TOP ROW
        for(int j = 0; j < m; j++) {
            dfs(heights, pac, 0, j);
        }

        // LEFT COLUMN
        for(int i = 0; i < n; i++) {
            dfs(heights, pac, i, 0);
        }

        // Atlantic

        // BOTTOM ROW
        for(int j = 0; j < m; j++) {
            dfs(heights, atl, n - 1, j);
        }

        // RIGHT COLUMN
        for(int i = 0; i < n; i++) {
            dfs(heights, atl, i, m - 1);
        }

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(pac[i][j] == 1 && atl[i][j] == 1) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};