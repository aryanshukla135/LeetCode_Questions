class Solution {
private:
    int f(int n , vector<int> & cuts, int i ,int j,vector<vector<int>> &dp){
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;

        for(int ind = i ;ind <= j ; ind++){
            int cost = cuts[j+1] - cuts[i-1] + f(n,cuts,i,ind -1,dp) + f(n,cuts,ind + 1 , j,dp);
            mini = min(mini,cost);
        }
        return dp[i][j] =  mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m+1,vector<int> (m+1,-1));

        return f(n,cuts,1,cuts.size() - 2,dp);
    }
};