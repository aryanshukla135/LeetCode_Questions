class Solution {
private:
    class Disjointset
{
public:
    vector<int> parent, rank;

    Disjointset(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            rank[i] = 0;
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

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjointset ds(n);
        int extraedge =0;

        for(auto it : connections){
            int u = it[0];
            int v= it[1];

            if(ds.findUpar(u) == ds.findUpar(v)){
                extraedge++;
            }else{
                ds.unionbyrank(u,v);
            }
        }
        int ccomponent =0;
        for(int i =0 ; i<n ; i++){
            if(ds.parent[i]==i){
                 ccomponent++;
            }
        }
        int ans = ccomponent -1 ;
        if(extraedge >= ans){
            return ans ;
        }
        return -1;
    }
};