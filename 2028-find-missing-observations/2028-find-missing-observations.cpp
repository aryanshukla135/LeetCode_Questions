class Solution {
public:
    vector<int> missingRolls(vector<int>& nums, int mean, int n) {
        int m = nums.size();
        int sum = 0;
        for(int i : nums){
            sum += i ;
        }
        int totalSum = (m+n) * mean ;
        int remSum = totalSum - sum ;
        if (remSum < n || remSum > 6 * n) {
            return {};
        }
        vector<int> ans(n,1);
        int x = 0;
        int val = remSum / n ;
        for(int i =0 ; i<n ; i++){
            ans[i] = val ;
            x += val;
        }
        int v = remSum - x ;
        for (int i = 0; i < n && v > 0; i++) {
            int add = min(6 - ans[i], v);
            ans[i] += add;
            v -= add;
        }

        return ans;
         
    }
};

// 10 + x = 48
// 38 = x 
