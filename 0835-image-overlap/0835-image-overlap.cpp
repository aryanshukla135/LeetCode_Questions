class Solution {
public:
    int solve(vector<vector<int>>& A, vector<vector<int>>& B,int & rowoff ,int & coloff ){
        int n = A.size();
        int count =0;
        for(int i = 0; i< n ; i++){
            for(int j = 0 ;j< n ; j++){
                int b_i = i+rowoff;
                int b_j = j+coloff ;
                if(b_i<0 || b_i>=n || b_j<0 || b_j>=n ){
                    continue ;
                }
                if(A[i][j]==1 && B[b_i][b_j]==1){
                    count++;
                }
            }
        }
        return count ;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
         int n = A.size();
         int maxcount =0 ;
         for(int rowoff = -n+1 ; rowoff<n ; rowoff++){
            for(int coloff = -n+1 ; coloff<n ; coloff++){
                
              int  count = solve(A,B,rowoff,coloff);
                maxcount = max(maxcount , count);
            }
         }
         return maxcount ;
    }
};