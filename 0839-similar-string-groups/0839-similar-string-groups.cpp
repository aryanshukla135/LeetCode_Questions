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

    void unionbysize(int u, int v)
    {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        Disjointset ds(n);

        for(int i =1 ; i<n ; i++){
            string s1 = strs[i];
            int j = i-1;
            while(j>=0){
                string s2 = strs[j];
                int swap =0 ;
                int a= 0;
                int b =0 ;
                while(a < s1.size()){
                    if(s1[a] != s2[b]){
                        swap++;
                    }
                    a++;
                    b++;
                }
                if(swap == 0 || swap == 2){
                    ds.unionbyrank(j,i);
                }
                j--;
            }
        }
        int cnt =0 ;
        for(int i = 0 ; i<n ; i++){
           if(ds.parent[i] == i ){
            cnt++;
        }
       }
       return cnt ;
    }
};