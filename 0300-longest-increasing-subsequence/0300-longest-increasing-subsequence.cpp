class Solution {
private:
   int f(vector<int> & nums, int ind ,int prev_ind,vector<vector<int>> & dp ){
      if(ind == nums.size()){
         return 0;
      }
      if(dp[ind][prev_ind+1] != -1 ) return dp[ind][prev_ind+1];
      int len = 0 + f(nums,ind+1,prev_ind,dp);

      if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
         len = max(len,1 + f(nums,ind+1,ind,dp));
      }

      return dp[ind][prev_ind+1] = len ;
   }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));

        return f(nums,0,-1,dp);

    }
};