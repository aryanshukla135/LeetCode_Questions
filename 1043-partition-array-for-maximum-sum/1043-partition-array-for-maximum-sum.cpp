class Solution {
    int solve(vector<int> & nums ,int ind ,int k,vector<int> & dp  ){
        if(ind >= nums.size()){
            return 0 ;
        }
        if(dp[ind] != -1) return dp[ind];
        int maxi = 0;
        int ans =0;
        for(int i =0 ; i<k ; i++ ){
            int index = ind + i ;
            if(index<nums.size()){
                maxi = max(maxi,nums[index]);
                int temp = maxi*(i+1);
                ans = max(ans,temp + solve(nums,index+1,k,dp));
            } 
        }
        return dp[ind] = ans ;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        int ans = solve(arr,0,k,dp);

        //// tabulation 
        for(int ind = n ; ind>=0 ; ind--){
            int maxi = 0;
            int ans = 0;
            for(int i = 0 ; i<k ; i++){
                int index = ind + i ;
                if(index<arr.size()){
                    maxi = max(maxi,arr[index]);
                    int temp = maxi*(i+1);
                    ans = max(ans,temp + dp[index+1]);
                } 
            }
            dp[ind] = ans ;
        }

        return dp[0] ;
    }
};