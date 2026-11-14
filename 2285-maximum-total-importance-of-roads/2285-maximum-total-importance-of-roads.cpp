class Solution {
public:
    typedef pair<int,int> P ;
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> indeg(n);
        vector<vector<int>> graph(n);
        
        for(auto & road : roads){
            int u = road[0];
            int v = road[1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        
            indeg[u]++;
            indeg[v]++;
        }

        vector<int> wt(n);
        priority_queue<P>pq;
        
        for(int i =0 ; i<n ; i++){
            pq.push({indeg[i],i});
        }
        int cnt = n ;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            wt[it.second] = cnt ;
            cnt--;
        }

        vector<int> vis(n);
        long long sum =0 ;
        
        for(int i =0 ; i<n; i++){
            for(auto & it : graph[i]){
                if(!vis[i] && !vis[it]){
                    sum += (wt[i] + wt[it]);
                }
            }
           vis[i] = 1 ;
        
        }

        return sum ;

    }
};