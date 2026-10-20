class Solution {
private:
    bool isRotatedSorted(vector<int>& nums, int i, int j) {
        int cnt = 0;

        for (int ind = i + 1; ind <= j; ind++) {
            if (nums[ind] < nums[ind - 1]) {
                cnt++;
            }
        }

        if (nums[j] > nums[i]) {
            cnt++;
        }

        return cnt <= 1;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (n % i != 0) continue;

            int j = 0;
            bool valid = true;
            int prevMax = INT_MIN;

            while (j < n) {
                int k = j;
                j = k + i - 1;

                if (!isRotatedSorted(nums, k, j)) {
                    valid = false;
                    break;
                }

                int currMin = *min_element(
                    nums.begin() + k, nums.begin() + j + 1
                );

                int currMax = *max_element(
                    nums.begin() + k, nums.begin() + j + 1
                );

                if (prevMax > currMin) {
                    valid = false;
                    break;
                }

                prevMax = currMax;
                j++;
            }

            if (valid) {
                ans += i;
            }
        }

        return ans;
    }
};