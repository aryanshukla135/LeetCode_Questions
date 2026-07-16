class Solution {
public:
    long long gcdSum(vector<int>& nums) {
         int n = nums.size();
         vector<int> mxi(n) ;
         mxi[0] = nums[0];

         for(int i = 1 ; i< n ; i++){
            mxi[i] = max(mxi[i-1],nums[i]);
         }

         for(int i =0 ; i< n ; i++){
            mxi[i] = gcd(mxi[i],nums[i]);
         }
         
         sort(mxi.begin() , mxi.end());
         long long sum =0 ;
         int i =0 ;
         int j = n-1;

         while(i<j){
            int val1 = mxi[i];
            int val2 = mxi[j];

            sum += gcd(val1,val2);
            i++;
            j--;
         }
         return sum; 

    }
};