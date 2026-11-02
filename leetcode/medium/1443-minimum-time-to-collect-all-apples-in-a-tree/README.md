# Minimum Time to Collect All Apples in a Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an undirected tree consisting of `n` vertices numbered from `0` to `n-1`, which has some apples in their vertices. You spend 1 second to walk over one edge of the tree.  *Return the minimum time in seconds you have to spend to collect all apples in the tree, starting at  **vertex 0**  and coming back to this vertex.* 

The edges of the undirected tree are given in the array `edges`, where `edges[i] = [ai, bi]` means that exists an edge connecting the vertices `ai` and `bi`. Additionally, there is a boolean array `hasApple`, where `hasApple[i] = true` means that vertex `i` has an apple; otherwise, it does not have any apple.

 

 **Example 1:** 

```
Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
Output: 8 
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  

```

 **Example 2:** 

```
Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
Output: 6
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  

```

 **Example 3:** 

```
Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
Output: 0

```

 

 **Constraints:** 

- 1 <= n <= 105
- edges.length == n - 1
- edges[i].length == 2
- 0 <= ai < bi <= n - 1
- hasApple.length == n

## Solution

**Language:** C++  
**Runtime:** 70 ms (beats 27.96%)  
**Memory:** 69.8 MB (beats 41.81%)  
**Submitted:** 2026-11-02T06:08:33.159Z  

```cpp
class Solution {
private:
    bool totalTime(vector<vector<int>> & graph ,int child , int parent,vector<bool> & hasApple ,int & ans ){
        bool found = hasApple[child];
        for(auto it : graph[child]){
            if(it != parent){
               bool res = totalTime(graph,it,child,hasApple,ans);

               if(res){
                ans += 2 ;
                found = true ;
               }
            }
        }
        return found ;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int ans = 0 ;
        vector<vector<int>> graph(n);
        for(auto it : edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        totalTime(graph,0,-1,hasApple,ans);
        return ans ;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/)