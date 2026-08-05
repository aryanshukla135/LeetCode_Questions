class Solution {
private: 
    void dfs( vector<vector<int>>& graph,vector<int>& vis,int i){
        vis[i]=1;
        for(auto it : graph[i]){
            if(!vis[it]){
                dfs(graph,vis,it);
            }
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        
        for(auto it :invocations ){
            int u = it[0];
            int v = it[1];
            
            graph[u].push_back(v);
        }
        vector<int> vis(n,0);
        
        dfs(graph,vis,k);
         for (auto &it : invocations) {
            int u = it[0];
            int v = it[1];

            if (!vis[u] && vis[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Otherwise return all non-suspicious methods.
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
        
    }
};