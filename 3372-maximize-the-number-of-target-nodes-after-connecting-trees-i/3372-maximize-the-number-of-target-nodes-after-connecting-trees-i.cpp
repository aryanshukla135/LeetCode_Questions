class Solution {
private:
    int nodeKdis(vector<vector<int>> & graph ,int k ,int src  ){
        int n = graph.size();

        queue<pair<int,int>> q ;
        q.push({0,src});
    
        int cnt = 0 ;
        vector<int> vis(n);
        vis[src] = 1 ;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first ;
            int node = it.second ;
             
            if(dis <= k){
                ++cnt;
            }

            for(auto i : graph[node]){
                if(!vis[i]){
                    vis[i] = 1;
                    q.push({dis + 1 , i});
                }
            } 
        }

        return cnt ;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size();
        int m = edges2.size();

          
        vector<vector<int>> graph1(n+1);
        vector<vector<int>> graph2(m+1);

        for(auto it : edges1){
            int u = it[0];
            int v = it[1];

            graph1[u].push_back(v);
            graph1[v].push_back(u);
        }
        for(auto it : edges2){
            int u = it[0];
            int v = it[1];
            graph2[u].push_back(v);
            graph2[v].push_back(u);
        }
        int maxi = -1 ;
        vector<int> ans;
        for(int i = 0 ; i<=m ; i++){
            int temp = nodeKdis(graph2,k-1,i);
            maxi = max(maxi,temp);
        }
        for(int i = 0 ; i<=n ; i++){
            int temp = nodeKdis(graph1,k,i);
            int val = temp + maxi ;
            ans.push_back(val);
        }
        return ans ;
    }
};