class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr;
        for(int i = 0; i < n; i++) {
            arr.push_back(llabs((long long)nums[i]));
        }
        sort(arr.begin(), arr.end());
        long long maxprod = arr[n-1] * arr[n-2];
        long long mul = 100000LL;
        return maxprod * mul;
    }
};