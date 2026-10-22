/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
private:
    void dfs(unordered_map<int,vector<int>> & mp , unordered_map<int,int>& val , int strt,int & ans,unordered_set<int> & st){

        ans += val[strt];
        st.insert(strt);
        for(auto it : mp[strt]){
            if(!st.count(it)){
                dfs(mp,val,it,ans,st);
            }
        }
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        int n = employees.size();
        unordered_map<int,int> val;
        unordered_map<int,vector<int>> mp ;
        for(int i =0 ; i<n ; i++){
            vector<int> temp = employees[i]->subordinates;
            for(int j =0 ; j <temp.size() ;j++){
                mp[employees[i]->id].push_back(temp[j]); 
            }
            val[employees[i]->id] = employees[i]->importance;
        }

        int ans = 0;
        unordered_set<int> st ;
        dfs(mp,val,id,ans,st);

        return ans ;
    
    }
};