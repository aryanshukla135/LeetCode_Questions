class Solution {
private:
    void dfs(vector<vector<int>> &rooms , int n , vector<int> &vis , int node,unordered_map<int,bool>&mp){
        vis[node] = 1 ;
        mp[node] = true ;

        for(auto it : rooms[node]){
            if(!vis[it]){
                dfs(rooms,n,vis,it,mp);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n,0);
        unordered_map<int,bool> mp;
        dfs(rooms,n,vis,0,mp);

        for(int i =0 ; i< n ; i++){
            if(!mp.count(i)){
                return false;
            }
        }
        return true;
    }
};