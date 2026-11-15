class Solution {
private:
    typedef pair<int,int> P;
    int shortestDis(vector<vector<int>> & graph){
        int n = graph.size();
        vector<int> dis(n,INT_MAX);
        priority_queue<P,vector<P>,greater<P>> pq ;
        pq.push({0,0});
        dis[0] = 0 ;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int d = it.first;
            int node = it.second;
            
            for(auto & i : graph[node]){
                if(dis[i] > d + 1 ){
                    dis[i] = d + 1 ;
                    pq.push({dis[i],i});
                }
            }
        }
    return dis[n-1];  
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        for(int i = 0 ; i<n-1 ; i++){
            graph[i].push_back(i+1);
        }
        vector<int> ans;

        for(auto & it : queries){
            int u = it[0];
            int v = it[1];

            graph[u].push_back(v);
            int dis = shortestDis(graph);
            ans.push_back(dis);
        }
        return ans;
    }
};