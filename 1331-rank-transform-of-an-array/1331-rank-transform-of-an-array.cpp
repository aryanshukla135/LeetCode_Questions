class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        vector<int> nums = arr;
        vector<int> result(n);

        if (n == 0)
            return result;

        if (n == 1) {
            result[0] = 1;
            return result;
        }

        sort(nums.begin(), nums.end());

        int cnt = 1;

        for (int i = 0; i < n - 1; i++) {
            mp[nums[i]] = cnt;

            if (nums[i] != nums[i + 1]) {
                cnt++;
            }
        }

        mp[nums[n - 1]] = cnt;

        for (int i = 0; i < n; i++) {
            result[i] = mp[arr[i]];
        }

        return result;
    }
};