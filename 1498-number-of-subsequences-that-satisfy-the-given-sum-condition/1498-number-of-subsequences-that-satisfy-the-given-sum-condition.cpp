class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        const int MOD = 1e9 + 7;

        vector<long long> pow(n,1);
        for (int i = 1; i < n; i++) {
            pow[i] = (pow[i - 1] * 2) % MOD;
        }

         int left = 0, right = n - 1;
        long long ans = 0;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                ans = (ans + pow[right - left]) % MOD;
                left++;
            } else {
                right--;
            }
        }

        return (int)ans;
    }
};