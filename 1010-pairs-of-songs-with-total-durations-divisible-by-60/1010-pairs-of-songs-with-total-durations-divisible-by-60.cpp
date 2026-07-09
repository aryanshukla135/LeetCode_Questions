class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        int cnt =0 ;
        for(int i =0 ;i<n ;i++){
            time[i] %= 60 ;
        }
        unordered_map<int,int> mp ;
        for(int i =0 ; i< n ; i++){
            mp[time[i]]++;
        }
        for(int i = 0 ; i<n ; i++){
            int val = time[i];
            int req = 0;
            if(val != 0){
               req = 60 -val;
            }
            mp[val]--;
            if(mp[req]>0){
                cnt += mp[req];
            }
    
        }
        return cnt ;
    }
};
// 30 20 30 40 40 
 