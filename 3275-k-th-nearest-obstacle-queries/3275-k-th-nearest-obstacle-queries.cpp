class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
         int n = queries.size();
         priority_queue<int> pq ;
         vector<int> ans ;
         
         for(int i =0 ; i<n ; i++){
            int x = queries[i][0];
            int y = queries[i][1];

            int dis =(abs(x) + abs(y));
    
            if(pq.empty()){
                pq.push(dis);
            }
            else if(pq.size() < k){
                pq.push(dis);
            }
            else{
                if(pq.top() > dis){
                    pq.pop();
                    pq.push(dis);
                }     
            }

            if(pq.size() < k ){
                ans.push_back(-1);
            }else{
                ans.push_back(pq.top());
            }
         }
         return ans ;
    }
};