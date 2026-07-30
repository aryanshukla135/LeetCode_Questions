class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n<3){
            return 0 ;
        }
        int prevdiff = nums[1]-nums[0];
        int i =1 ;
        int j =0 ;
        int ans = 0;
        int cnt =0 ;
        
        while(i<n-1){
            int currdiff = nums[i+1] - nums[i];

            if(prevdiff != currdiff){
               while(i-j+1 >=3){
                  int totalelement = i-j +1 ;
                  cnt += (totalelement - 2);
                  j++;
               }
               ans += cnt;
               cnt = 0 ;
               j = i;
        
            }
            i++;
            prevdiff = nums[i] - nums[i-1]; 
        }

        while(i-j+1 >=3){
                  int totalelement = i-j +1 ;
                  cnt += (totalelement - 2);
                  j++;
               }
               ans += cnt;

        return ans ;
    }
};