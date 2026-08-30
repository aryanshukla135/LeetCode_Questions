class Solution {
private:
    int f(vector<int> & nums ,int ind , int target,vector<vector<int>> & dp){
        if(target < 0 ) return 1e9;
        if(ind >= nums.size()){
            if(target == 0){
                return 0;
            }else{
                return 1e9;
            }
        }
        if(dp[ind][target] != -1) return dp[ind][target];

        int take = INT_MAX;
        int i = 1 ;
        int val = nums[ind];

        take = f(nums,ind+1,target-nums[ind],dp);

        while(val*2 <=target){
            val = val *2;
            take =min(take,i + f(nums,ind +1 , target - val,dp));
            i++;
        }
        i = 1;
        val = nums[ind];
        while(val/2 >=1){
            val = val/2;
            take =min(take,i + f(nums,ind +1 , target - val,dp));
            i++;
        }
        int nottake = f(nums,ind+1,target,dp);
        return dp[ind][target] = min(take,nottake);
    }
public:
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(sum +1 , -1));
        int ans =  f(nums,0,sum,dp);
        if(ans == 1e9){
            return -1;
        }
        return ans;
    }
};