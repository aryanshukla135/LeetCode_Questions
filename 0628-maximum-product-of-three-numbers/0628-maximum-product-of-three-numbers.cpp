class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
       
        int ans = INT_MIN ;
        ans = max(ans , nums[n-1]*nums[n-2]*nums[n-3]);
        ans = max(ans,nums[0]*nums[1]*nums[2]);
        ans = max(ans,nums[0]*nums[1]*nums[n-1]);

        return ans ;
        
    }
};
// -10 -9 -1 -10 -20
// -5 -4 -1 -1 2 30
//-20 -10 -10 -9 -1