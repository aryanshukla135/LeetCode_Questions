class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int cnt =0 ;
        for(int i =0 ; i<n ; i++){
            if(nums[i]<0) cnt++;
        }
        if(cnt == n){
            return nums[n-1]*nums[n-2]*nums[n-3];
        }

        int ans = INT_MIN ;
        ans = max(ans , nums[n-1]*nums[n-2]*nums[n-3]);
        ans = max(ans,nums[0]*nums[1]*nums[2]);
        ans = max(ans,nums[0]*nums[1]*nums[n-1]);

        return ans ;
        
    }
};
// -10 -9 -1 -10 -20
// -5 -4 -1 -1 2 30