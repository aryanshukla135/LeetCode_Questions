class Solution {
private:
    int solve(vector<int> & days,vector<int> & costs ,int ind ,vector<int> & passday,vector<int> & dp){
        if(ind >= days.size()) return 0 ;
        if(dp[ind] != -1) return dp[ind];
   
        int mini = 1e9;
        for(int i =0 ; i<costs.size() ; i++){
            int cost = costs[i];
            int target = days[ind] + passday[i] - 1;
            int j = ind ;
            for( ; j < days.size() ; j++){
                if(days[j] > target){
                    break;
                }
            }
            mini = min(mini,cost + solve(days,costs,j,passday,dp));
        }
        return dp[ind] = mini;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> passday = {1,7,30};
        vector<int> dp(days.size(), -1);
        return solve(days,costs,0,passday,dp);
    }
};