class Solution {
public:
    int solve(string s,int i,int j,vector<vector<int>>&dp){
        
        if(i>=j){
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]!=s[j]){
            return dp[i][j]=false;
        }
        dp[i][j]=solve(s,i+1,j-1,dp);
        return dp[i][j];

    }


    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,false));
        int count=0;

       /*for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j,dp)){
                    count++;
                }
            }
       }*/
       for(int i=0;i<n;i++){
        dp[i][i]=true;
       }
       for(int len=1;len<=n;len++){
        for(int i=0;i+len<=n;i++){
            int j=len+i-1;
            if(s[i]==s[j]){
                if(len<=2 || dp[i+1][j-1]){
                    dp[i][j]=true;
                    count++;
                }
            }
        }
       }



       return count;
        
        
    }
};
