class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> result ;
        bool flip = true ;
        bool temp = true ;
        for(int i =0 ; i< n ; i++){
            for(int j = 0; j< m ; j++){
                int idx = flip ? j : m-j-1; 
                if(temp){
                  result.push_back(grid[i][idx]);
                }
                temp = !temp ;
            }
            flip = !flip ;
        }
    return result ;
    }
};