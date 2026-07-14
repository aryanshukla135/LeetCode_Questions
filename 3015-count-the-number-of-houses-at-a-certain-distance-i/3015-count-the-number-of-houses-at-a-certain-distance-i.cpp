class Solution {
private:
    void bfs(vector<vector<int>> &graph, int src, vector<int> &result) {

        int n = graph.size() - 1;
        vector<int> vis(n + 1, 0);

        queue<pair<int,int>> q;
        q.push({src, 0});
        vis[src] = 1;

        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();

            if (dist > 0)
                result[dist - 1]++;

            for (auto adj : graph[node]) {
                if (!vis[adj]) {
                    vis[adj] = 1;
                    q.push({adj, dist + 1});
                }
            }
        }
    }

public:
    vector<int> countOfPairs(int n, int x, int y) {

        vector<vector<int>> graph(n + 1);

        for (int i = 1; i < n; i++) {
            graph[i].push_back(i + 1);
            graph[i + 1].push_back(i);
        }

        if (x != y) {
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        vector<int> result(n, 0);

        for (int i = 1; i <= n; i++) {
            bfs(graph, i, result);
        }

        return result;
    }
};