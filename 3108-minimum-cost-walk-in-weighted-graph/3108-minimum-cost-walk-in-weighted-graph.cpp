class Disjointset
{
public:
    vector<int> parent, rank,size,andValue;

    Disjointset(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1);
        size.resize(n+1);
        andValue.resize(n+1,INT_MAX);

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

    void unionbyrank(int u, int v,int val)
    {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if (ulp_u == ulp_v){
           andValue[ulp_u] &= val ;
            return;
        }

        int newAnd = andValue[ulp_u] & andValue[ulp_v] & val;   

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            andValue[ulp_v] = newAnd ;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
            andValue[ulp_u] = newAnd ;
        }
        else
        {
            parent[ulp_u] = ulp_v;
            rank[ulp_u]++;
            andValue[ulp_v] = newAnd ;
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
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        Disjointset ds(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            ds.unionbyrank(u,v,wt); 

        }
        vector<int> ans;

        for(auto it : query) {
            int u = it[0];
            int v = it[1];

            if(ds.findUpar(u) != ds.findUpar(v)) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(ds.andValue[ds.findUpar(u)]);
            }
        }

        return ans;

       
    }
};



