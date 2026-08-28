class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int n = coins.size();
        vector<int> temp ;
        sort(coins.begin(),coins.end());
        long long prev = 1;
        int cnt =0 ;
        int i =0;
            while(i<n){
            if(prev >= coins[i]){
                prev = prev+coins[i];
                i++;
            }else{
               cnt++;
               prev = (2*prev);
            }


        }

        while(prev <= target){
            cnt++;
            prev = (2*prev);
        }
        
        return cnt ;
    }
};
// 1 20
// 1 2 4 8 16 