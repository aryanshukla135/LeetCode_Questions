class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            graph[u].push_back({v,wt});
            graph[v].push_back({u,wt});
        }
        int ans =INT_MAX;
        vector<int> vis(n+1,0);
        queue<int> q;
        q.push(1);
        vis[1]=1;

        while(!q.empty()){
            int it = q.front();
            q.pop();

            for(auto i : graph[it]){
                int adjnode = i.first;
                int adjwt = i.second ;
                ans = min(ans,adjwt);

                if(!vis[adjnode]){
                    vis[adjnode] =1 ;
                    q.push(adjnode);
                }
            }

        }
        return ans;
    }
};