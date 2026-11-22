class Solution {
public:
    typedef long long ll;
    long long minCost(vector<int>& nums) {
        int n = nums.size();
        
        long long ans = LLONG_MAX;

        for(int i = 1 ;i < n-1 ; i++){
            long long pre = 0 ;
            long long suf = 0 ;
            if(nums[i] != nums[i-1]){
                pre =1LL *  i * nums[i];
            }
            while(i<n-1 && nums[i] == nums[i+1]){
                i++;
            }
            if( i <n-1 && nums[i] != nums[i+1]){
                suf = 1LL * (n-i-1) * nums[i];
            }
            if(pre == 0 && suf == 0) continue ;   
            ans = min(ans, pre + suf);
        }
        if(ans ==LLONG_MAX) return 0 ;
        return ans ;
    }
};
// 3 3 3 4 4 4   
