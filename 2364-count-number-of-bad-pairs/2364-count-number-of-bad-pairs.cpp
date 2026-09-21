class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
          int n = nums.size();
          unordered_map<int,int> mp ;
          for(int i =0 ; i<n ; i++){
            nums[i] = i - nums[i];
            mp[nums[i]]++;
          }
          long long ans =0 ;
          for(int i =0 ; i<n ; i++){
             int val = nums[i];
             mp[val]--;
             if(mp[val] > 0){
                ans += mp[val];
             }
          }
          long long totalPair = 1LL * n * (n-1)/2;
          return (totalPair - ans);
    }
};
// j - nums[j] != i-nums[i]
//n(n-1)/2