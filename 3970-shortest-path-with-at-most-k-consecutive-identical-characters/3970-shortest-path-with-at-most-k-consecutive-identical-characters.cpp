class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            graph[u].push_back({v,w});
        }

        vector<vector<int>> dis(n,vector<int>(k+1,INT_MAX));

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
            > pq;

        pq.push({0,0,1});
        dis[0][1] = 0 ;
        while(!pq.empty()){
            auto [wt, node, cnt] = pq.top();
            pq.pop();


            if(wt > dis[node][cnt]){
                continue;
            }

            if(node == n-1){
                return wt ;
            }



            for(auto nod : graph[node]){
                int adjNode = nod.first ;
                int adjWt = nod.second ;

                int newCnt = 1 ;
                if(labels[node] == labels[adjNode]){
                    newCnt = cnt + 1 ;
                }

                if(newCnt > k){
                    continue ;
                }

                if(dis[adjNode][newCnt] > adjWt + wt){
                    dis[adjNode][newCnt] = adjWt +wt ;
                    pq.push({dis[adjNode][newCnt],adjNode,newCnt});
                }
            }
        }
        return -1;
    }
};