class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n);
         
        vector<long long> dist(n,LLONG_MAX) , ways(n,0);
        for(auto it : roads){
            graph[it[0]].push_back({it[1],it[2]});
            graph[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long ,int> , vector<pair<long long,int>> , greater<pair<long long ,int>>> pq ;
        pq.push({0,0});
        dist[0] = 0;
        ways[0] = 1;
        int mod = 1e9 + 7 ;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            long long  distance = it.first ;
            int node = it.second ;

            for(auto i : graph[node]){
                int adjnode = i.first ;
                long long ndist = i.second ;

                if(ndist + distance < dist[adjnode]){
                    dist[adjnode] = ndist + distance ;
                    pq.push({dist[adjnode] , adjnode});
                    ways[adjnode] = ways[node];
                }else if(ndist + distance == dist[adjnode]){
                    ways[adjnode] =  (ways[adjnode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};