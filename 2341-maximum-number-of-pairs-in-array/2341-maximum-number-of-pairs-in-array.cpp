class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st ;
        int cnt =0 ;
        for(int i =0 ; i< n ; i++){
            if(!st.count(nums[i])){
                st.insert(nums[i]);
            }else{
                st.erase(nums[i]);
                cnt++;
            }
        }
        int x = st.size();
        return {cnt,x};

    }
};