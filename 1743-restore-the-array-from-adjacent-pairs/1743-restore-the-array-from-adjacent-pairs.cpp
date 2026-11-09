class Solution {
private:
    void dfs(unordered_map<int,vector<int>> & mp , unordered_set<int> & st , int node , vector<int> & ans ){
        st.insert(node);
        ans.push_back(node);
        for(auto it : mp[node]){
            if(!st.count(it)){
                dfs(mp,st,it,ans);
            }
        }
    }
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> mp ;

        for(auto & it : adjacentPairs){
            int u = it[0];
            int v = it[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        int strt = 0 ;
        for(auto & it  : mp){
            int size = it.second.size();
            if(size == 1 ){
                strt = it.first;
            }
        }
        vector<int> ans;
        cout<<strt;
        unordered_set<int> st ;
        dfs(mp,st,strt,ans);

        return ans;
    }
};
/*
2 - 1 3 
1 - 2 
3 - 4 2 
4 - 3 


4 = -2 1 
-2 = 4 
1 = 4 -3  
-3 = 1 










*/