class Solution {
private:
    int f(vector<int> &nums,int target,int i,vector<vector<int>>& dp ){
        if(target == 0){
            return 0 ;
        }
        if(i<0){
            return -1e8;
        }
        if(dp[i][target] != -1) return dp[i][target];
        int take = -1e8;

        if(target-nums[i] >=0){
            int l  = f(nums,target-nums[i],i-1,dp);
            if(l != -1e8){
               take = l+1;
            }
        }
        int nottake = 0 + f(nums,target,i-1,dp);

        return dp[i][target] = max(take,nottake);
    }
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        // declare 2d dp 
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        int ans = f(nums,target,n-1,dp);
        if(ans<0){
            return -1;
        }
        return ans ;
    }
};