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

    int findMin(vector<int> & nums ,int i , int j){
        int val = INT_MAX;
        for(int ind = i ; ind <= j ; ind++){
            val = min(val,nums[ind]);
        }
        return val;
    }
    int findMax(vector<int> & nums ,int i , int j){
        int val = INT_MIN;
        for(int ind = i ; ind <= j ; ind++){
            val = max(val,nums[ind]);
        }
        return val;
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
                if(!isRotatedSorted(nums, k, j)) {
                    valid = false;
                    break;
                }
                int currMin = findMin(nums,k,j); 
                int currMax = findMax(nums,k,j);
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