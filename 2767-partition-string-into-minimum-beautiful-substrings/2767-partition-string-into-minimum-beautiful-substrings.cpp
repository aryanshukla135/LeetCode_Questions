class Solution {
private:
     bool ispossible(string s) {
        long long num = 0;
        for (char ch : s) {
            num = num * 2 + (ch - '0');
        }
        while (num > 1 && num % 5 == 0) {
            num /= 5;
        }
        return num == 1;
    }
    int f(string & s , int i , vector<int> & dp){
        if( i== s.length()){
            return 0;
        }
        if(s[i] == '0'){
            return 100000;
        }
        if(dp[i] != -1){
            return dp[i];
        } 
        string prev = "";
        long long mini = 100000 ;
        for(int ind =i ; ind<s.length() ;ind++){
            prev += s[ind];
            if(ispossible(prev)){
                long long count = 1 + f(s, ind + 1 ,dp);
                mini = min(mini, count);
            }
        }
       
       return dp[i] =  mini;
    }
public:
    int minimumBeautifulSubstrings(string s) {
        int n = s.length();
        int i = 0 ;
        vector<int> dp(n,-1);
        int ans = f(s,i,dp);
        return ans >= 100000 ? -1 :ans ;
    }
};