class Disjointset
{
public:
    vector<int> parent, rank, size;
    int component ; 

    Disjointset(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1);
        size.resize(n + 1);
        component = n ; 

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
        component--;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        Disjointset alice(n);
        Disjointset bob(n);

        sort(edges.rbegin(),edges.rend());

        int edgecount =0 ;
        for(auto it : edges){
            int type = it[0];
            int u = it[1];
            int v = it[2];

            if(type == 3){
                bool temp = false;

                if(alice.findUpar(u) != alice.findUpar(v)){
                    alice.unionbyrank(u,v);
                    temp = true ;
                }

                if(bob.findUpar(u) != bob.findUpar(v)){
                    bob.unionbyrank(u,v);
                    temp = true ;
                }

                if(temp){
                    edgecount++;
                }
            }else if(type == 2){
                if(bob.findUpar(u) != bob.findUpar(v)){
                    bob.unionbyrank(u,v);
                    edgecount++;
                }
            }else{
                if(alice.findUpar(u) != alice.findUpar(v)){
                    alice.unionbyrank(u,v);
                    edgecount++;
                }
            }
        }

        if(alice.component == 1 && bob.component == 1){
            return edges.size() - edgecount;
        }
   
        return -1;

    }
};