class Solution {
private:
    int f(vector<int> & nums ,int i , int d , vector<int> & maxArr,vector<vector<int>> & dp){
        int n = nums.size();
        if(d <= 1){
            return maxArr[i];
        }
        if(dp[i][d] != -1) return dp[i][d];
        int ans = INT_MAX;
        int maxi = INT_MIN;
        for(int ind = i ; ind<n ; ind++){
            if(n-ind >= d){
                maxi = max(maxi,nums[ind]);
                ans = min(ans,maxi + f(nums,ind+1,d-1,maxArr,dp));
            }
        }
        return dp[i][d] =  ans ;
    }
public:
    int minDifficulty(vector<int>& nums, int d) {
        int n = nums.size();
        vector<int> maxArr(n,0);
        vector<vector<int>> dp(n,vector<int>(d+1,-1));
       
        if(d > n){
           return -1;
        }
        

        maxArr[n-1] = nums[n-1];

        for(int i =n-2 ; i>=0 ; i--){
            maxArr[i] = max(maxArr[i+1],nums[i]);
        }
    
        return f(nums,0,d,maxArr,dp);


    }
};