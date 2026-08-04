class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
           int maxi = *max_element(nums.begin(),nums.end());
           int mini = *min_element(nums.begin(),nums.end());
           unordered_set<int> st ;
           
           for(int i =0 ; i< nums.size() ; i++) st.insert(nums[i]);

           vector<int> result ;
           for(int i =mini ; i<=maxi ; i++){
                   if(!st.count(i)) result.push_back(i);
           }
           return result ;
    }
};