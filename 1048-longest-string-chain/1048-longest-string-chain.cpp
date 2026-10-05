class Solution {
private:
    bool ispossible(string & s1 , string & s2 ){
        int n = s1.length();
        int m = s2.length();

        if(n != m +1 ){
            return false;
        }
        int i = 0 ;
        int j = 0 ;
        while(i < n && j < m ){
            if(s1[i] == s2[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        return  j == m ;
    }
public:
    int longestStrChain(vector<string>& words) {
        int n =words.size();
        vector<int> dp(n,1);
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.length() < b.length();
        });
        int maxi = INT_MIN ;

        for(int i = 0 ;i<n ; i++){
            dp[i] = 1 ;
            for(int prev = 0 ; prev < i ; prev++){
                if(ispossible(words[i],words[prev]) && dp[i] < dp[prev]+1){
                    dp[i] = dp[prev] + 1 ;
                }
            }
            maxi = max(maxi,dp[i]);
        }

    return maxi ;
    }
};