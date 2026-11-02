class Solution {
    vector<int> ans;
private:
    vector<int> dfs(vector<vector<int>> & graph , string & label,int child , int parent){
        vector<int> freq(26,0);
        for(auto it : graph[child]){
            if(it != parent){
            vector<int> temp =  dfs(graph,label,it,child);
                for(int i =0 ; i<26 ;i++){
                    freq[i] += temp[i];
                }
            }
        }
        int ch = label[child] - 'a';
        freq[ch]++;

        ans[child] = freq[ch];

        return freq;
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.assign(n,0);
        vector<vector<int>> graph(n);
        for(auto it : edges ){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        dfs(graph,labels,0,-1);
         
        return ans ;
    }
};