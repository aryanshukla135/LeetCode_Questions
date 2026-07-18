class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int> elementtoidx_i;
        unordered_map<int,int> elementtoidx_j;
        unordered_map<int,int> icount;
        unordered_map<int,int> jcount;
        int n = mat.size();
        int m = mat[0].size();

        for(int i =0 ; i< n ; i++){
            for(int j =0 ; j< m ; j++){
                elementtoidx_i[mat[i][j]] = i ;
                elementtoidx_j[mat[i][j]] = j ;

            }
        }

        for(int i =0 ; i< n ; i++){
            icount[i] = m ;
        }
        for(int i =0 ; i< m ; i++){
            jcount[i] = n ;
        }

        for(int i =0 ; i<arr.size() ; i++){
            int idxi = elementtoidx_i[arr[i]];
            int idxj = elementtoidx_j[arr[i]];

            if(icount[idxi] > 0){
                icount[idxi]--;
                if(icount[idxi] == 0){
                    return i ;
                }
            }
            if(jcount[idxj] > 0){
                jcount[idxj] -- ;
                if(jcount[idxj] == 0){
                    return i ;
                }
            }
        }

        return 0 ;
    }
};