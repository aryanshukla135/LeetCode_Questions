class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
       set<pair<int,int>> st ;
       vector<int> deg(n);
       for(auto it : roads){
           int u = it[0];
           int v = it[1];
           deg[u]++;
           deg[v]++;
           st.insert({u,v});
           st.insert({v,u});
       }

       int ans =0 ;
       for(int i =0 ; i<n ; i++){
          for(int j = i + 1 ; j<n ; j++){
             int cnt = deg[i] + deg[j];
             if(st.count({i,j}) || st.count({j,i})){
                cnt -= 1 ;
             }
             ans = max(cnt,ans);
          }
       }

    return ans ;
    }
};