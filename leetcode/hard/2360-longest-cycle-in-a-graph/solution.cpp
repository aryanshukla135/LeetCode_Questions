class Solution {
private:
    int result = -1;
    void dfs(vector<vector<int>> & graph , vector<bool> & pathvis,vector<bool> & vis,vector<int> & count , int node)
    {
        pathvis[node] = 1 ;
        vis[node] = 1 ;
        for(auto it : graph[node]){
            if(!vis[it]){
                count[it] = count[node] + 1 ;
                dfs(graph,pathvis,vis,count,it);
            }else if(pathvis[it]){
                result = max(result,count[node] - count[it] +1);
            }
        }
        pathvis[node] = 0;
       // count[node] = 1 ;
    }
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n);

        for(int i =0; i<n ; i++){
            if(edges[i] != -1){
                graph[i].push_back(edges[i]);
            }
        }

        vector<bool> pathvis(n,0);
        vector<bool> vis(n,0);
        vector<int> count(n,0);

        for(int i= 0 ; i<n ;i++){
            if(vis[i] != 1){
               dfs(graph,pathvis,vis,count,i);
            }
        }
        
        return result;
    }
};