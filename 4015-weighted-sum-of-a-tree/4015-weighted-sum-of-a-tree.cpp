class Solution {
private:
    int finddepth(vector<int>&parent,vector<int> &dp,int node){
        if(dp[node] != -1){
            return dp[node];
        }
        if(parent[node] == -1){
            return 1 ;
        }

        int ans = 1 + finddepth(parent,dp,parent[node]);
        return dp[node] = ans ;
    }
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<int> dp(n,-1);
        int h= 0;
        for(int i =n-1 ; i>=0 ; i--){
            h = max(h,finddepth(parent,dp,i));
        }
        dp[0] = 1 ;
        long long  ans =0 ;
        for(int i =0 ; i<n ; i++){
            long long d = dp[i];
            long long  w = 1LL * nums[i] *(h-d+1);
            ans += w ;
        }
        return ans ;
    }
};