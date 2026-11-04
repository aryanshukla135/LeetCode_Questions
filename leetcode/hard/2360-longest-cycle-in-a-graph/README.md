# Longest Cycle in a Graph

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a  **directed**  graph of `n` nodes numbered from `0` to `n - 1`, where each node has  **at most one**  outgoing edge.

The graph is represented with a given  **0-indexed**  array `edges` of size `n`, indicating that there is a directed edge from node `i` to node `edges[i]`. If there is no outgoing edge from node `i`, then `edges[i] == -1`.

Return  *the length of the  **longest**  cycle in the graph*. If no cycle exists, return `-1`.

A cycle is a path that starts and ends at the  **same**  node.

 

 **Example 1:** 

```
Input: edges = [3,3,4,2,3]
Output: 3
Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
The length of this cycle is 3, so 3 is returned.

```

 **Example 2:** 

```
Input: edges = [2,-1,3,1]
Output: -1
Explanation: There are no cycles in this graph.

```

 

 **Constraints:** 

- n == edges.length
- 2 <= n <= 105
- -1 <= edges[i] < n
- edges[i] != i

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.5 MB  
**Submitted:** 2026-11-04T12:29:40.396Z  

```cpp
class Solution {
private:
    int result = -1;
    void dfs(vector<vector<int>> & graph , vector<bool> & pathvis,vector<bool> & vis,vector<int> & count , int node)
    {
        pathvis[node] = 1 ;
        vis[node] = 1 ;
        for(auto it : graph[node]){
            if(!vis[it]){
                count[it] = count[node] + 1 ;
                dfs(graph,pathvis,vis,count,it);
            }else if(pathvis[it]){
                result = max(result,count[node] - count[it] +1);
            }
        }
        pathvis[node] = 0;
       // count[node] = 1 ;
    }
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n);

        for(int i =0; i<n ; i++){
            if(edges[i] != -1){
                graph[i].push_back(edges[i]);
            }
        }

        vector<bool> pathvis(n,0);
        vector<bool> vis(n,0);
        vector<int> count(n,0);

        for(int i= 0 ; i<n ;i++){
            if(vis[i] != 1){
               dfs(graph,pathvis,vis,count,i);
            }
        }
        
        return result;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-cycle-in-a-graph/)