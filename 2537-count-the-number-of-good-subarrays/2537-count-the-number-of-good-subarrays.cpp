class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp ;
        int j =0 ;
        long long ans =0 ;
        long long pair = 0 ;
        for(int i =0 ; i<n ; i++){
            int val = nums[i];
            pair += mp[val];
            mp[val]++;

            while(pair >= k){
                ans += (n - i );
                mp[nums[j]]--;
                pair -= mp[nums[j]];
                j++;
            }
        }
        return ans ;
    }
};