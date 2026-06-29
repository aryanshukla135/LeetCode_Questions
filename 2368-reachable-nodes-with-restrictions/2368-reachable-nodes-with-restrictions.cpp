class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> graph(n);

        for(auto it : edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        unordered_set<int> st ;
        for(int it : restricted){
            st.insert(it);
        }
        queue<int> q ;
        q.push(0);
        int cnt =0;
        st.insert(0);
        int maxi=0;

        while(!q.empty()){
            int it = q.front();
            q.pop();
   
            cnt++;
          
            for(auto i : graph[it]){
                int adjnode = i;
                if(!st.count(adjnode)){
                    st.insert(adjnode);
                    q.push(adjnode);
                }
            }
        }
        return cnt ;
    }
};