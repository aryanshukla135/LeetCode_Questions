class Solution {
private:
    void dfs(vector<vector<int>> & graph , vector<bool> & vis , int i , int &cnt){
        vis[i] = 1 ;
        cnt++;

        for(auto it : graph[i]){
            if(!vis[it]){
                dfs(graph,vis,it,cnt);
            }
        }
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);

        for(int i =0 ; i<n ; i++){
            int x1 = bombs[i][0];
            int y1 = bombs[i][1];
            int r = bombs[i][2];

            for(int j = 0 ; j<n ; j++){
                if(j != i){
                    int x2 = bombs[j][0];        
                    int y2 = bombs[j][1];
                    
                    int x = (x1 - x2 );
                    int y = (y1 - y2 );
                   
                    long long dis = (1LL * x * x) + (1LL * y * y);
                    if(dis <= (1LL * r * r)){
                        graph[i].push_back(j);
                    }
                }
            }
        }
        int maxCnt = 0 ;
        for(int i = 0  ; i<n ; i++){
            vector<bool> vis(n,0);
            int cnt =0 ;
            dfs(graph,vis,i,cnt);
            maxCnt = max(maxCnt,cnt);
        }
        return maxCnt;
    }
};