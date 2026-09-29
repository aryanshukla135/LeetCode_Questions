class Solution {
private:
    bool solve(vector<vector<char>> & grid , int i ,int j ,int cnt,vector<vector<vector<int>>>& dp){
        if(i<0 || j<0 || cnt < 0){
            return false;
        }

        if(i==0 && j ==0 ){
            if(grid[i][j] == ')'){
                cnt++;
            }else{
                cnt--;
            }
            return cnt == 0;
        }
        if(dp[i][j][cnt] != -1 ) return dp[i][j][cnt];

        bool up = false;
        bool left = false;

        if(grid[i][j] == '('){
            up = solve(grid,i-1,j,cnt-1,dp);
            left = solve(grid,i,j-1,cnt-1,dp);
        }else{
            up = solve(grid,i-1,j,cnt+1,dp);
            left = solve(grid,i,j-1,cnt+1,dp);
        }
        return dp[i][j][cnt] =  (up || left);
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>((m+n),-1)));

        if(grid[0][0] == ')' || grid[n-1][m-1] == '(')
            return false;

        if((n + m - 1) % 2 != 0)
            return false;
        int cnt =0;
        bool ans = solve(grid,n-1,m-1,cnt,dp);
        return ans ;
        
    }
};