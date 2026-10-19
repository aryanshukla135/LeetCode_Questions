class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int f = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int h = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
        
        vector<int> ans ;
       for(int i = f ; i<h ; i++){
          ans.push_back(i);
       } 
       return ans ;       
    }
};