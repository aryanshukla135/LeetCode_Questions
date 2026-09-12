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
           // cout<<index<<endl;
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
        vector<int> dp(n,-1);
        int ans = solve(arr,0,k,dp);
        return ans ;
    }
};