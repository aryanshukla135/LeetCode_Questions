class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int n = nums.size();
        vector<int> result ;
        unordered_map<int,int> mp ;

        for(int i =0 ; i< n ; i++){
            mp[nums[i]]++;
        }

        for(int i =0 ; i< n ; i++){
            int val = nums[i];
            if(mp[val] == 1 && !mp.count(val+1) && !mp.count(val-1)){
                result.push_back(val);
            }
        }
        return result;
    }
};