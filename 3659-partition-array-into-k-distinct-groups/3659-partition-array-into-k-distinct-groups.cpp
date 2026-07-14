class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n || n % k != 0){
            return false ;
        }

        int part = n / k ;

        unordered_map<int,int> mp ;
        for(int i =0 ; i<n ;i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > part){
                return false;
            }
        }

        // for(int i =0 ; i<n ; i++){
        //     if(mp[nums[i]] > part){
        //         return false ;
        //     }
        // }

        return true;
    }
};
// 1 2 3 5 4 4  , k = 3