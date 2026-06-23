class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxcnt =INT_MIN;
        for(auto &row : matrix){
            vector<int> invert(m);

            for(int i =0 ; i<m ; i++){
                invert[i] = !row[i];
            }
             int cnt=0;
            for(auto &i : matrix){
                if(i == row || i == invert){
                    cnt++;
                }
            }
            maxcnt = max(maxcnt,cnt);
        }
        return maxcnt ;
    }
};
