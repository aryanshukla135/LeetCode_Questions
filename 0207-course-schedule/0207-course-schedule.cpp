class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       int n=numCourses;
        vector<vector<int>> graph(n) ;
    
        for(vector<int> it : prerequisites){
            int u = it[0];
            int v = it[1];

            graph[u].push_back(v);
        }
        int cnt =0;
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
            cnt++;

            for(auto it : graph[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }

        }
        if(cnt == n){
            return true ;
        }

        return false ;

    }
};