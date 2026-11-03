# Reorder Routes to Make All Paths Lead to the City Zero

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

There are `n` cities numbered from `0` to `n - 1` and `n - 1` roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by `connections` where `connections[i] = [ai, bi]` represents a road from city `ai` to city `bi`.

This year, there will be a big event in the capital (city `0`), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city `0`. Return the  **minimum**  number of edges changed.

It's  **guaranteed**  that each city can reach city `0` after reorder.

 

 **Example 1:** 

```
Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

```

 **Example 2:** 

```
Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

```

 **Example 3:** 

```
Input: n = 3, connections = [[1,0],[2,0]]
Output: 0

```

 

 **Constraints:** 

- 2 <= n <= 5 * 104
- connections.length == n - 1
- connections[i].length == 2
- 0 <= ai, bi <= n - 1
- ai != bi

## Solution

**Language:** C++  
**Runtime:** 169 ms (beats 22.61%)  
**Memory:** 117.4 MB (beats 32.03%)  
**Submitted:** 2026-11-03T20:17:52.260Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/)