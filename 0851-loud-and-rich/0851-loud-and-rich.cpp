class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
           
           int n = quiet.size();
           vector<vector<int>> graph(n);
           vector<int>indegree(n,0);
           for(auto it : richer){
              graph[it[0]].push_back(it[1]);
              indegree[it[1]]++;
           }

           vector<int> ans(n);
           for(int i =0 ; i<n ; i++){
              ans[i]=i ;
           }

           queue<int> q ;
           for(int i =0 ; i<n ; i++){
             if(indegree[i] ==0){
                q.push(i);
             }
           }
           while(!q.empty()){
             int node = q.front();
             q.pop();
             for(int i : graph[node]){
                if(quiet[ans[node]]<quiet[ans[i]]){
                    ans[i] = ans[node]; 
                }
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
             }
           }
           return ans ;

    }
};