class Solution {
public:
    int solve(vector<int>nums,int start,int end,vector<int>&dp){
        if(end<start){
            return 0;
        }
        
        if(dp[end]!=-1){
            return dp[end];
        }
        int inc=nums[end]+solve(nums,start,end-2,dp);
        int exc=solve(nums,start,end-1,dp);

        dp[end]=max(inc,exc);
        return dp[end];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        if(n==1){
            return nums[0];
        }

        int ans1=solve(nums,0,n-2,dp1);
        int ans2=solve(nums,1,n-1,dp2);
        return max(ans1,ans2);

    }
};
