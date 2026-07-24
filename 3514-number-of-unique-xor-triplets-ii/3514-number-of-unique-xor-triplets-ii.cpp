class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr ;
        unordered_set<int> st1 ;
        for(int i =0 ; i<n ; i++){
            for(int j =i ; j<n ; j++){
                 st1.insert(nums[i]^nums[j]);
            }
        }

         for(auto & it : st1){
            arr.push_back(it);
         }

        unordered_set<int> st ;
        for(int i =0 ; i<arr.size() ; i++){
            for(int j = 0 ; j<n ; j++){
                st.insert(arr[i]^nums[j]);
            }
        }
        return st.size();
    }
};