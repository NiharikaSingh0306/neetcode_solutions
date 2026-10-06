class Solution {
public:
    int solveMem(string s, int i,int j,vector<vector<int>>&dp){
        if(i>=j){
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]!=s[j]){
            return dp[i][j]=false;
        }

       return  dp[i][j]=solveMem(s,i+1,j-1,dp);
    }

    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,false));
        int maxlen=1;
        int start=0;

        /*for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j,dp)){
                    int len=j-i+1;
                    if(len>maxlen){
                        maxlen=len;
                        start=i;
                    }
                }
            }
        }*/

        // TABULATION  SOL:string badi hai,tle de raha hai
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=len+i-1;
                if(s[i]==s[j]){
                    if(len==2){
                        dp[i][j]=true;
                    }
                    else{
                        dp[i][j]=dp[i+1][j-1];
                    }
                }
                if(dp[i][j]==true && len>maxlen){
                    maxlen=len;
                    start=i;
                }
            }
        }

        return s.substr(start,maxlen);



    }
};
