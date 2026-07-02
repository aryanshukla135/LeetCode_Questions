class Solution {
private:
    void solve(vector<vector<int>>& graph , vector<int> &temp , vector<vector<int>>& ans,int n ,vector<int> &vis,int start ){

        vis[start] =1 ;
        temp.push_back(start);
        if(start == n-1){
            ans.push_back(temp);
            vis[start] = 0;
            temp.pop_back();
            return;
        }
        for(auto it : graph[start]){
            if(!vis[it]){
                solve(graph,temp,ans,n,vis,it);
            }
        }
        vis[start] =0;
        temp.pop_back();

    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans ;
        vector<int> temp ;
        vector<int> vis(n,0);

        solve(graph,temp,ans,n,vis,0);

        return ans ;
    }
};