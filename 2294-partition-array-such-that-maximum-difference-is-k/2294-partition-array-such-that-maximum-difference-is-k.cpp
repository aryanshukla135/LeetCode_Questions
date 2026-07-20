class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int cnt =1 ;
        int maxi = nums[0];
        int mini = nums[0];

        for(int i =0 ; i<n ; i++){
           maxi = nums[i];

           if(maxi - mini > k){
              cnt++;
              mini = nums[i];
           }
        }
        return cnt ;
    }
};
// 1 2 3 5 6
// 
//        