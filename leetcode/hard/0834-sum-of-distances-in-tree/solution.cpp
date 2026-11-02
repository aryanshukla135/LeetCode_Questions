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
