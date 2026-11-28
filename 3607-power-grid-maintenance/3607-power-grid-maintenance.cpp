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
};
class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
         Disjointset ds(c+1);

         for(auto & it : connections){
            int u = it[0];
            int v = it[1];

            ds.unionbyrank(u,v);
         }   

         vector<int> id(c+1);
         unordered_map<int,set<int>> mp ;

         for(int i = 1 ; i<=c ; i++){
            id[i] = ds.findUpar(i);
         }

         for(int i = 1 ; i<=c ;i++){
            mp[id[i]].insert(i);
         }

         vector<int> ans ;

         for(auto & it : queries){
            int val = it[0];
            int node = it[1];

            int i = id[node];

            if(val == 1){
                if(mp[i].count(node)){
                   ans.push_back(node);
                }
                else if(!mp[i].empty()){
                    ans.push_back( *mp[i].begin());
                }else{
                    ans.push_back(-1);
                }
            }else{
                mp[i].erase(node);
            }
         }
         return ans ;
    }
};