class Solution {
private:
    long long  solve(vector<vector<int>> & graph ,int i , int par , vector<int> & values,int & ans,int k){
       long long sum =0 ;

        for(auto & it : graph[i]){
            if(it != par){
                sum += solve(graph,it,i,values,ans,k);
            }
        }
        sum += values[i];
        if(sum % k == 0){
           ans++;
           return 0 ;
        }else{
            return sum ; 
        }
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
         vector<vector<int>> graph(n);

         for(auto & it : edges){
            int u = it[0];
            int v = it[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
         }

         int ans = 0 ;

         int sum =  solve(graph,0,-1,values,ans,k);
         cout<<sum ;

         return ans ;

    }
};