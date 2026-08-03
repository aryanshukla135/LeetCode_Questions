class Solution {
private: 
    int solve(vector<int>& A,vector<int>& dp,int i,int n ){
        if(i>=n)  return 0 ;

        if(dp[i] != INT_MIN) return dp[i];

        int one = A[i] - solve(A,dp,i+1,n);

        int two = INT_MIN;

        if(i+1 < n){
            two = A[i] + A[i+1] - solve(A,dp,i+2,n);
        }
        int three = INT_MIN;

        if(i+2 < n){
            three = A[i] + A[i+1] + A[i+2] - solve(A,dp,i+3,n);
        }

        return dp[i] = max(one,max(two,three));

    }
public:
    string stoneGameIII(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n,INT_MIN);

        int val = solve(A,dp,0,n);

        if(val>0){
            return "Alice";
        }else if(val<0){
            return "Bob";
        }else{
            return "Tie";
        }
    }
};