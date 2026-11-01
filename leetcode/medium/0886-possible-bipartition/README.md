# Possible Bipartition

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

We want to split a group of `n` people (labeled from `1` to `n`) into two groups of  **any size**. Each person may dislike some other people, and they should not go into the same group.

Given the integer `n` and the array `dislikes` where `dislikes[i] = [ai, bi]` indicates that the person labeled `ai` does not like the person labeled `bi`, return `true`  *if it is possible to split everyone into two groups in this way*.

 

 **Example 1:** 

```
Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: The first group has [1,4], and the second group has [2,3].

```

 **Example 2:** 

```
Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Explanation: We need at least 3 groups to divide them. We cannot put them in two groups.

```

 

 **Constraints:** 

- 1 <= n <= 2000
- 0 <= dislikes.length <= 104
- dislikes[i].length == 2
- 1 <= ai < bi <= n
- All the pairs of dislikes are unique.

## Solution

**Language:** C++  
**Runtime:** 69 ms (beats 12.97%)  
**Memory:** 76.1 MB (beats 32.62%)  
**Submitted:** 2026-11-01T21:11:06.534Z  

```cpp
class Solution {
private:
    bool dfs(vector<vector<int>> & graph , vector<int> & color , int node ){
         for(auto it : graph[node]){
            if(color[it] == -1){
                color[it] = !color[node];
                if(dfs(graph,color,it) == false){
                    return false;
                };
            }else if(color[it] == color[node]){
                return false;
            }
         }
         return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1);
        for(auto it : dislikes){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<int> color(n+1,-1);
        // if(dfs(graph,color,1)){
        //     return true;
        // }else{
        //     return false;
        // }
        for(int i = 1 ; i<=n ; i++){
            if(dfs(graph,color,i) == false){
                return false;
            }
        }
        return true;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/possible-bipartition/)