class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        int i = 0;
        int ans = INT_MAX;
        for( ; i<n ;i++){
            sum +=  nums[i];
            if(sum >= x){
                break;
            }
        }
        if(sum == x){
            ans = min(ans,i+1);
        }
        if(i == n){
            return -1;
        }
        if(i>0){
            sum -= nums[i];
            i--;
        }
     
        for(int j = n-1  ; j >=0 ;j--){
            sum += nums[j];

            while( i >= 0 && sum > x ){
                    sum -= nums[i];
                    i--;
            }
            if(sum == x){
                int fromi = i+1;
                int fromj = n-j ;
                int total = fromi + fromj ;
                ans = min(ans,total);
            }

        }
        if(ans == INT_MAX){
            return -1 ;
        }
        return ans ;

    }
};