# Sum of Distances in Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

There is an undirected connected tree with `n` nodes labeled from `0` to `n - 1` and `n - 1` edges.

You are given the integer `n` and the array `edges` where `edges[i] = [ai, bi]` indicates that there is an edge between nodes `ai` and `bi` in the tree.

Return an array `answer` of length `n` where `answer[i]` is the sum of the distances between the `ith` node in the tree and all other nodes.

 

 **Example 1:** 

```
Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
Output: [8,12,6,10,10,10]
Explanation: The tree is shown above.
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.
Hence, answer[0] = 8, and so on.

```

 **Example 2:** 

```
Input: n = 1, edges = []
Output: [0]

```

 **Example 3:** 

```
Input: n = 2, edges = [[1,0]]
Output: [1,1]

```

 

 **Constraints:** 

- 1 <= n <= 3 * 104
- edges.length == n - 1
- edges[i].length == 2
- 0 <= ai, bi < n
- ai != bi
- The given input represents a valid tree.

## Solution

**Language:** C++  
**Runtime:** 87 ms (beats 57.51%)  
**Memory:** 97.6 MB (beats 68.67%)  
**Submitted:** 2026-11-02T05:15:55.414Z  

```cpp
class Solution {
    vector<int> node;
    int totalSum;
    vector<int> ans ;
    int N ;
private:
    int baseRoot(vector<vector<int>> & graph , int child , int parent , int currDepth){
        int totalNode = 1 ;
        totalSum += currDepth;
        for(int it : graph[child]){
            if(it != parent){
                totalNode += baseRoot(graph,it,child,currDepth+1);
            }
        }
        node[child] = totalNode;
        return totalNode;
    }
    void dfs(vector<vector<int>> & graph , int child ,int parent){

        for(auto it : graph[child]){
            if(it != parent){
                ans[it] = ans[child] - node[it] + (N - node[it]);
                dfs(graph,it,child);
            }
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
          vector<vector<int>> graph(n);

          for(auto & it : edges){
             graph[it[0]].push_back(it[1]);
             graph[it[1]].push_back(it[0]);
          }
          N = n;
          node.assign(n,0);
          totalSum =0;
          ans.assign(n,0);
          baseRoot(graph,0,-1,0);

          ans[0] = totalSum;
          dfs(graph,0,-1);

          return ans ;

    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/sum-of-distances-in-tree/)