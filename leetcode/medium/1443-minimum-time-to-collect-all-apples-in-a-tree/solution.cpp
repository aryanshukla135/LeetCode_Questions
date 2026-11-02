class Solution {
private:
    bool totalTime(vector<vector<int>> & graph ,int child , int parent,vector<bool> & hasApple ,int & ans ){
        bool found = hasApple[child];
        for(auto it : graph[child]){
            if(it != parent){
               bool res = totalTime(graph,it,child,hasApple,ans);

               if(res){
                ans += 2 ;
                found = true ;
               }
            }
        }
        return found ;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int ans = 0 ;
        vector<vector<int>> graph(n);
        for(auto it : edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        totalTime(graph,0,-1,hasApple,ans);
        return ans ;
    }
};