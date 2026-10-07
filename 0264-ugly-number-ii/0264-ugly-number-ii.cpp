class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> nums;

        nums.insert(1);

        int cnt = 0;

        while (!nums.empty()) {
            long long val = *nums.begin();
            nums.erase(nums.begin());

            cnt++;

            if (cnt == n)
                return val;

            nums.insert(val * 2);
            nums.insert(val * 3);
            nums.insert(val * 5);
        }

        return -1;
    }
};