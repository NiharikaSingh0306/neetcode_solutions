class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j) {

        if(i < 0 || i >= grid.size() ||
           j < 0 || j >= grid[0].size()) {
            return 0;
        }

        if(grid[i][j] == 0) {
            return 0;
        }

       
        int area = 1;

        
        grid[i][j] = 0;

        
        area += dfs(grid, i, j + 1); // right
        area += dfs(grid, i, j - 1); // left
        area += dfs(grid, i + 1, j); // down
        area += dfs(grid, i - 1, j); // up

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int maxArea = 0;

        for(int i = 0; i < grid.size(); i++) {

            for(int j = 0; j < grid[0].size(); j++) {

                if(grid[i][j] == 1) {

                    int area = dfs(grid, i, j);

                    maxArea = max(area, maxArea);
                }
            }
        }

        return maxArea;
    }
};