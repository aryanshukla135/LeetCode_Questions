class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto it : flights){
            graph[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n,1e9);

        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        dist[src]= 0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int stop = it.first ;
            int node = it.second.first;
            int distance = it.second.second;

            if(stop>k){
                continue ;
            }

            for(auto i : graph[node]){
                int adjnode = i.first;
                int edgewt = i.second ;

                if(edgewt + distance < dist[adjnode] && stop<=k){
                    dist[adjnode] = edgewt + distance ;
                    q.push({stop +1 ,{adjnode,dist[adjnode]}});
                }
            }
        }
        if(dist[dst] == 1e9){
            return -1;
        }
        return dist[dst];
    }
};