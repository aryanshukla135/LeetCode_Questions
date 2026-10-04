class Solution {
private:
    bool solve(string & s , int i , int count ,vector<vector<int>> & dp){
        int n =s.length();
        if(i >= n){
            if(count == 0){
                return true;
            }else{
                return false;
            }
        }
        if(count < 0){
            return false;
        }
        if(dp[i][count] != -1){
          return dp[i][count];
        }

        bool open = false;
        bool close = false;
        bool empty = false;
        bool norm = false;

        if(s[i] == '('){
            norm = solve(s,i+1,count + 1 , dp);
        }
        else if(s[i] == ')'){
            norm = solve(s,i+1,count - 1 , dp);
        }
        else{
          open = solve(s,i+1,count + 1,dp);
          close = solve(s,i+1,count - 1,dp );
          empty = solve(s,i+1,count,dp);
        }
       
        return dp[i][count] = (open || close || empty || norm) ;
    }
public:
    bool checkValidString(string s) {
         int n = s.length();
         vector<vector<int>> dp(n,vector<int>(n+1,-1));
         return solve(s,0,0,dp);
    }
};