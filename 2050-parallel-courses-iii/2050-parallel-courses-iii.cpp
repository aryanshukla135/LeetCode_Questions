class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n);
        vector<int> indeg(n);
        for(auto it : relations){
            indeg[it[1]-1]++;
            graph[it[0]-1].push_back(it[1]-1);
        }
        queue<int> q ;
        vector<int> maxTime(n,0);
        for(int i =0 ; i<n ; i++){
            if(indeg[i] == 0){
                q.push(i);
                maxTime[i] = time[i];
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : graph[node]){
                maxTime[it] = max(maxTime[it],maxTime[node] + time[it]);
                indeg[it]--;
                if(indeg[it] == 0){
                    q.push(it);
                }
            }
        }
        int ans = *max_element(maxTime.begin(),maxTime.end());
        return ans ;
    }
};