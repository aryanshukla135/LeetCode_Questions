class Solution {
private:
    long long solve(int i , vector<int> & nums,vector<long long > & dp){
        int n = nums.size();
        if(i>=n) return 0 ;

        if(dp[i] != LLONG_MIN){
            return dp[i];
        }
        long long first = nums[i];
        long long take1 ;
        if(first % 3 == 0){
            take1 = first - solve(i+1,nums,dp);
        }else{
            take1 = first + solve(i+1 , nums,dp);
        }
         long long take2= LLONG_MIN;
        if(i+1 < n){
            long long sum = nums[i] + nums[i+1];

            if(sum % 3 ==0){
                take2 = sum - solve(i+2,nums,dp);
            }else{
                take2 = sum + solve(i+2,nums,dp);
            }
        }
        return dp[i] = max(take1,take2);
    }
public:
    long long maxDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long > dp(n,LLONG_MIN);
        return solve(0,nums,dp);
    }
};