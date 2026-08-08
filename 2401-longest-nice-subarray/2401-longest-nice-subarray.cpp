class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
         int n = nums.size();
         int j =0 ; 
         int checker = 0 ;
         int ans =0 ;

         for(int i =0 ; i<n ; i++){
            while((checker & nums[i]) !=0){
                checker ^= nums[j];
                j++;
            }
            checker |= nums[i];
            ans = max(ans,i-j+1);

         }
         return ans ;
    }
};