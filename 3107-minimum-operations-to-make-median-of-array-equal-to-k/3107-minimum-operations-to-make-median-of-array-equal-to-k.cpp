class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
         int n = nums.size();
         sort(nums.begin(),nums.end());

         long long  mid = nums[n/2] ;
         long long idx = n/2;

         long long cnt =(abs(k-mid)) ;
         nums[idx] = k ;
         idx--;
         while(idx >=0 ){
            if(nums[idx]> k){
                cnt += abs(nums[idx] - k);
                nums[idx] = k ;
                idx--;
            }else{
                break;
            }
         }
         idx = n/2 ;
         idx++;
         while(idx <n ){
            if(nums[idx]<k){
                cnt += abs(nums[idx]-k);
                nums[idx] = k ;
                idx++;
            }else{
                break ;
            }
         }
         return cnt ;
    }
};
// 2 5 5 6 8