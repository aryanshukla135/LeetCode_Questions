class Solution {
private :
    bool dfs(vector<vector<int>>& graph , vector<int>& vis , int strt , int end ){
        vis[strt] = 1 ;

        if(strt == end){
            return true ;
        }
        for(auto it : graph[strt]){
            if(!vis[it]){
                if(dfs(graph,vis,it,end) == true){
                    return true ;
                }
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for(auto it: edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<int> vis(n);
        if(dfs(graph,vis,source,destination)){
            return true ;
        }
        return false ;

    }
};