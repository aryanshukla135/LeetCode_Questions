class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> graph(n,vector<int>(n,INT_MAX));

        for(auto it : edges){
            graph[it[0]][it[1]] = it[2];
            graph[it[1]][it[0]] = it[2];
        }
        for(int i =0 ; i<n ; i++){
            graph[i][i]=0;
        }

        for(int via = 0; via<n ;via++){
            for(int i =0 ; i<n ; i++){
                for(int j =0; j<n; j++){
                    if(graph[i][via] == INT_MAX || graph[via][j] ==INT_MAX){
                        continue;
                    }
                    graph[i][j] = min(graph[i][j] , graph[i][via]+graph[via][j]);
                }
            }
        }
        int countcity =0;
        int cityno =n;

        for(int i =0 ; i< n ; i++){
            int cnt =0;
            for(int j =0 ;j< n ; j++){
                if(graph[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=cityno){
                cityno = cnt;
                countcity = i ;
            }
        }
        return countcity;
    }
};