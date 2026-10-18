class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int j =0 ;
        long long sum = 0;
        long long maxSum =0 ;
        for(int i =0 ;i<n ; i++){
            mp[nums[i]]++;
            sum += nums[i];
            while( mp[nums[i]] > 1){
                sum -= nums[j];
                mp[nums[j]]--;
                if(mp[nums[j]] == 0){
                    mp.erase(nums[j]);
                }
                j++;
            }
            while(i-j+1 >k){
                 sum -= nums[j];
                 mp[nums[j]]--;
                 if (mp[nums[j]] == 0) {
                    mp.erase(nums[j]);
                 }
                 j++;
            }
            if(i-j+1 == k){
                maxSum = max(maxSum , sum);
            } 
        }
        return maxSum;
    }
};