
class Solution {
private:
    bool isPossible(vector<int>& nums, int k) {
        int n = nums.size();

        int cnt = 1;
        int prev = 0;

        for(int i = 1; i < n; i++) {

            if(nums[i] > nums[i-1]) {
                cnt++;
            }
            else {
                if(cnt >= 2*k || (prev >= k && cnt >= k)) {
                    return true;
                }

                prev = cnt;
                cnt = 1;
            }
        }

        if(cnt >= 2*k || (prev >= k && cnt >= k)) {
            return true;
        }

        return false;
    }

public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        int l = 1;
        int h = n/2;
        int ans = 0;

        while(l <= h) {
            int mid = l + (h-l)/2;

            if(isPossible(nums, mid)) {
                ans = mid;
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }

        return ans;
    }
};
