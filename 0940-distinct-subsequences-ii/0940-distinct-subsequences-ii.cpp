class Solution {
        const int mod = 1e9 + 7 ;
private:
    int f(string & s ,int ind , vector<int> & prev , vector<long long > &dp){
        if(ind == 0){
            return 1 ;
        }
        if(dp[ind] != -1 ) return dp[ind];
        long long ans = 2 * f(s,ind-1,prev,dp) % mod ;
        if(prev[ind-1] != -1){
            ans -= f(s,prev[ind-1],prev,dp);

             if (ans < 0)
                ans += mod;
        }
        return dp[ind] = ans; 
    }
public:
    int distinctSubseqII(string s) {
        int n = s.length();
        vector<int> prev(n,-1);
        vector<int> last(26,-1);

        for(int i =0 ; i<n ; i++){
            prev[i] = last[s[i]-'a'];
            last[s[i]-'a'] = i;
        }

        vector<long long >dp(n+1,-1);
        return (f(s,n,prev,dp)-1+mod)%mod;

    }
};