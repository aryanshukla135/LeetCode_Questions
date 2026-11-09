class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0 ;
        unordered_map<int,vector<int>> adj ;

        for(int i = 0 ; i < routes.size(); i++){
            for(auto it : routes[i]){
                adj[it].push_back(i);
            }
        }
        queue<pair<int,int>> q ;
        vector<int> vis(501,0);
        for(auto & it : adj[source]){
            q.push({1,it});
            vis[it] = 1 ;
        }

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int busCnt = it.first ;
            int route = it.second ;
            
           for(auto stop : routes[route]){

                if(stop == target){
                    return busCnt;
                }

                for(auto nextRoute : adj[stop]){
                    if(!vis[nextRoute]){
                        vis[nextRoute] = 1;
                        q.push({busCnt + 1, nextRoute});
                    }
                }
            }
        }
        return -1;
    }
};