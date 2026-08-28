class Solution {
private:
    int solve(vector<int> & nums, int target ,int ind,vector<vector<int>> &dp){
         if(ind < 0) {
            if(target == 0)
                return 0;
            return INT_MIN;
        }
        if(dp[ind][target] != -1) return dp[ind][target]; 
        int nottake = solve(nums,target,ind-1,dp);
        int take = solve(nums,target ^ nums[ind],ind-1,dp);

        if(take != INT_MIN){
            take++;
        }

        return dp[ind][target] = max(take,nottake);
    }
public:
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
       
        vector<vector<int>> dp(n, vector<int>(1 << 14, -1)); 
        int ans = solve(nums,target,nums.size()-1,dp);
        if(ans < 0) return -1;

        return  n - ans;

    }
};
// in this if we find maxlength of subsequence with equal to taget then we will easily find the answer