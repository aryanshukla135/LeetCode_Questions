class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n = nums.size();
        queue<pair<int,int>> q ;
        q.push({start,0});
        int ans = INT_MAX;
        vector<int> vis(1001,INT_MAX);
        vis[start] = 0 ;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int val = it.first ;
            int step = it.second ;
            if(val == goal){
                ans = min(ans,step);
            }
            if(val >= 0 && val <= 1000){
                for(int i = 0 ; i < n ; i++){
                   
                    int op1 = val + nums[i];
                    if(op1 == goal) ans = min(ans, step + 1);
                   
                    if(op1 >= 0 && op1 <= 1000 && vis[op1] > step + 1){
                        vis[op1] = step + 1;
                        q.push({op1, step + 1});
                    }

                    int op2 = val - nums[i];
                    if(op2 == goal) ans = min(ans, step + 1);
                    if(op2 >= 0 && op2 <= 1000 && vis[op2] > step + 1){
                        vis[op2] = step + 1;
                        q.push({op2, step + 1});
                    }

                    int op3 = val ^ nums[i];
                    if(op3 == goal) ans = min(ans, step + 1);
                    if(op3 >= 0 && op3 <= 1000 && vis[op3] > step + 1){
                        vis[op3] = step + 1;
                        q.push({op3, step + 1});
                    }
                }
        }
        }
       return ans == INT_MAX ? -1 : ans;
    }
};