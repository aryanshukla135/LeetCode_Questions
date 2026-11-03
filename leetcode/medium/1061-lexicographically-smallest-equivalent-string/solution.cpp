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

        if (ulp_u < ulp_v)
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_u] = ulp_v;
        }
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
           int n = s1.size();
           Disjointset ds(26);
           for(int i =0 ; i<n ; i++){
               int u = s1[i] - 'a';
               int v = s2[i] - 'a';
              
               ds.unionbyrank(u,v);
              
           }
           string ans = "";

           for(int i = 0 ; i<baseStr.size();i++){
               int ind = baseStr[i]-'a';
               int val = ds.findUpar(ind);

               char ch = val + 'a';
               ans += ch; 
           }
           return ans ;
    }
};