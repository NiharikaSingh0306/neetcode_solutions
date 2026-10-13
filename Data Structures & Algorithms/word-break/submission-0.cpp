class Solution {
public:
    int solve(string s,int index,unordered_set<string> &searchdict,vector<int>&dp){
        if(index==s.size()){
            return 1;
        }
        if(dp[index]!=-1){
            return dp[index];
        }

        string tofind="";
        for(int i=index;i<s.size();i++){
            tofind+=s[i];
            if(searchdict.count(tofind)){
                if(solve(s,i+1,searchdict,dp)){
                    return dp[index]=1;
                }
            }
        }
      
        return dp[index]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string> searchdict(wordDict.begin(),wordDict.end());
        vector<int> dp(s.size(),-1);
        return solve(s,0,searchdict,dp);
    }
};
