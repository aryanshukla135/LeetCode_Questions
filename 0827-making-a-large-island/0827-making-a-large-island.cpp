class Solution {
private:
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
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        Disjointset ds(n*n);

        for(int i =0 ; i< n ; i++){
            for(int j =0; j< n ; j++){
                 if(grid[i][j] == 0) continue ;

                 int delrow[] = {-1,0,+1,0};
                 int delcol[] = {0,+1,0,-1};

                 for(int k =0 ; k<4 ; k++){
                    int nrow = i + delrow[k];
                    int ncol = j + delcol[k];

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol] ==1){
                        int adjcellno = nrow*n + ncol ;
                        int cellno = i*n + j;

                        ds.unionbysize(cellno,adjcellno);
                    }
                 }
            }
        }
        int maxsize =0;

        for(int i =0 ; i< n ; i++){
            for(int j =0 ; j< n ; j++){
                 if(grid[i][j] == 1) continue ;

                 int delrow[] = {-1,0,+1,0};
                 int delcol[] = {0,+1,0,-1};
                set<int> st ;
                 for(int k =0 ; k<4 ; k++){
                    int nrow = i + delrow[k];
                    int ncol = j + delcol[k];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                          st.insert(ds.findUpar(nrow*n + ncol));
                    }
                 }
                 int ssize =1;
                for(auto it : st){
                    ssize += ds.size[it];
                }
                maxsize = max(maxsize,ssize);
            }
            
        }
        for(int i =0 ; i<n*n ; i++){
            maxsize = max(maxsize , ds.size[ds.findUpar(i)]);
        }
        return maxsize;
    }
};