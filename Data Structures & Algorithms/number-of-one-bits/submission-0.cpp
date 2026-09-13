class Solution {
public:
    int hammingWeight(uint32_t n) {
        vector<uint32_t> bin;
        while(n>0){
            bin.push_back(n%2);
            n=n/2;
        }
        reverse(bin.begin(),bin.end());
        int ans=0;
        for(int i=0;i<bin.size();i++){
            if(bin[i]==1){
                ans++;
            }
        }
        return ans;
    }
};
