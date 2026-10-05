class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int cnt = 0;
        int prev =timeSeries[0] + duration - 1  ;
        cnt = prev - timeSeries[0] + 1;

        for(int i = 1 ; i<n ; i++){
            int l = timeSeries[i];
            int h = timeSeries[i] + duration - 1 ;
            
            if(l <= prev){
                l = prev + 1 ;
            }
           
            cnt += h- l +1;
            prev = h ;
            
        }
        return cnt ;
    }
};