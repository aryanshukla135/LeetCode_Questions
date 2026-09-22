class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int j = 0;
        int one = 0;
        int totalOne = 0;
        int zero = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                totalOne++;
            }
        }

        if (totalOne == 0 || totalOne == n) {
            return 0;
        }

        for (int i = 0; i < n + totalOne; i++) {

            // Add current element
            if (nums[i % n] == 1) {
                one++;
            } else {
                zero++;
            }

            // Keep window size <= totalOne
            while (i - j + 1 > totalOne) {

                if (nums[j] == 1) {
                    one--;
                } else {
                    zero--;
                }

                j++;
            }

            // Window has exactly totalOne elements
            if (i - j + 1 == totalOne) {
                mini = min(mini, zero);
            }
        }

        return mini;
    }
};