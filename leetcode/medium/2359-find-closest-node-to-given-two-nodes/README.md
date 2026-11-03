# Find Closest Node to Given Two Nodes

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a  **directed**  graph of `n` nodes numbered from `0` to `n - 1`, where each node has  **at most one**  outgoing edge.

The graph is represented with a given  **0-indexed**  array `edges` of size `n`, indicating that there is a directed edge from node `i` to node `edges[i]`. If there is no outgoing edge from `i`, then `edges[i] == -1`.

You are also given two integers `node1` and `node2`.

Return  *the  **index**  of the node that can be reached from both* `node1` *and* `node2` *, such that the  **maximum**  between the distance from* `node1` *to that node, and from* `node2` *to that node is  **minimized***. If there are multiple answers, return the node with the  **smallest**  index, and if no possible answer exists, return `-1`.

Note that `edges` may contain cycles.

 

 **Example 1:** 

```
Input: edges = [2,2,3,-1], node1 = 0, node2 = 1
Output: 2
Explanation: The distance from node 0 to node 2 is 1, and the distance from node 1 to node 2 is 1.
The maximum of those two distances is 1. It can be proven that we cannot get a node with a smaller maximum distance than 1, so we return node 2.

```

 **Example 2:** 

```
Input: edges = [1,2,-1], node1 = 0, node2 = 2
Output: 2
Explanation: The distance from node 0 to node 2 is 2, and the distance from node 2 to itself is 0.
The maximum of those two distances is 2. It can be proven that we cannot get a node with a smaller maximum distance than 2, so we return node 2.

```

 

 **Constraints:** 

- n == edges.length
- 2 <= n <= 105
- -1 <= edges[i] < n
- edges[i] != i
- 0 <= node1, node2 < n

## Solution

**Language:** C++  
**Runtime:** 171 ms (beats 12.68%)  
**Memory:** 165.9 MB (beats 6.79%)  
**Submitted:** 2026-11-03T18:21:31.569Z  

```cpp
class Solution {
void bfs(vector<vector<int>> & graph , int node , vector<int> & nums){
    int n = nums.size();
    vector<int> vis(n);
    queue<pair<int,int>> q ;
    q.push({0,node});
    nums[node] = 0 ;
    vis[node] = 1 ;

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int step = it.first ;
        int no = it.second ;
        nums[no] = step ;

        for(auto it : graph[no]){
            if(!vis[it]){
                vis[it] = 1 ;
                q.push({step + 1 , it});
            }
        }
    }
}
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> graph(n);

        for(int i =0 ; i<n ; i++){
           if(edges[i] != -1){
              graph[i].push_back(edges[i]);
           }
        }

        vector<int> nums1(n,INT_MAX);
        vector<int> nums2(n,INT_MAX);

        bfs(graph,node1,nums1);
        bfs(graph,node2,nums2);

        int ind = -1 ;
        int mini = INT_MAX;

        for(int i =0 ; i <n ; i++){
            if(nums1[i] != INT_MAX  && nums2[i] != INT_MAX){
                int val = max(nums1[i],nums2[i]);
                if(val < mini){
                    mini = val ;
                    ind = i ;
                }
            }
        }
        return ind ;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/find-closest-node-to-given-two-nodes/)