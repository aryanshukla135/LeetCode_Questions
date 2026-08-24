class Solution {
private:
    int f(vector<int> & nums , int i , int t , vector<vector<int>> & dp){
        if(i ==0 ){
            if(t == 0 && nums[0] == 0) return 2 ;
            if(t == 0 || t == nums[0]) return 1 ; 
        
            return 0 ;

        }
        if(dp[i][t] != -1) return dp[i][t];
        int nottake = f(nums,i-1,t,dp);
        int take = 0 ;
        if(nums[i] <=t){
            take = f(nums,i-1,t-nums[i],dp);
        }
        return dp[i][t] = take + nottake ;

    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalsum = 0;
        for(auto it : nums) totalsum += it ;
         if (totalsum - target < 0)
            return 0;

        if ((totalsum - target) % 2 != 0)
            return 0;

        int t = (totalsum - target)/2;
        vector<vector<int>>dp(n,vector<int>(t+1,-1));
        return f(nums,n-1,t,dp);
    }
};