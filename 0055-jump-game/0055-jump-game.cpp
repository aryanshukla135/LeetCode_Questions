class Solution {
private:
    bool f(vector<int>& nums, int i ,vector<int> & dp){
        if(i == nums.size()-1) return true ;
        if(nums[i] == 0) return false; 
        if(dp[i] != -1) return dp[i];

        for(int ind =1 ; ind<=nums[i]; ind++){
            if(i + ind < nums.size()){
               if(f(nums,i + ind,dp)==true){
                  return dp[i] = true ;
               }                                                                  
            }
        }
        return dp[i] = false ;
        
    }
public:
    bool canJump(vector<int>& nums) {
         int n = nums.size();
         vector<int> dp(n,-1);

         return f(nums,0,dp);

    }
};