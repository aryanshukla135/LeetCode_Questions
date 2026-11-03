class Solution {
private:
    void dfs(vector<vector<pair<int,int>>> &graph,
             int node, vector<int> &vis, int &cnt) {

        vis[node] = 1;

        for(auto it : graph[node]) {

            int adjNode = it.first;
            int direction = it.second;

            if(!vis[adjNode]) {

                if(direction == 1) {
                    cnt++;
                }

                dfs(graph, adjNode, vis, cnt);
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {

        vector<vector<pair<int,int>>> graph(n);

        for(auto it : connections) {

            graph[it[0]].push_back({it[1], 1});
            graph[it[1]].push_back({it[0], 0});
        }

        int cnt = 0;

        vector<int> vis(n, 0);

        dfs(graph, 0, vis, cnt);

        return cnt;
    }
};