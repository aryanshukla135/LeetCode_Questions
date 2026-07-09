class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp ;
        for(int i =0 ; i< n ; i++){
            mp[arr[i]]++;
        }
        priority_queue<int> pq ;
        for(auto it : mp){
            pq.push(it.second);
        }
        int cnt = 0 ;
        int sum =0;
      
        while(!pq.empty()){
            int it = pq.top();
            pq.pop();
            sum+=it;
            cnt++;
            if(sum>=(n/2)){
                return cnt ;
            }
        }
        return -1 ;
    }
};