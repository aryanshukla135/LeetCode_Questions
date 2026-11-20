
class Solution {
private:
    typedef pair<int,int> P;

    int dist(vector<vector<P>>& graph, int n) {
        priority_queue<P, vector<P>, greater<P>> pq;

        vector<int> dis(n, INT_MAX);

        pq.push({0, 0});
        dis[0] = 0;

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int node = it.second;
            int wt = it.first;

            if(wt > dis[node]) continue;

            for(auto i : graph[node]) {
                int adjnode = i.first;
                int adjwt = i.second;

                int newWt = max(wt, adjwt);

                if(newWt < dis[adjnode]) {
                    dis[adjnode] = newWt;
                    pq.push({newWt, adjnode});
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(dis[i] == INT_MAX) return -1;
            ans = max(ans, dis[i]);
        }

        return ans;
    }

public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<P>> graph(n);

        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            graph[v].push_back({u, wt});
        }

        return dist(graph, n);
    }
};
