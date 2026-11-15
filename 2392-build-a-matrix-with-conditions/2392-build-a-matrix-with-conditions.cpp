class Solution {
private:
    vector<int> top(vector<vector<int>> & graph , vector<int> & indeg){
        queue<int> q;
        vector<int> ans ;
        for(int i =1 ; i< graph.size() ;i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto & it : graph[node]){
                indeg[it]--;
                if(indeg[it] == 0){
                    q.push(it);
                }
            }
        }
        return ans ;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> adj1(k+1);
        vector<vector<int>> adj2(k+1);

        vector<int> indeg1(k+1);
        vector<int> indeg2(k+1);

        for(auto it : rowConditions){
            int u = it[0];
            int v = it[1];
            adj1[u].push_back(v);
            indeg1[v]++;
        }

        for(auto it : colConditions){
            int u = it[0];
            int v = it[1];
            adj2[u].push_back(v);
            indeg2[v]++;
        }

        vector<int> row = top(adj1,indeg1);
        vector<int> col = top(adj2,indeg2);
        //for(int i : col) cout<<i<<" ";
        
        if(row.size()!=k || col.size() !=k) return {};
        if(row.size() != col.size()) return {};

        vector<vector<int>> ans(k,vector<int>(k,0));

        unordered_map<int,int> mp ;
        for(int i =0 ; i<col.size();i++){
            mp[col[i]] = i;
        }

        for(int r =0 ; r<row.size() ; r++){
           int c = mp[row[r]];
           ans[r][c] = row[r];
        }
        return ans;
    }
};