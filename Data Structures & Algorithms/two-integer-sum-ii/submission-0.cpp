class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;
        vector<int> ans;
int sum=0;
        while(i<j){
            sum=numbers[i]+numbers[j];

            if(sum==target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
            else{
                if(sum>target){
                j--;
            }
            if(sum<target){
                i++;
            }
            }
            
        }
        return ans;
    }
};
