class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 1 ; i<n ; i += 2){
            string s1 = to_string(nums[i-1]);
            string s2 = to_string(nums[i]);

            string str = s1 + s2 ;
            int num = stoi(str);
            ans = min(ans, num);
        }
        return ans ;
    }
};