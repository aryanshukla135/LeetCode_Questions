class Solution {
private:
    bool dfs(vector<vector<int>> & graph , vector<int> & color , int node ){
         for(auto it : graph[node]){
            if(color[it] == -1){
                color[it] = !color[node];
                if(dfs(graph,color,it) == false){
                    return false;
                };
            }else if(color[it] == color[node]){
                return false;
            }
         }
         return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1);
        for(auto it : dislikes){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<int> color(n+1,-1);
        // if(dfs(graph,color,1)){
        //     return true;
        // }else{
        //     return false;
        // }
        for(int i = 1 ; i<=n ; i++){
            if(dfs(graph,color,i) == false){
                return false;
            }
        }
        return true;
    }
};