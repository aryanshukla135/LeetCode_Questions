class Solution {
private:
    void solve(unordered_map<string,vector<string>> & mp , unordered_map<string,int> & indeg,unordered_set<string> & st ){
        queue<string> q ;
        for(auto & it : st){
            q.push(it);
        }

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            st.insert(it);

            for(auto i : mp[it]){
                indeg[i]--;
                if(indeg[i] == 0){
                    q.push(i);
                }
            }
        }
        
    }
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>> mp ;
        int n = recipes.size();
        unordered_map<string,int> indeg;
        for(int i =0 ; i<n ; i++){
            string v = recipes[i];
            for(string s : ingredients[i]){
                mp[s].push_back(v);
                indeg[v]++;
            }
        }
        unordered_set<string> st;
        for(auto it : supplies){
            st.insert(it);
        } 
        vector<string> ans;
        solve(mp,indeg,st);

        for(auto it : recipes){
            if(st.count(it)){
                ans.push_back(it);
            }
        }

    return ans ;
    }
};