class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
         int n = nums.size();

        // return false;
         for(int i = 0 ; i<n ; i++){
             int j = i ;
             bool pre = 0 ;
             while(j < n-1 && j-i+1 < k && nums[j] < nums[j+1]){
                j++;
             }
             if(j-i+1 == k){
                pre = 1 ;
             }
             if(pre == 1 ){
                bool temp = 1;
                int l = j+1 ;
                int y = j+1 ;
                while(l<n-1 && l-y+1 < k){
                    if(nums[l] >= nums[l+1]){
                        temp = 0;
                        break;
                    }
                    l++;
                }
                if(temp && l-y+1 == k){
                   return true;
                }
             }    
         }
         return false;
    }
};