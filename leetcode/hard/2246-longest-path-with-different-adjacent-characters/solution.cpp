class Solution {
private:
    int dfs(vector<vector<int>> & graph , string & s ,int child , int parent,int & maxi){
        int largest =0 ;
        int secondlargest = 0;

        for(auto it : graph[child]){
            if(it != parent){
                int cnt = dfs(graph,s,it,child,maxi);
                if(s[it] != s[child]){
                    if(cnt > largest){
                        secondlargest = largest ;
                        largest = cnt ;
                    }
                    else if(cnt > secondlargest){
                        secondlargest = cnt ;
                    }
                }
            }
        }
        maxi = max(maxi,largest + secondlargest + 1);

        return largest + 1 ;
        
    }
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> graph(n);

        for(int i = 1; i < n; i++) {
            graph[parent[i]].push_back(i);
            graph[i].push_back(parent[i]);
        }
        int maxi =0 ;
        dfs(graph,s,0,-1,maxi);
        return maxi;

    }
};