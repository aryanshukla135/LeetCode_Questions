class Graph {
private:  
    int sortPath(vector<vector<int>> & edges ,int n, int strt , int end){
        vector<vector<pair<int,int>>> graph(n);

        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            graph[u].push_back({v,wt});
        }

        vector<int> dis(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq ;
        // {dis,node}
        pq.push({0,strt});
        dis[strt] = 0 ;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dist = it.first ;
            int node = it.second ;

            for(auto it : graph[node]){
                int adjNode = it.first;
                int wt = it.second; 
                if(dis[adjNode] > dist + wt){
                    dis[adjNode] = dist + wt;
                    pq.push({dis[adjNode],adjNode});
                }
            }
        }
        if(dis[end] == INT_MAX){
            return -1 ;
        }
        return dis[end];
    }
public:
    vector<vector<int>> edges;
    int n = 0 ;
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n ;
        this->edges = edges ;
    }
    
    void addEdge(vector<int> edge) {
         edges.push_back(edge);
    }
    
    int shortestPath(int node1, int node2) {
        int ans = sortPath(edges,n,node1,node2);

        return ans ;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */