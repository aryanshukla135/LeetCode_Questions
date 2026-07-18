class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>,int> mp;

        for(int i =0 ; i<n ; i++){
            mp[grid[i]]++;
        }
        
        vector<vector<int>> mat(n,vector<int>(n,0)) ;

        for(int i = 0 ; i<n ; i++){
            for(int j = 0; j<n ; j++){
                mat[i][j] = grid[j][i];
            }
        }
        int count =0 ;
        for(int i =0 ; i<n ; i++){
            if(mp.count(mat[i])){
                count += mp[mat[i]];
            }
        }

    return count ;
    }
};

