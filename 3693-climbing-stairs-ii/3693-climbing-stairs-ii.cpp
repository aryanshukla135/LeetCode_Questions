class Solution {
private:
    typedef long long ll;
    int solve(vector<int> & costs , int n , int i, vector<int> & dp ){
        if(i >= n - 1 ){
            return 0 ;
        }
        ll first = 1e8;
        ll second = 1e8;
        ll third = 1e8;

        if(dp[i] != -1){
            return dp[i];
        }

        if(i + 1 < n){
            int idx = i + 1 ;
            first = costs[idx] + 1 + solve(costs,n,i+1,dp);
        }
        if(i + 2 < n){
            int idx = i + 2 ;
            second = costs[idx] + 4 + solve(costs,n,i+2,dp);
        }
        if(i + 3 < n){
            int idx = i + 3 ;
            third = costs[idx] + 9 + solve(costs,n,i+3,dp);
        }

        return dp[i] = min({first,second,third});
    }
public:
    int climbStairs(int n, vector<int>& costs) {

        costs.insert(costs.begin(), 0);
        n = costs.size();
        vector<int> dp(n, 1e9);
        dp[n - 1] = 0;

        for (int i =n-2; i>= 0; i--) {

            int first = 1e9;
            int second = 1e9;
            int third = 1e9;

            if (i + 1 < n) {
                first = costs[i+1] + 1 + dp[i+1];
            }

            if (i + 2 < n) {
                second = costs[i+2] + 4 + dp[i+2];
            }

            if (i + 3 < n) {
                third = costs[i+3] + 9 + dp[i+3];
            }

            dp[i] = min({first, second, third});
        }

        return dp[0];
    }
};
