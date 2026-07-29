class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();
        int ans =0 ;
        int i = 0 ;
        int j = 0;

        unordered_map<int,int> mp ;
        while(i<n){
            mp[nums[i]]++;
            while(mp.size() > 2){
                ans = max(ans,i-j );
                mp[nums[j]]--;
                if(mp[nums[j]] == 0){
                    mp.erase(nums[j]);
                }
                j++;
            }
            i++;
        }
        ans = max(ans,i-j);
        return ans ;
    }
};