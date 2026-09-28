class Solution {
private:
    bool solve(int i , string & s ,unordered_set<string>& st,vector<int> & dp){
        int n = s.length();
        if(i>=n){
            return true;
        }
        if(dp[i] != -1) return dp[i];
        for(int ind = i ; ind < n ; ind++){
           string str = s.substr(i, ind - i + 1);
            if (st.count(str)) {
                if (solve(ind + 1, s, st,dp)) {
                    return dp[i] = true;
                }
            }
        }
        return dp[i] =false ;

    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st ;
        vector<int> dp(s.length(),-1);
        for(string s : wordDict){
            st.insert(s);
        }
        return solve(0,s,st,dp);
    }
};