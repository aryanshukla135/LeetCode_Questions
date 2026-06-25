class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> graph(n) ;
    
        for(vector<int> it : prerequisites){
            int u = it[0];
            int v = it[1];

            graph[v].push_back(u);
        }
        vector<int> ans;
        vector<int> indegree(n);

        for(int i =0 ; i< n ; i++){
            for(auto it :graph[i]){
                indegree[it]++;
            }
        } 
        queue<int> q ;
        for(int i =0 ; i< n ; i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it : graph[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }

        }
        if(ans.size() == n){
            return ans ;
        }

        return {} ;
    }
};