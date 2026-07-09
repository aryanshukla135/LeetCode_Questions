class Disjointset
{
public:
    vector<int> parent, rank,size;

    Disjointset(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1);
        size.resize(n+1);

        for (int i = 0; i < n; i++)
        {
            rank[i] = 0;
            parent[i] = i;
            size[i] = 1 ;
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
    void unionbysize(int u ,int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if (ulp_u == ulp_v)
            return;

        if(size[ulp_u]< size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] +=size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] +=size[ulp_v];
        }

    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
          Disjointset ds(n);
          for(int i =0 ;i<n-1 ;i++){
             int val1 = nums[i];
             int val2 = nums[i+1];
             int diff = abs(val1 - val2);

             if(diff <= maxDiff){
                ds.unionbyrank(i,i+1);
             }
          }

          //cout<< ds.findUpar(3);

          vector<bool> result;
          for(int i = 0 ; i<queries.size() ; i++){
              int u = queries[i][0];
              int v = queries[i][1];

              if(ds.findUpar(u) == ds.findUpar(v)){
                  result.push_back(true);
              }else{
                 result.push_back(false);
              }
          }
          return result ;
    }
};