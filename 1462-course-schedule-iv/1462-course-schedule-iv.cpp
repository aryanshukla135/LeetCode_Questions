class Solution {
private:  
    vector<int> topo(vector<vector<int>> & graph , vector<int> &indeg){
        int n = indeg.size();
        queue<int> q ;
        for(int i =0 ; i<n ; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        vector<int> res ;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);

            for(auto & it : graph[node]){
                indeg[it]--;
                if(indeg[it] == 0){
                    q.push(it);
                }
            }
        }
        return res;
    }
    bool bfs(vector<vector<int>> & graph,int strt ,int tar ){
        queue<int> q ;
        int n = graph.size();
        vector<int> vis(n);

        q.push(strt);
        vis[strt] = 1 ;

        while(!q.empty()){
            int i = q.front();
            q.pop();

            if(i == tar){
                return true;
            }

            for(auto it : graph[i]){
                if(!vis[it]){
                    vis[it] = 1 ;
                    q.push(it);
                }
            }
        }

        return false;
    }

public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
         vector<vector<int>> graph(numCourses);
         vector<int> indeg(numCourses);
         for(auto it : prerequisites){
            int u = it[0];
            int v = it[1];

            indeg[v]++;
            graph[u].push_back(v);
         }

         //vector<int> top = topo(graph,indeg);

        //  for(int i : top) cout<<i<<" "; 
         vector<bool> ans;

         for(auto it : queries){
            int u = it[0];
            int v = it[1];

            bool temp = bfs(graph,u,v);
            ans.push_back(temp);
    
         }
         return ans ;
    }
};