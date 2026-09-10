class Solution {
private:
    long long f(vector<int> & nums , int ind,int sign,vector<vector<long long>> & dp){
        if(ind>=nums.size()){
            return 0;
        }
        if(dp[ind][sign] != -1 ) return dp[ind][sign];
        long long maxi = 0;
        if(sign ==0){
            long long  take = nums[ind] + f(nums,ind+1,1,dp);
            long long nottake = 0 + f(nums,ind+1,0,dp);
            maxi = max({maxi,take,nottake});
        }else{
            long long take = - nums[ind] + f(nums,ind + 1,0,dp);
            long long nottake = 0 + f(nums,ind+1,1,dp);
            maxi = max({maxi,take,nottake});
        }

        return dp[ind][sign] = maxi;
    }
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long >> dp(n+1,vector<long long>(2,0));
        //  return f(nums,0,0,dp); memorization will always give tle because of reuction call depth 
        long long prev0 = 0;
        long long prev1 = 0;

        for(int ind = n-1 ; ind>=0 ; ind--){
            for(int sign = 0 ; sign<2 ; sign++){
                long long maxi = 0;
                if(sign ==0){
                    long long  take = nums[ind] + prev1;
                    long long nottake = 0 + prev0;
                    maxi = max({maxi,take,nottake});
                }else{
                    long long take = - nums[ind] + prev0;
                    long long nottake = 0 + prev1;
                    maxi = max({maxi,take,nottake});
                }

               if(sign == 0){
                  prev0 = maxi;
               }else{
                  prev1 = maxi;
               }
            }
        }
        return prev0;
    }
};