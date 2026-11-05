class Solution {
private:
    void dfs(unordered_map<string,vector<pair<string,double>>> & mp , unordered_set<string> & st,string src , string des,double prod,double & ans){
        st.insert(src);
        if(src == des){
            ans = prod ;
            return ;
        }
        for(auto it : mp[src]){
            string s = it.first ;
            double val = it.second ;
            if(!st.count(s)){
                dfs(mp,st,s,des,prod * val , ans);
            }
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string,vector<pair<string,double>>> mp ;

        for(int i =0 ; i<n ; i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            mp[u].push_back({v,val});
            mp[v].push_back({u,1.0/val});
        }
 
        vector<double> res ;
        for(auto query : queries){
            string src = query[0];
            string des = query[1];
  
            if(!mp.count(src)){
                res.push_back(-1.0);
                continue;
            }
            unordered_set<string> st ;

            double prod = 1.0 ;
            double ans = -1.0 ;
            
            dfs(mp,st,src,des,prod,ans);

            res.push_back(ans);
        }
        return res;
    }
};