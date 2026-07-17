class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
         int n = nums.size();
         long long cnt =0 ;
         long long ans = 0;

         for(int i =0 ; i<n-1 ; i++){
            int val = nums[i];
            int val1 = nums[i+1];

            if( (val == 1 && val1 == 0 ) || (val == 0 && val1 == 1) ){
                cnt++;
            }else{
                cnt++;
                long long subarry = cnt *(cnt+1)/2; 
                cnt =0 ;
                ans += subarry ;
            }
         }
         if(cnt != 0 ){
            cnt++;
            ans += cnt * (cnt +1)/2;
         }else{
            ans++;
         }
         return ans ;
    }
};