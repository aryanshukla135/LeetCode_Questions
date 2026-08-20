class Solution {
private:
    bool f(vector<int>&nums,int target , int i,vector<vector<int>>& dp){
         if(target == 0) return true ;

         if(i ==0 ) return target == nums[0];

         if(dp[i][target] != -1) return dp[i][target];

         int nottake = f(nums,target,i-1,dp);
         int take = false;

         if(target >= nums[i]){
            take = f(nums,target -nums[i] , i-1,dp);
         }

         return dp[i][target] = take || nottake;
    }

public:
    bool canPartition(vector<int>& nums) {
         int n = nums.size();
         int totalsum = 0;
         for(int i : nums) totalsum += i;
         if(totalsum % 2 != 0) return false;

         int target = totalsum/2;
         vector<vector<int>> dp(n,vector<int>(target+1,-1));
    
         return f(nums,target,n-1,dp);

    }
};