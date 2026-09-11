class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        int startRow = 0;
        int startCol = 0;
        int endRow = row - 1;
        int endCol = col - 1;

        int total = row * col;
        int count = 0;

        vector<int> ans;

        while(count < total) {

            // Left -> Right
            for(int index = startCol; 
                index <= endCol && count < total; 
                index++) {

                ans.push_back(matrix[startRow][index]);
                count++;
            }
            startRow++;

            // Top -> Bottom
            for(int index = startRow; 
                index <= endRow && count < total; 
                index++) {

                ans.push_back(matrix[index][endCol]);
                count++;
            }
            endCol--;

            // Right -> Left
            for(int index = endCol; 
                index >= startCol && count < total; 
                index--) {

                ans.push_back(matrix[endRow][index]);
                count++;
            }
            endRow--;

            // Bottom -> Top
            for(int index = endRow; 
                index >= startRow && count < total; 
                index--) {

                ans.push_back(matrix[index][startCol]);
                count++;
            }
            startCol++;
        }

        return ans;
    }
};
