class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int minelement = INT_MAX;
        long long totalsum =0 ;
        long long negative_cnt =0;

        for(int i=0 ; i< n ; i++){
            for(int j =0 ; j< n ;j++){
                totalsum+=abs(matrix[i][j]);

                if(matrix[i][j]<0){
                    negative_cnt++;
                }
                minelement = min(minelement,abs(matrix[i][j]));
            }
        }

        long long ans =0;

        if(negative_cnt %2 ==0){
            ans = totalsum;
        }else{
            ans= totalsum-2*minelement;
        }

        return ans;
    }
};

