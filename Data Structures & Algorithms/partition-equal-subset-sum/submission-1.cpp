class Solution {
public:
    int solve(vector<int> &nums,int index,int target,vector<vector<int>>&dp){
        if(target==0){
            return true;
        }
        if(index==nums.size()){
            return false;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        int notTake=solve(nums,index+1,target,dp);
        int take=0;
        if(nums[index]<=target){
            take=solve(nums,index+1,target-nums[index],dp);
        }

        return dp[index][target]=(take|| notTake);//koi bhi ek side true hojaye
        
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;
        for(int num:nums){
            totalSum+=num;
        }

        if(totalSum%2!=0){//odd sum can be equally partitioned
            return false;
        }
        
        int target=totalSum/2;

        vector<vector<int>> dp(n,vector<int>(target+1,-1));

        return solve(nums,0,target,dp);
    }
};
