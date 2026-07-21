class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int len = banned.size();
        unordered_map<int,int> mp ;

        for(int i =0 ; i<len ; i++){
            mp[banned[i]]++;
        }
        long long sum =0;
        int cnt =0 ;
        for(int i =1 ; i<=n ; i++){
            if(mp.count(i)){
                continue ;
            }
            sum += i ;
            if(sum>maxSum){
                break;
            }
            cnt++;
        }
        return cnt ;

    }
};