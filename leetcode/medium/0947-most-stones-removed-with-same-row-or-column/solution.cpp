class Solution {
private:
    void dfs(vector<vector<int>>& stones,int ind , vector<int> & vis){
         vis[ind] = 1 ;
        for(int i =0 ; i<stones.size();i++){
            int nr = stones[i][0];
            int nc = stones[i][1];
            if((nr == stones[ind][0] || nc == stones[ind][1]) && vis[i] != 1){
                dfs(stones,i,vis);
            }    
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> vis(n);
       
        int cnt =0;
        for(int i =0 ; i<n ;i++){
    
           if(!vis[i]){
             cnt++;
             dfs(stones,i,vis);
           }
        }
        return n-cnt ;
    }
};