# Count Unreachable Pairs of Nodes in an Undirected Graph

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer `n`. There is an  **undirected**  graph with `n` nodes, numbered from `0` to `n - 1`. You are given a 2D integer array `edges` where `edges[i] = [ai, bi]` denotes that there exists an  **undirected**  edge connecting nodes `ai` and `bi`.

Return  *the  **number of pairs**  of different nodes that are  **unreachable**  from each other*.

 

 **Example 1:** 

```
Input: n = 3, edges = [[0,1],[0,2],[1,2]]
Output: 0
Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.

```

 **Example 2:** 

```
Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
Output: 14
Explanation: There are 14 pairs of nodes that are unreachable from each other:
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
Therefore, we return 14.

```

 

 **Constraints:** 

- 1 <= n <= 105
- 0 <= edges.length <= 2 * 105
- edges[i].length == 2
- 0 <= ai, bi < n
- ai != bi
- There are no repeated edges.

## Solution

**Language:** C++  
**Runtime:** 15 ms (beats 93.94%)  
**Memory:** 142.2 MB (beats 93.54%)  
**Submitted:** 2026-11-04T05:09:22.625Z  

```cpp
class Disjointset
{
public:
    vector<int> parent, rank, size;

    Disjointset(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i < n; i++)
        {
            rank[i] = 0;
            size[i] = 1;
            parent[i] = i;
        }
    }

    int findUpar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = findUpar(parent[node]);
    }

    void unionbyrank(int u, int v)
    {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_u] = ulp_v;
            rank[ulp_u]++;
        }
    }

    void unionbysize(int u, int v)
    {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        Disjointset ds(n);

        for(auto & it : edges){
           int u = it[0];
           int v = it[1];

           ds.unionbysize(u,v);
        }
        long long prev =0 ;
        long long ans= 0 ;
        for(int i =0 ; i<n; i++){
            if(ds.parent[i] == i ){
                ans += (prev * ds.size[i]);
                prev += (ds.size[i]);
            }
        } 
        return ans ;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/)