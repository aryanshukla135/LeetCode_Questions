class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> graph(n);

        for(int i = 0 ; i< edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double val = succProb[i];

            graph[u].push_back({v,val});
            graph[v].push_back({u,val});
        }
        vector<double> dist(n,INT_MIN);
        priority_queue<pair<double,int>> pq ;
        pq.push({1.0,start_node});

        dist[start_node] = 1.0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            double val = it.first ;
            int node = it.second ;

            for(auto i : graph[node]){
                int adjnode = i.first;
                double adjval = i.second;
                double value = adjval * val;
                if(value>dist[adjnode]){
                    dist[adjnode] = value;
                    pq.push({dist[adjnode],adjnode});

                }
            }
        }
        if(dist[end_node] == INT_MIN){
            return 0 ;
        }

        return dist[end_node];
    }
};