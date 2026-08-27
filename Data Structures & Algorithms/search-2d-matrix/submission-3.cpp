class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int col=matrix[0].size();

        int s=0;
        int e=rows*col-1;
        while(s<=e){
            int mid=s+(e-s)/2;

            //2d to 1d mapping
            int ele=matrix[mid/col][mid%col];

            if(ele==target){
                return true;
            }
            else if(ele>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return false;
        
    }
};
