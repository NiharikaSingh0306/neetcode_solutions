class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num(nums.begin(),nums.end());

        int lon=0;

        for(int k:num){
            if(num.find(k-1)==num.end()){
                int cur=k;
                int len=1;

                while(num.find(cur+1)!=num.end()){
                cur++;
                len++;

            }
            lon=max(len,lon);
            }
            
            
        
            
        }
        return lon;

        

        
    }
};
