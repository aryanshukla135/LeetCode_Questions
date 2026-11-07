class Solution {
private:
    bool dfs(vector<vector<int>> &graph, vector<int> &vis, int node) {

        if(vis[node]) {
            return false;
        }

        vis[node] = 1;

        for(auto it : graph[node]) {
            if(!dfs(graph, vis, it)) {
                return false;
            }
        }

        return true;
    }

public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild,vector<int>& rightChild) {

        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        for(int i = 0; i < n; i++) {

            if(leftChild[i] != -1) {
                graph[i].push_back(leftChild[i]);
                indegree[leftChild[i]]++;
            }

            if(rightChild[i] != -1) {
                graph[i].push_back(rightChild[i]);
                indegree[rightChild[i]]++;
            }
        }

        int root = -1;

        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {

                if(root != -1) {
                    return false;
                }

                root = i;
            }
        }

        if(root == -1) {
            return false;
        }

        vector<int> vis(n, 0);

        if(!dfs(graph, vis, root)) {
            return false;
        }

        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                return false;
            }
        }

        return true;
    }
};