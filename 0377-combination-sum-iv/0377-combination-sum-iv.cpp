class Solution {
private:
    int f(vector<int> & nums , int i , int target,vector<vector<int>> & dp ){
        if(target == 0){
            return 1 ;
        }
        if(i >= nums.size() ){
            return 0 ;
        }
        if(dp[i][target] != -1) return dp[i][target];
        int ans =0 ;
        for(int i = 0 ; i<nums.size() ; i++){
             if(target - nums[i] >= 0){
                ans += f(nums,i,target-nums[i],dp);
             }  
        }
        return dp[i][target] = ans ;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(nums,0,target,dp);
    }
};