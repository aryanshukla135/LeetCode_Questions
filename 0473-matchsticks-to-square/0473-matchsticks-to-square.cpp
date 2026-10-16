class Solution {
private:
    bool solve(vector<int>& nums, int i, vector<int>& sides, int target) {
        if (i == nums.size()) {
            return true;
        }

        for (int j = 0; j < 4; j++) {
            if (sides[j] + nums[i] > target) {
                continue;
            }
            sides[j] += nums[i];
            if (solve(nums, i + 1, sides, target)) {
                return true;
            }
            sides[j] -= nums[i];
            if (sides[j] == 0) {
                break;
            }
        }
        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);

        if (matchsticks.size() < 4 || sum % 4 != 0) {
            return false;
        }

        int target = sum / 4;

        sort(matchsticks.rbegin(), matchsticks.rend());

        if (matchsticks[0] > target) {
            return false;
        }

        vector<int> sides(4, 0);

        return solve(matchsticks, 0, sides, target);
    }
};