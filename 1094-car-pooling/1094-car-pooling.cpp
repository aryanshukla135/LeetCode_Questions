class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
            return a[1] < b[1]; 
    }
    typedef pair<int,int> P;
    bool carPooling(vector<vector<int>>& trips, int capacity) {
         int n = trips.size();

         sort(trips.begin(), trips.end(),comp);
         
         priority_queue<P,vector<P>,greater<P>> pq ;
         int cnt =0 ;
         for(int i =0 ; i<n ; i++){
            int val = trips[i][0];
            int strt = trips[i][1];
            int end = trips[i][2];

            while(!pq.empty() && pq.top().first <= strt){
                 cnt -= pq.top().second;
                 pq.pop();
            }

            cnt += val ;
            if(cnt > capacity){
                return false;
            }
            pq.push({end,val});
         }

        return true ;
    }
};