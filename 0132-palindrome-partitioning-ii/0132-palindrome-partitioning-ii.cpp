class Solution {
private:
    bool ispallindrome(string & s){
        int i = 0;
        int j = s.length() - 1 ;
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
    int f(string & s ,int i ,vector<int> & dp){
        int n = s.length();
        if(i == n){
            return 0 ;
        }
        if(dp[i] != -1) return dp[i];
        int mini = INT_MAX;
        string prev = "";
        for(int j = i ; j<n ; j++){
            prev += s[j];
            if(ispallindrome(prev)){
                int part = 1 + f(s,j+1,dp);
                mini = min(mini,part);
            }
        }
        return dp[i] = mini;
    }
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n,-1);
        return f(s,0,dp) -1;
    }
};