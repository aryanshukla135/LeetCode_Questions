class Solution {
private:
    int f(vector<int> & nums , int i,vector<int> & dp ){
        if(i == nums.size()-1) return 0 ;
        if(nums[i] == 0) return 1e9 ;
        if(dp[i] != -1) return dp[i];
        
        int mini = 1e9;
        for(int ind = 1 ; ind <= nums[i] ; ind++){
           
            if(ind+i < nums.size()){
                mini = min(mini,1+f(nums,i+ind,dp));
            }
        }
        return dp[i] = mini;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return f(nums,0,dp);
    }
};