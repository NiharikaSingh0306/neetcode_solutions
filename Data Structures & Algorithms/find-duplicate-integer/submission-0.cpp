class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int ,int> freq;
        int n=nums.size()-1;

        for(int i=0;i<nums.size();i++){
           
            if(freq.find(nums[i])!=freq.end()){
                return nums[i];
            }
            freq[nums[i]]++;
        }
        return 0;
    }
};
