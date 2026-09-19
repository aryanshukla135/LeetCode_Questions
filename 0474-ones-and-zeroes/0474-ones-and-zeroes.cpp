class Solution {
private: 
    int solve(vector<int> & zeros , vector<int> & one , int i, int m , int n, vector<vector<vector<int>>>& dp  ){
        if(i >= zeros.size()){
            return 0 ;
        }
        if(dp[i][m][n] != -1) return dp[i][m][n];
        int nottake = solve(zeros,one,i+1,m,n,dp);
        int take = 0 ;
        if(zeros[i] <= m && one[i] <=n){
            take = 1 + solve(zeros,one,i+1,m-zeros[i],n - one[i],dp);
        }
        return dp[i][m][n] = max(take,nottake);
    }
    
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<int> zeros ;
        vector<int> one ;
        int x = strs.size();
        vector<vector<vector<int>>> dp(x,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        for(int i =0 ; i<x ; i++){
            int y = strs[i].size();
            int o = 0;
            int z = 0;
            for(int j = 0 ; j<y ; j++){
                if(strs[i][j] == '1'){
                    o++;
                }else{
                    z++;
                }
            }
            zeros.push_back(z);
            one.push_back(o);
        }
        int ans = solve(zeros,one,0,m,n,dp);


    return ans ; 
    }
};