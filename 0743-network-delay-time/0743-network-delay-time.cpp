class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto it : times){
            graph[it[0]].push_back({it[1],it[2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq ;
        vector<int> dist(n+1 , INT_MAX);

        pq.push({0,k});
        dist[k] = 0 ;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int distance = it.first ;
            int node = it.second ;

            for(auto i: graph[node]){
                int adjnode = i.first ;
                int edgedist = i.second ;

                if(edgedist + distance < dist[adjnode]){
                    dist[adjnode] = edgedist + distance;
                    pq.push({dist[adjnode] , adjnode});
                }
            }
        }
        dist[0] = 0;
        int maxi = *max_element(dist.begin() , dist.end());
        if(maxi == INT_MAX){
            return -1;
        }
        return maxi;
    }
};