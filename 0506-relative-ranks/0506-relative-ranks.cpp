class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
         int n = score.size();
         // {score,idx};
         priority_queue<pair<int,int>> pq ;
         for(int i =0 ; i< n ; i++){
            pq.push({score[i],i});
         }
         vector<string> ans(n) ;
         int cnt =1 ;
         while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int val = it.first ;
            int idx = it.second ;

            if(cnt<=3){
                if(cnt==1){
                    ans[idx] = "Gold Medal";
                    cnt++;
                }else if(cnt == 2){
                    ans[idx] = "Silver Medal";
                    cnt++;
                }else if(cnt = 3){
                    ans[idx] = "Bronze Medal";
                    cnt++;
                }
            }else{
                string str = to_string(cnt);
                cnt++;
                ans[idx] = str;
            }
         }
         return ans ;
    }
};