class Solution {
private:
    void solve(string & s , string & curr , set<string> & st , vector<bool> &vis){
        if(!curr.empty()){
            st.insert(curr);
        }
        for(int i = 0; i<s.length() ; i++){
            if(vis[i] == true){
                continue ;
            }
            vis[i] = true ;
            curr.push_back(s[i]);
            solve(s,curr,st,vis);
            curr.pop_back();
            vis[i] = false;
        }
    }
public:
    int numTilePossibilities(string tiles) {
        vector<bool> vis(tiles.size() , false);
        set<string> st ;
        string cur = "";

        solve(tiles,cur,st,vis);

        return st.size();

    }
};