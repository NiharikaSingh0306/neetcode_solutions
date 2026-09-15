class Solution {
public:
    int solveMem(int n,vector<int> &dp){
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }

        return dp[n]=solveMem(n>>1,dp)+(n&1);
        
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        vector<int> dp(n+1,-1);
        
       for(int i=0;i<=n;i++){
        ans[i]=solveMem(i,dp);
       }
       return ans;


    }
};
