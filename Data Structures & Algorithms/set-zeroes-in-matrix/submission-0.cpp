class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();

        vector<int> rowZ(row,0);
        vector<int> colZ(col,0);

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    rowZ[i]=1;
                    colZ[j]=1;
                }

            }
        }

        //common zero areaz
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(rowZ[i]|| colZ[j]){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
