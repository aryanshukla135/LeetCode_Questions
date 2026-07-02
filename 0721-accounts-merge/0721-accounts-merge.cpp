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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
       int n = accounts.size();
        Disjointset ds(n);
       
        unordered_map<string,int> mapmailnode ;

        for(int i =0 ; i<n ; i++){
            for(int j =1 ; j<accounts[i].size() ; j++){
                 string mail = accounts[i][j] ;
                 if(mapmailnode.find(mail) == mapmailnode.end()){
                       mapmailnode[mail] = i;
                 }
                 else{
                       ds.unionbyrank(i,mapmailnode[mail]);
                 }
            }
        }
        vector<string> mergedmail[n];

        for(auto it :mapmailnode){
            string mail = it.first ;
            int node = ds.findUpar(it.second) ;

            mergedmail[node].push_back(mail);

        }

        vector<vector<string>> ans ;
        for(int i =0 ; i< n ; i++){
            if(mergedmail[i].size() ==0) continue ;
            sort(mergedmail[i].begin() , mergedmail[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergedmail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans ;
    }
};