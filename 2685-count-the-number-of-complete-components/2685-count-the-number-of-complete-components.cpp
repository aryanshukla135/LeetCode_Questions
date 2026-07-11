class Solution {
private:
   void solve(vector<vector<int>>& graph, int node ,vector<int> & vis , int &vert ,int &edge){
        vis[node] = 1 ;
        vert++;
        edge += graph[node].size();

        for(auto it : graph[node]){
            
            if(!vis[it]){            
                solve(graph,it,vis,vert,edge);
            }
        }
   }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> vis(n,0);
        int cnt =0;
        for(int i = 0 ;i<n ; i++){
           int vert =0 ; 
           int edge =0 ;
            if(!vis[i]){
              solve(graph ,i,vis,vert,edge);
              edge = edge/2 ;
              if(edge == vert *(vert -1)/2){
                cnt++;
               }
            }
            
        }
        return cnt ;
    }
};