class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,list<pair<int,int>>> adj;
        for(int i = 0 ; i< times.size();i++){
            int u =times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            pair<int,int> p = make_pair(v,w);
            adj[u].push_back(p);
        }
        vector<int> dist(n+1,INT_MAX);
        set<pair<int,int>>st;
        dist[k]=0;
        st.insert({0,k});

        while(!st.empty()){
            auto top = *(st.begin());
            st.erase(st.begin());
            int node=top.second;
            int d = top.first ;

            for(auto i:adj[node]){
                int a = i.first;
                int b = i.second;

                if(d+b<dist[a]){
                     if(dist[a] !=INT_MAX){
                        st.erase({dist[a],a});
                     }
                     dist[a]=d+b;
                     st.insert({dist[a],a});
                }
            }
        }
        int ans =0;
        for(int i= 1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            ans=max(ans,dist[i]);
        }
     return ans ;
        
    }
};