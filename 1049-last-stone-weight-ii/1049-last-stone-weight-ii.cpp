class Solution {
private: 
    int solve(vector<int> & nums , int ind , int totalSum,vector<vector<int>> & dp){
        if(ind<0 || totalSum == 0){
            return 0;
        }
        if(dp[ind][totalSum] != -1 ) return dp[ind][totalSum];
        int nottake = solve(nums,ind-1,totalSum,dp);
        int take = 0;
        if(totalSum >= nums[ind]){
            take = nums[ind] + solve(nums,ind-1,totalSum - nums[ind],dp);
        }

        return dp[ind][totalSum] = max(take,nottake);
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int totalsum = 0;
        for(int&  i : stones){
            totalsum += i;
        }
        vector<vector<int>> dp(n,vector<int>(totalsum/2 +1 , -1 ));
        int s1 = solve(stones,n-1, totalsum/2,dp);
        return totalsum - 2*s1 ;
    }
};

// s1 + s2 = total 
// |s1 - s2 | = | total - 2*s2|



