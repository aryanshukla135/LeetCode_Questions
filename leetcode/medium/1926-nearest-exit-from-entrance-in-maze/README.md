# Nearest Exit from Entrance in Maze

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an `m x n` matrix `maze` (**0-indexed**) with empty cells (represented as `'.'`) and walls (represented as `'+'`). You are also given the `entrance` of the maze, where `entrance = [entrancerow, entrancecol]` denotes the row and column of the cell you are initially standing at.

In one step, you can move one cell  **up**,  **down**,  **left**, or  **right**. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the  **nearest exit**  from the `entrance`. An  **exit**  is defined as an  **empty cell**  that is at the  **border**  of the `maze`. The `entrance`  **does not count**  as an exit.

Return  *the  **number of steps**  in the shortest path from the* `entrance` *to the nearest exit, or* `-1` *if no such path exists*.

 

 **Example 1:** 

```
Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
Output: 1
Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3].
Initially, you are at the entrance cell [1,2].
- You can reach [1,0] by moving 2 steps left.
- You can reach [0,2] by moving 1 step up.
It is impossible to reach [2,3] from the entrance.
Thus, the nearest exit is [0,2], which is 1 step away.

```

 **Example 2:** 

```
Input: maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
Output: 2
Explanation: There is 1 exit in this maze at [1,2].
[1,0] does not count as an exit since it is the entrance cell.
Initially, you are at the entrance cell [1,0].
- You can reach [1,2] by moving 2 steps right.
Thus, the nearest exit is [1,2], which is 2 steps away.

```

 **Example 3:** 

```
Input: maze = [[".","+"]], entrance = [0,0]
Output: -1
Explanation: There are no exits in this maze.

```

 

 **Constraints:** 

- maze.length == m
- maze[i].length == n
- 1 <= m, n <= 100
- maze[i][j] is either '.' or '+'.
- entrance.length == 2
- 0 <= entrancerow < m
- 0 <= entrancecol < n
- entrance will always be an empty cell.

## Solution

**Language:** C++  
**Runtime:** 14 ms (beats 32.52%)  
**Memory:** 39.1 MB (beats 32.67%)  
**Submitted:** 2026-11-01T20:41:01.534Z  

```cpp
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        int r = entrance[0];
        int c = entrance[1];

        int dr[] = {-1,0,+1,0};
        int dc[] = {0,+1,0,-1};

        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>> q ;

        q.push({0,{r,c}});
        vis[r][c] = 1 ;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int step = it.first ;
            int row = it.second.first;
            int col = it.second.second;

            if ((row == 0 || row == n-1 || col == 0 || col == m-1) && !(row == r && col == c)) {
                 return step;
            }
            for(int i =0 ; i<4 ; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                if(nr >=0 && nr < n && nc >=0 && nc < m && vis[nr][nc] != 1 && maze[nr][nc] == '.'){
                    vis[nr][nc] = 1 ;
                    q.push({step + 1 ,{nr,nc}});
                }
            }

        }

    return -1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/)