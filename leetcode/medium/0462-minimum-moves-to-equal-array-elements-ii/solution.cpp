class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mid = nums[n/2];
        int ans =0 ;
        for(int i =0 ; i<n/2; i++){
            ans += (mid - nums[i]);
        }
        for(int i = n/2 ; i<n ; i++){
            ans += (nums[i] - mid);
        }
        return ans ;
    }
};