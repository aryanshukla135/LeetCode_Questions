class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans =0 ;
        unordered_map<int,int> mp ;
        unordered_set<int> st;

        for(int i =0 ; i<n ; i++){
           st.insert(nums[i]);
        }
        int total = st.size();
        int i =0 ;
        int j =0 ;
        

        while(i<n){
            mp[nums[i]]++;
            while(mp.size() == total){
                ans += n-i;
                mp[nums[j]]--;
                if(mp[nums[j]] == 0){
                    mp.erase(nums[j]);
                }
                j++;
            }
            i++;
        }
        return ans ;
    }
};