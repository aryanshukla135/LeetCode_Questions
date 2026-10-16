class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            nums[i] = (nums[i] % modulo == k) ? 1 : 0;
        }
        unordered_map<int, long long> mp;
        mp[0] = 1;
        long long ans = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int mod = sum % modulo;
            int need = (mod - k + modulo) % modulo;

            if (mp.count(need)) {
                ans += mp[need];
            }
            mp[mod]++;
        }
        return ans;
    }
};