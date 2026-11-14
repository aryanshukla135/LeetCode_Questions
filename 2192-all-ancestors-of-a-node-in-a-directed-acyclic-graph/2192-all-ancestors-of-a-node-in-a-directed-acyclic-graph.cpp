class Solution {
private:
    vector<int> topo(vector<vector<int>> & graph,vector<int> & indeg){
        queue<int> q;
        vector<int> top;
       
       for(int i =0 ; i<graph.size() ; i++){
           if(indeg[i] == 0){
             q.push(i);
           }
       }

       while(!q.empty()){
          int elem = q.front();
          q.pop();
          top.push_back(elem);
          for(auto & it : graph[elem]){
             indeg[it]--;
             if(indeg[it] == 0){
                q.push(it);
             }
          }
       }
        return top;
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> indeg(n);
        vector<vector<int>> parent(n);
        for(auto & edge : edges){
            int u = edge[0];
            int v = edge[1];

            indeg[v]++;
            graph[u].push_back(v);
            parent[v].push_back(u);
        }

        vector<int> top = topo(graph,indeg);
        vector<vector<int>> ans(n);
        for(int i : top) cout<<i<<" ";


        for(int i =0 ; i<n ; i++){
          int node = top[i];
          unordered_set<int> st ;
          if(parent[node].size() > 0){
            vector<int> temp = parent[node];
            for(int i =0 ; i < temp.size();i++){
                st.insert(temp[i]);
                int m = ans[temp[i]].size();
                for(int j = 0 ; j<m ; j++){
                    st.insert(ans[temp[i]][j]);
                }
            }
          }
          vector<int> topush;
          if(!st.empty()){
             for(auto & it : st){
                topush.push_back(it);
             }
             sort(topush.begin(),topush.end());
          }
          ans[node] = topush;
        }

        return ans ; 
    }
};