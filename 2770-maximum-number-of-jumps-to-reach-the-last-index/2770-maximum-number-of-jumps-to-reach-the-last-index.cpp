class Solution {
private:
    int solve(vector<int> & nums , int idx , int target,vector<int> & dp){
        if(idx == nums.size() - 1) return 0 ;

        if(dp[idx] != -1) return dp[idx];
        
        int maxi = -1e9;
        for(int i = idx+1 ; i<nums.size() ; i++){
            int val = nums[i] - nums[idx];
            if(val >= (-1 * target) && val <= target ){
               maxi = max(maxi,1+solve(nums,i,target,dp));
            }
        }
        return dp[idx] = maxi;
    }
public:
    int maximumJumps(vector<int>& nums, int target) {

        int n = nums.size();
        vector<int> dp(n,-1);
        int ans =  solve(nums,0,target,dp);
        if(ans < 0){
           return -1;
        }
        return ans ;
    }
};