class Solution {
private:
    int f(int n) {
        int s = 0;
        while (n > 0) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<tuple<int, int, int>> arr;

        for (int i = 0; i < n; i++) {
            int sum = f(nums[i]);
            arr.push_back({sum, nums[i], i});
        }

        sort(arr.begin(), arr.end());

        vector<bool> vis(n, false);
        int totalSwap = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || get<2>(arr[i]) == i) {
                continue;
            }

            int cycleSize = 0;
            int j = i;

            while (!vis[j]) {
                vis[j] = true;
                j = get<2>(arr[j]);
                cycleSize++;
            }

            if (cycleSize > 1) {
                totalSwap += cycleSize - 1;
            }
        }

        return totalSwap;
    }
};